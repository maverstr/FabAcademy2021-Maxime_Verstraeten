#include <Wire.h>
int address = 0x3B;
void setup()
{
  Display_init();
//  Write_text();
}


void loop()
{
  lcdClear();
  lcdGoTo(0,0);
  lcdPrint("a b c d e f");  
  delay(500);
}

void Display_init(void)
{
  Wire.begin();
  Wire.beginTransmission(address);
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
  Wire.beginTransmission(address);
  Wire.write(0x00); // Control byte for Instruction
  Wire.write(0x80 | (y * 0x40 + x)); // DDRAM Address set to 00hex
  Wire.endTransmission();
}

void lcdClear() {
  lcdGoTo(0,0);
  lcdPrint("                ");
  lcdGoTo(0,1);
  lcdPrint("                ");
}

void lcdPrint(String s) {
  Wire.beginTransmission(address);
  Wire.write(0x40); // Control byte for Data
  for (int i = 0; i < s.length(); i++)
  {
    Wire.write(s[i]|0x80); // Write ABCDE....
  }
  Wire.endTransmission();
}

//void Write_text(void)
//{
//  int i;
//  Wire.beginTransmission(address);
//  Wire.write(0x00); // Control byte for Instruction
//  Wire.write(0x80); // DDRAM Address set to 00hex
//  Wire.endTransmission();
//
//  Wire.beginTransmission(address);
//  Wire.write(0x40); // Control byte for Data
//  for (i = 1; i <= 16; i++)
//  {
//    Wire.write(0xC0 + i); // Write ABCDE....
//  }
//  Wire.endTransmission();
//  Wire.beginTransmission(address);
//  Wire.write(0x00); // Control byte for Instruction
//  Wire.write(0xc0); // DDRAM Address set to 10hex
//  Wire.endTransmission();
//
//  Wire.beginTransmission(address);
//  Wire.write(0x40); // Control byte for Data
//  for (i = 1; i <= 16; i++)
//  {
//    Wire.write(0xe0 + i); // Write abcde....
//  }
//  Wire.endTransmission();
//}
