#include <Wire.h>
#include "MS5837.h"
MS5837 sensor0;
MS5837 sensor1;

const int ledPin = 23; //board LED

float p1 = 0, p2 = 0; //pressure
bool motor1State = 0, motor2State = 0; //motors on off

//push buttons
const int button1 = 12, button2 = 27, button3 = 26;
void IRAM_ATTR setB1Flag(); //loaded in quick ram
void IRAM_ATTR setB2Flag(); //loaded in quick ram
void IRAM_ATTR setB3Flag(); //loaded in quick ram
bool flagB1 = false, flagB2 = false, flagB3 = false;
#define debounceTime 75

//lcd
int lcdAddress = 0x3B;
const int refreshTime = 700;
int lastRefreshTime = 0;
bool forcedRefresh = false;

//motors
int directionMot1 = 4;
int directionMot2 = 17;
int speedMot1 = 16;
int speedMot2 = 5;
const int PWMFreq = 5000;
const int PWMch0 = 0;
const int PWMch1 = 1;
const int resolution = 8;
int  PWM1 = 0;
int  PWM2 = 0;
//strain gauge
const int strainPin = 32;
int strainVal = 0;

void setup()
{
  Wire.begin(21, 22, 5000); //i2c
  Serial.begin(115200);

  pinMode(strainPin, INPUT);

  pinMode(directionMot1, OUTPUT);
  pinMode(directionMot2, OUTPUT);
  pinMode(speedMot1, OUTPUT);
  pinMode(speedMot2, OUTPUT);
  ledcSetup(PWMch0, PWMFreq, resolution);
  ledcSetup(PWMch1, PWMFreq, resolution);
  ledcAttachPin(speedMot1, PWMch0);
  ledcAttachPin(speedMot2, PWMch1);
  digitalWrite(directionMot1, HIGH);
  digitalWrite(directionMot2, HIGH);

  pinMode(ledPin, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1), setB1Flag, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2), setB2Flag, FALLING);
  attachInterrupt(digitalPinToInterrupt(button3), setB3Flag, FALLING);

  selectI2CChannel(0);
  scanI2c();
  delay(1);

  selectI2CChannel(1);
  scanI2c();
  delay(1);

  selectI2CChannel(0);
  if (!sensor0.init()) {
    Serial.println("Init 0 failed!");
  }
  Serial.println("Init 0 success!");

  selectI2CChannel(1);
  if (!sensor1.init()) {
    Serial.println("Init 1 failed!");
    delay(100);
  }
  Serial.println("Init 1 success!");

  sensor0.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
  sensor1.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)

  Display_init();
}

void loop()
{
  //polling pressure values
  selectI2CChannel(0);
  p2 = mbarToPsi(sensorRead(sensor0, 0));
  selectI2CChannel(1);
  p1 = mbarToPsi(sensorRead(sensor1, 1));

  if (millis() > refreshTime + lastRefreshTime || forcedRefresh) {
    lcdRefresh(); //updates pressure values and motors
  }
  if (motor1State) {
    PWM1 = 255;
  }
  else {
    PWM1 = 0;
  }

  if (motor2State) {
    PWM2 = 255;
  }
  else {
    PWM2 = 0;
  }
  ledcWrite(PWMch0, PWM1);
  ledcWrite(PWMch1, PWM2);

  strainVal = analogRead(strainPin);
  Serial.print("strain:");
  Serial.print(strainVal);
  Serial.print(" ");
  Serial.print("pressure1:");
  Serial.print(p1);
  Serial.print(" ");
  Serial.print("pressure2:");
  Serial.println(p2);

  if (flagB1) {
    button1Handler();
  }
  if (flagB2) {
    button2Handler();
  }
  if (flagB3) {
    button3Handler();
  }
}

void Display_init(void)
{
  Wire.beginTransmission(lcdAddress);
  Wire.write(0x00); // Control byte for Instruction
  Wire.write(0x34); // DL: 8 bits, M: 16 by two line display, SL: 1:18, H: normal instruction set
  Wire.write(0x0C); // D: Display on, C: curser off, B: blink off
  Wire.write(0x06); // I/D: increment, S: no shift
  Wire.write(0x35); // DL: 8 bits, M: 16 by two line, SL: 1:18, H: extended instruction set
  Wire.write(0x04); // P: left to right, Q: top to bottom
  Wire.write(0x10); // TC1: 0, TC2: 0
  Wire.write(0x42); // HV Stages 3
  Wire.write(0x9f); // set Vlcd, store to VA
  Wire.write(0x34); // DL: 8 bits, M: two line, SL: 1:18, H: normal instruction set
  Wire.write(0x80); // DDRAM Address set to 00hex
  Wire.write(0x02); // return home
  Wire.endTransmission();
  delay(1000);
}

void lcdGoTo(int x, int y) {
  Wire.beginTransmission(lcdAddress);
  Wire.write(0x00); // Control byte for Instruction
  Wire.write(0x80 | (y * 0x40 + x)); // DDRAM Address set to 00hex
  Wire.endTransmission();
}

void lcdClear() {
  lcdGoTo(0, 0);
  lcdPrint("                ");
  lcdGoTo(0, 1);
  lcdPrint("                ");
}

void lcdPrint(String s) {
  Wire.beginTransmission(lcdAddress);
  Wire.write(0x40); // Control byte for Data
  for (int i = 0; i < s.length(); i++)
  {
    Wire.write(s[i] | 0x80); // Write ABCDE....
  }
  Wire.endTransmission();
}


void scanI2c() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknow error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
  delay(50);
}

void selectI2CChannel(int chNr) {
  Wire.beginTransmission(0x71);
  Wire.write((0x01 << chNr)); //select channel
  int error = Wire.endTransmission();
  if (error == 0) {
//    Serial.println("channel " + String(chNr) + " selected");
  }
}


float sensorRead(MS5837 sensor, int chNr) {
  sensor.read();
  float pressure = 0, temperature = 0;
//  Serial.print("Pressure " + String(chNr) + " : ");
  pressure = sensor.pressure();
//  Serial.print(pressure);
//  Serial.println(" mbar");
//
//  Serial.print("Temperature " + String(chNr) + " : ");
  temperature = sensor.temperature();
//  Serial.print(temperature);
//  Serial.println(" deg C \n\n\n");
  return pressure;
}

float mbarToPsi(float p) {
  return p * 0.0145038;
}

bool motorToggle(bool current) {
  return !current;
}

String printMotorState(bool state) {
  if (state) {
    return "on";
  }
  else {
    return "off";
  }
}

void lcdRefresh() {
  digitalWrite(ledPin, !digitalRead(ledPin));
  lcdClear();
  lcdGoTo(0, 0);
  lcdPrint("p1=" + String(p1));
  lcdGoTo(0, 1);
  lcdPrint("p2=" + String(p2));

  lcdGoTo(10, 0);
  lcdPrint("M1:" + printMotorState(motor1State));
  lcdGoTo(10, 1);
  lcdPrint("M2:" + printMotorState(motor2State));
  lastRefreshTime = millis();
  forcedRefresh = false;
}

void IRAM_ATTR setB1Flag() {
  flagB1 = true;
}

void IRAM_ATTR setB2Flag() {
  flagB2 = true;
}

void IRAM_ATTR setB3Flag() {
  flagB3 = true;
}

void button1Handler() {
  static int lastButtonPressEvent = 0;
  if (millis() - lastButtonPressEvent > debounceTime and !digitalRead(button1)) {
    Serial.println("1 pressed");
    motor1State = motorToggle(motor1State);
    lastButtonPressEvent = millis();
    forcedRefresh = true;
  }
  flagB1 = false;

}

void button2Handler() {
  static int lastButtonPressEvent = 0;
  if (millis() - lastButtonPressEvent > debounceTime and !digitalRead(button2)) {
    Serial.println("2 pressed");
    motor2State = motorToggle(motor2State);
    forcedRefresh = true;
  }
  flagB2 = false;
}

void button3Handler() {
  static int lastButtonPressEvent = 0;
  if (millis() - lastButtonPressEvent > debounceTime and !digitalRead(button3)) {
    Serial.println("3 pressed");
    forcedRefresh = true;
  }
  flagB3 = false;
}
