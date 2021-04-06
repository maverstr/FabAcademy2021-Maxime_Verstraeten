int controlPin = A0;
int directionPin = A1;
int photoTop = A6;
int photoBottom = A7;

float lightTop = 0.0;
float lightBottom = 0.0;
float threshold = 25;
void setup() {
  analogReadResolution(10);
  Serial.begin(9600);
  pinMode(controlPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(photoTop, INPUT);
  pinMode(photoBottom, INPUT);
  digitalWrite(controlPin, HIGH);
  digitalWrite(directionPin, HIGH);
}

void loop() {
//  digitalWrite(directionPin, LOW);
//  digitalWrite(controlPin, LOW);
//  delay(1000);
//  digitalWrite(controlPin, HIGH);
//  delay(1000);
//
//  digitalWrite(directionPin, HIGH);
//  digitalWrite(controlPin, LOW);
//  delay(1000);
//  digitalWrite(controlPin, HIGH);
//  delay(1000);

  lightTop = analogRead(photoTop);
  lightBottom = analogRead(photoBottom);
  Serial.print(lightTop);
  Serial.print(" ");
  Serial.println(lightBottom);

  if(lightTop > threshold && lightBottom > threshold){ //if both phototransistors are under light
    moveDirection(HIGH); //move from bottom to top
  }

  if(lightTop < threshold && lightBottom < threshold){ //if both phototransistors are in the shadow
    moveDirection(LOW); //move from bottom to top
  }
  else{
    digitalWrite(controlPin, HIGH); //Deactivate motor as one is in the shadow
  }
  
}

bool moveDirection(bool direction){
  digitalWrite(directionPin, direction); //sets direction
  digitalWrite(controlPin, LOW); //turns on the motor
}
