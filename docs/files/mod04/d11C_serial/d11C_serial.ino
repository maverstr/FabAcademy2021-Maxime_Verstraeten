void setup() {
   SerialUSB.begin(0);
   Serial2.begin(115200, SERIAL_8E2);
}

void loop() {
   if (SerialUSB.available()) {
      Serial2.write((char) SerialUSB.read());
   }
   if (Serial2.available()) {
      SerialUSB.write((char) Serial2.read());
   }
}
