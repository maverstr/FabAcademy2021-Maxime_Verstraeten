const byte pattern[16] = {
  //abcdefg
  0b1111110, // ZERO
  0b0110000, // ONE
  0b1101101, // TWO
  0b1111001, // THREE
  0b0110011, // FOUR
  0b1011011, // FIVE
  0b1011111, // SIX
  0b1110000, // SEVEN
  0b1111111, // EIGHT
  0b1111011, // NINE
  0b1110111, // A
  0b0011111, // B
  0b1001110, // C
  0b0111101, // D
  0b1001111, // E
  0b1000111, // F
};

int const pin[] ={ // from g to a (reverse order, MSB on the left) then DP
  27,26,25,33,32,5,18,19};
  
int no_pins = 8;
int value = 0;

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  for(int i = 0; i < no_pins;i++)
  {
    pinMode(pin[i],OUTPUT); //init pin mode
  }
}

void loop() {
  display(value);
  value++;
  value = value%0x10;
  delay(250);
  digitalWrite(pin[7], !digitalRead(pin[7]));
  delay(250);
  digitalWrite(pin[7], !digitalRead(pin[7]));
}

void display(const int value){
  Serial.println(value);
  for(int i=0; i<=8; i++){ //reads bits of value and write it to corresponding pin
    digitalWrite(pin[i],pattern[value]&(1<<i));
    Serial.print((pattern[value]&(1<<i)?1:0));
  }
  Serial.println("");
}
