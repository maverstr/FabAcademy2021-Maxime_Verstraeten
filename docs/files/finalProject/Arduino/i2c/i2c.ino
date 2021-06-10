#include <Wire.h>
#include "MS5837.h"

MS5837 sensor0;
MS5837 sensor1;

void setup() {
  Wire.begin(21, 22, 5000);
  Serial.begin(115200);

  selectI2CChannel(0);
  scanI2c();
  delay(100);

  selectI2CChannel(1);
  scanI2c();
  delay(100);

  selectI2CChannel(0);
  while (!sensor0.init()) {
    Serial.println("Init 0 failed!");
    delay(5000);
  }
  Serial.println("Init 0 success!");

  selectI2CChannel(1);
  while (!sensor1.init()) {
    Serial.println("Init 1 failed!");
    delay(100);
  }
  Serial.println("Init 1 success!");
  sensor0.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
  sensor1.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
}

void loop() {
  selectI2CChannel(0);
  sensorRead(sensor0, 0);
  selectI2CChannel(1);
  sensorRead(sensor1, 1);
  delay(5);
}

void sensorRead(MS5837 sensor, int chNr) {
  sensor.read();

  Serial.print("Pressure " + String(chNr) + " : ");
  Serial.print(sensor.pressure());
  Serial.println(" mbar");

  Serial.print("Temperature " + String(chNr) + " : ");
  Serial.print(sensor.temperature());
  Serial.println(" deg C \n\n\n");
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
  delay(500);
}

void selectI2CChannel(int chNr) {
  Wire.beginTransmission(0x71);
  Wire.write((0x01 << chNr)); //select channel
  int error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("channel " + String(chNr) + " selected");
  }
}
