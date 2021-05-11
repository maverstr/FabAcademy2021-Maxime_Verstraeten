#define MASTER //uncomment if programming master, comment for slave

#define startFrame 0x02 // STX :start of frame
#define endFrame 0x03 // ETX : end of frame
#define DLY 100
#define slave1Address 'b'
#define slave2Address 'c'
#define masterAddress 'a'

#if defined (MASTER)
  #define myAddress masterAddress
#else
  //#define myAddress slave1Address
  #define myAddress slave2Address
#endif

// init LED pins
int const led1 = 9;
int const led2= 14;
int const led3 = 15;

void setup() {
  SerialUSB.begin(19200, SERIAL_8N1); //USB serial prints
  pinMode(5, INPUT); // RX
  pinMode(4, OUTPUT); // TX
  Serial2.begin(19200,SERIAL_8N1); // UART 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial1.end(); //Try to stop serial 1 (RX1, TX1) from communicating
  while(Serial2.available()){ //flush UART buffer
    Serial2.read();
  }
  SerialUSB.println("done setup");
}

#if defined(MASTER)

void loop() { //MASTER loop: write input data or pre-selected data to UART to slave1
  #if 1
  if(SerialUSB.available()){
    String input = "";
    byte slaveAddress = (byte)SerialUSB.read();
//    SerialUSB.print("slaveAddress :");
//    SerialUSB.println(slaveAddress);
    while(SerialUSB.available()){
      input+=(char)SerialUSB.read();
    }
//    SerialUSB.println(input);
    delay(DLY);
    sendMessage(slaveAddress, input);
  }
  #else
//  SerialUSB.println("start");
  sendMessage(slave1Address, "11");
  delay(DLY);
  sendMessage(slave1Address, "21");
  delay(DLY);
  sendMessage(slave1Address, "31");
  delay(DLY);
  sendMessage(slave1Address, "10");
  delay(DLY);
  sendMessage(slave1Address, "20");
  delay(DLY);
  sendMessage(slave1Address, "30");
  delay(DLY);

//  SerialUSB.println("start2");
  sendMessage(slave2Address, "11");
  delay(DLY);
  sendMessage(slave2Address, "21");
  delay(DLY);
  sendMessage(slave2Address, "31");
  delay(DLY);
  sendMessage(slave2Address, "10");
  delay(DLY);
  sendMessage(slave2Address, "20");
  delay(DLY);
  sendMessage(slave2Address, "30");
  delay(DLY);
  #endif
}

#else
void loop() { //Slave loop: awaits data
  readMessage();
}

#endif

void sendMessage(byte address, String msg){ //adds start and end of frames
  SerialUSB.print("sent message : ");
  SerialUSB.print(address);
  SerialUSB.print(" ");
  SerialUSB.println(msg);//+ (char)address + msg);
  SerialUSB.flush();
  while(Serial2.available()){ //flush receive buffer
        Serial2.read();  
      }
  Serial2.write(startFrame); //Add SOF
  Serial2.write(address); // write slave adress
  Serial2.print(msg); //write command and params
  Serial2.write(endFrame); // add EOF
  Serial2.flush(); //awaits for all outgoing data to be sent
  readMessage(); //reads back the info to make sure it is correct
}

void readMessage(){
  String receivedMsg = "";
  bool done = false;
  char c;
  byte d;
  int counter = 0;
  if(Serial2.available()){
    SerialUSB.println("reading message..."); 
    if( (d = (byte)Serial2.read()) == startFrame){ //checks SOF
      SerialUSB.println("start frame detected");
      counter = 0;
      while((!done) && (counter < 100)){ //gather all data
        if(Serial2.available()){
          c = (char)Serial2.read();
          if(c == endFrame){ // until EOF
            done = true;
          }
          else{
            receivedMsg += c;    
          }
        }
        counter++;
      }
      SerialUSB.println("received message : " + receivedMsg);
      if(receivedMsg[0] == myAddress){ //check address
        char cmd = receivedMsg[1];
        char param = receivedMsg[2];
        processMessage(cmd,param); //if for "me", process it
      }
    }
    else{
    SerialUSB.println("invalid message");
    SerialUSB.println(d); //wrong SOF
      while(Serial2.available()){
        SerialUSB.print((char)Serial2.read());  
      }
    }      
  }
}

void processMessage(char cmd, char param){//decomposes message in command and params
  //SerialUSB.println("processing message : " + String(cmd) + " " + String(param));
  int led;
  switch (cmd){ //selects led accoridng to cmd
    case '1': led=led1; break;
    case '2': led=led2; break;
    case '3': led=led3; break;
    default: led=0; break;
  }
  if(led!=0){ //switch on or off the led
    int state;
    if(param == '1'){
      state = HIGH;
    }
    else{
      state = LOW;
    }
    digitalWrite(led, state);
  }
}
