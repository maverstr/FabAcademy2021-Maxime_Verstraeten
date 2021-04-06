#include <Wire.h>
#include <AccelStepper.h>
#include "fabstep_i2c.h"

uint8_t addr = ADDR_UNKNOWN;

// Define some steppers and the pins the will use
AccelStepper stepper(AccelStepper::FULL4WIRE, PIN_1A, PIN_1B, PIN_2A, PIN_2B);

char msg[MAX_MSG_LENGTH];
int msg_i = 0;

char msg_content[MAX_MSG_LENGTH];


void setup() {
  pinMode(PIN_PULL, OUTPUT);
  digitalWrite(PIN_PULL, HIGH);

  pinMode(PIN_PREV, INPUT_PULLUP);
  pinMode(PIN_NEXT, INPUT_PULLUP);

  pinMode(PIN_LED, OUTPUT);

  // detect address
  bool has_prev = digitalRead(PIN_PREV) == LOW;
  bool has_next = digitalRead(PIN_NEXT) == LOW;

  // simplified addressing logic for only 2 nodes
  has_prev = true;
  if (!has_prev) {
    addr = 0;
    Wire.begin();
    Wire.setClock(I2C_FREQ);
  } else {
    addr = 1;
    Wire.begin(I2C_ADDR_OFFSET+addr, true);
    Wire.onReceive(processI2C);
  }

  // A4950 current reference
  // R = 0.05, LEVEL = 1023 * (10 * R * I / 3.3V)
  analogWriteResolution(10);
  pinMode(PIN_VREF, OUTPUT);
  analogWrite(PIN_VREF, VREF_LEVEL);

  stepper.setMaxSpeed(MAX_SPEED);
  //stepper.setSpeed(MAX_SPEED);
  stepper.setAcceleration(1000.0);

  // USB CDC (so baudrate doesn't matter)
  SerialUSB.begin(115200);

  SerialUSB.println(has_prev);
  SerialUSB.println(has_next);

  delay(100);
  stepper.enableOutputs();
}


void turn() {
  long pos = stepper.currentPosition();
  stepper.moveTo(pos+300);
}


void processI2C(int numBytes) {
  int i = 0;
  while (Wire.available() > 0) {
    char c = Wire.read();
    if (c == '\n' || msg_i == MAX_MSG_LENGTH-1) {
      msg_content[i] = '\n';
      msg_content[i+1] = '\0';
      break;
    } else {
      msg_content[i] = c;
      i++;
    }
  }
  processMessage();
}


void processMessage() {
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  int msg_port;
  char msg_value[MAX_VAL_LENGTH];

  int value_int;
  double value_float;

  if (sscanf(msg_content, "%d=%s\n", &msg_port, &msg_value) == 2) {
    switch(msg_port) {
      case 0:
        value_int = atoi(msg_value);
        value_int = constrain(value_int, MIN_POS, MAX_POS);
        stepper.moveTo(value_int);
        break;
      case 1:
        value_float = atof(msg_value);
        //value_float = max(value_float, 0);
        //value_float = min(value_float, MAX_SPEED);
        stepper.setMaxSpeed(value_float);
        break;
      default:
        break;
    }
  }
}


void processSerial() {
  int msg_addr;

  if (sscanf(msg, "%d:%s", &msg_addr, &msg_content) == 2) {
    if (msg_addr == addr) {
      processMessage();
      SerialUSB.println("OK");
    } else {
      Wire.beginTransmission(I2C_ADDR_OFFSET+msg_addr);
      Wire.write(msg_content);
      int result = Wire.endTransmission();
      if (result == 0) {
        SerialUSB.println("ACK");
      } else {
        SerialUSB.println("NACK");
      }
    }
  }
}


void loop() {
  while (SerialUSB.available()) {
    char c = SerialUSB.read();
    if (c == '\n' || msg_i == MAX_MSG_LENGTH-1) {
      msg[msg_i] = '\n';
      msg[msg_i+1] = '\0';
      msg_i = 0;
      processSerial();
    } else {
      msg[msg_i] = c;
      msg_i++;
    }
  }
  stepper.run();
}
