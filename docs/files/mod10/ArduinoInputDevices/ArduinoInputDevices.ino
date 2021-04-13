#include <analogWrite.h>
const int LEDpin = 23;
const int GPIO0 = 0;
const int in1 = 25; //34
const int in2 = 26; //35
const int in3 = 27;
const int in4 = 33;

int val = 0;
void setup() {
  pinMode(LEDpin,OUTPUT);
  pinMode(GPIO0,INPUT_PULLUP);
  pinMode(in1, INPUT_PULLUP);
  pinMode(in2, INPUT_PULLUP);
  pinMode(in3, INPUT_PULLUP);
  pinMode(in4, INPUT_PULLUP);
  Serial.begin(115200, SERIAL_8N1);
}

void loop() {
//  digitalWrite(LEDpin, HIGH);
//  delay(100);
//  digitalWrite(LEDpin, LOW);
//  delay(100);
//  val = hallRead();
//  Serial.print("high : ");
//  Serial.print("  ");
//  Serial.print(400);
//  Serial.print("low  : ");
//  Serial.print("  ");
//  Serial.print(0);
//  Serial.print("value : ");
//  Serial.print("  ");
//  Serial.println(val*10); 
//  analogWrite(LEDpin, val*1);
// digitalWrite(in3, HIGH);
//  Serial.print("photo1 : ");
//  Serial.print("  ");
//  Serial.print(analogRead(in1));
//  Serial.print("photo2 : ");
//  Serial.print("  ");
//  Serial.println(analogRead(in2));
//  analogWrite(LEDpin, analogRead(in1)*5);
//  Serial.println(analogRead(in3));
//  analogWrite(LEDpin, analogRead(in3));

  Serial.println(analogRead(in1));
}
