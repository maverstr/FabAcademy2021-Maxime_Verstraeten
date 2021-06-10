int led = 23;
int directionMot1 = 4;
int directionMot2 = 17;
int speedMot1 = 16;
int speedMot2 = 5;

const int PWMFreq = 5000;
const int PWMch1 = 0;
const int PWMch2 = 1;
const int resolution = 8;
int  PWM=20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(directionMot1, OUTPUT);
  pinMode(directionMot2, OUTPUT);
  pinMode(speedMot1, OUTPUT);
  pinMode(speedMot2, OUTPUT);

  ledcSetup(PWMch1, PWMFreq, resolution);
  ledcSetup(PWMch2, PWMFreq, resolution);
  ledcAttachPin(speedMot1, PWMch1);
  ledcAttachPin(speedMot2, PWMch2);


  digitalWrite(directionMot1, LOW);
  digitalWrite(directionMot2, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("a");
  digitalWrite(led, HIGH);
//  digitalWrite(directionMot1, HIGH);
//  digitalWrite(directionMot2, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
//  digitalWrite(directionMot1, LOW);
//  digitalWrite(directionMot2, LOW);
  delay(2000);


  ledcWrite(PWMch1, PWM);
  ledcWrite(PWMch2, PWM);

  PWM+=10;
  PWM = PWM % 255;

  
}
