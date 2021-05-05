# 13. Networking and Communications

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group Assignment: Send a message between two projects. </li>
    <li> Design, build, and connect wired or wireless node(s) with network or bus addresses</li>
  </ul>
</div>
<div class="dottedLine"></div>

## Group assignment
During [Electronics production week, Jason and I already connected two of our own boards and communicated between them using UART](./../module04/#usb-updi-converter).

<figure> <center>
  <img src="./../../img/mod04/UART1.jpg" alt="logo text" width="80%" />
  <figcaption>Our boards connected</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod04/UART2.png" alt="logo text" width="80%" />
  <figcaption>Communication using UART and messages displayed through the Serial USB monitor in Arduino</figcaption>
</figure>

## Making a network board
For my network, I wanted to make a board that is able to communicate using a single master on the bus, and a lot of slaves. I want all the communication to happen in "human-readable format", meaning using ASCII characters mainly. Also, for simplicity purpose, I intend to use an asynchronous communication protocol and a single data wire.
Obviously, I will need addresses to choose  which slave I communicate to, and I will have framing data (start of frame and end of frame).

I chose to use ATSAMD11C as the main microcontroller. The nodes can be anything, but in order to only make a single board, they will be SAMD11C as well, but it could work with almost any controller like an ATTiny for example.

The idea is to use the UART protocol (RX and TX pins), but to make it a full network bus, I'll share the RX between all the nodes, and the TXs will be connected with the RXs through a diode at each node, in order for them to be able to pull the signal low when they want to send a message.
I end up with a single wire: RX between all the nodes (and a shared GND obviously). Note that each board can be powered separately but they can also share the power line.

The good news is also that, as indicated in the datasheet of the SAMD11C, the UART protocol is already completely implemented, features start and stop bit, parity bit and the idle state is high. So, by default, TX will not make the diode conducting, which is exactly what we want.

<figure> <center>
  <img src="./../../img/mod13/SAMDUART.jpg" alt="logo text" width="80%" />
  <figcaption>From SAMD11 datasheet</figcaption>
</figure>


### The design
The deign itself is relatively straightforward, here are the main components:

- An ATSAMD11C
- A 3.3V regulator
- A USB copper connector
- A pull-up resistor on RX (for the master only)
- A diode between RX and TX (cathode on TX)
- A few LEDs and current limiting resistors connected to GPIOs so that I a have a visual feedback of the communication
- A 4x connector for programmation through SWD
- Connectors for RX, TX, 3.3V, 5V, GND.

The Altium schematic is shown below and is available in the design files.
<figure> <center>
  <img src="./../../img/mod13/schematic.jpg" alt="logo text" width="80%" />
  <figcaption>Network board schematic</figcaption>
</figure>

I connected everything in Altium, added a ground plane and my board is basically ready. In practice, there is no connection between two ground planes so I'll have a add small wire to link them as it would be very space-inefficient to try to connect them with traces or to use a jumper.

<figure> <center>
  <img src="./../../img/mod13/pcb.jpg" alt="logo text" width="80%" />
  <figcaption>Altium PCB</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod13/pcb3D.jpg" alt="logo text" width="80%" />
  <figcaption>3D view</figcaption>
</figure>

### Making the board
I had some trouble with the CNC engraver and the copper plates that were not perfectly plane so I ended up using chemical etching to make the board.
It went flawlessly and the result is extremely good.

<figure> <center>
  <img src="./../../img/mod13/board1.jpg" alt="logo text" width="80%" />
  <figcaption>After chemical etching</figcaption>
</figure>

Obviously, I still need to cut it to make the right shape then, especially for the USB connector so I used a rolling saw.

<figure> <center>
  <img src="./../../img/mod13/board2.jpg" alt="logo text" width="80%" />
  <figcaption>Cutting the outline</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod13/board3.jpg" alt="logo text" width="80%" />
  <figcaption>Cut board</figcaption>
</figure>

Time to solder everything, nothing complicated, especially with the magnifying glass, and I made sure to well tin the USB connector.

<figure> <center>
  <img src="./../../img/mod13/board4.jpg" alt="logo text" width="80%" />
  <figcaption>Cut board</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod13/board5.jpg" alt="logo text" width="80%" />
  <figcaption>Cut board</figcaption>
</figure>

### Programming the SAMD
To program the SAMD, I intended to use my own programmer but I think it did not held up together over time as copper turned green and I wasn't able to program my new board. So I had to rely on a commercial CMSIS-DAP programmer. It worked perfectly, I only needed to connect SWDIO, SWCLK and GND to my board.

<figure> <center>
  <img src="./../../img/mod13/program.jpg" alt="logo text" width="80%" />
  <figcaption>Connecting the board and the programmer</figcaption>
</figure>

I loaded the [sam_ba](https://github.com/mattairtech/ArduinoCore-samd/blob/master/bootloaders/zero/binaries/sam_ba_Generic_D11C14A_SAMD11C14A.bin) bootloader so I can use the Arduino IDE to program my board, which will initially ease up the process.

<figure> <center>
  <img src="./../../img/mod13/edbg.jpg" alt="logo text" width="80%" />
  <figcaption>Succesful progamming</figcaption>
</figure>

I started by checking that everything on my board worked correctly by lighting up the LEDs. Good thing I did because one was not perfectly soldered and wouldn't light up reliably so I needed to correct that soldering a bit !

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/ledSolder.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>
The third LED does not blink

I then tried to send data over the UART and directly read it.
Note that using the ArduinoSAMDCore for Mattairtech, you can use the RX2, TX2 Serial wich is the second UART channel on the SAMD by using "Serial2" command. The USB, if selected in the config, will be avaiable on "Serial" or "SerialUSB". However, there is currently a bug (not yet reported ?) that make the SerialUSB also communicate on the RX1,TX1 (so UART channel1). One of my LEDs being soldered on the TX1 pin, it would blink whenever I try to print on the SerialUSB. I tried multiple things to disconnect it (Serial config, using "Serial1.end()", pinMode, ...) but couldn't make it happen.

<figure> <center>
  <img src="./../../img/mod13/serialConfig.jpg" alt="logo text" width="80%" />
  <figcaption>SerialConfig</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod13/serial1.jpg" alt="logo text" width="80%" />
  <figcaption>Pin PA09 is used for SERCOM1 as well/figcaption>
</figure>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/ledSERCOM.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


Here is the code to make the LEDs blink and communicate over the bus and reading it back.

````
int led1 = 9;
int led2= 14;
int led3 = 15;


void setup() {
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(4, OUTPUT);
  Serial2.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);



}

void loop() {
  Serial2.println("test");
  if(Serial2.available()){
    Serial.print("received : ");
    while(Serial2.available()){
    Serial.print((char)Serial2.read());  
    }
    Serial.println("");

  }

  Serial.println("a");
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led1, LOW);  
  delay(300);
  digitalWrite(led2, LOW);
  delay(300);
  digitalWrite(led3, LOW);
  delay(300);
}
````
<figure> <center>
  <img src="./../../img/mod13/test1.jpg" alt="logo text" width="80%" />
  <figcaption>I can send an receive a message (on the same board)</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod13/connecting.jpg" alt="logo text" width="80%" />
  <figcaption>Connecting GND, RX and 3.3V between two boards</figcaption>
</figure>


### Adding some framing
Even though I'm using the UART protocol which already features start bit, stop bit, ... I will add "start of frame" and "end of frame" characters in my message to be able to detect the start and the end of a message on the bus.

To do so, I chose to use the 0x02 and 0x03 characters which are already set as start of text and end of text in the ASCII encoding.
<figure> <center>
  <img src="./../../img/mod13/ascii.jpg" alt="logo text" width="80%" />
  <figcaption>ASCII encoding table</figcaption>
</figure>

In the code, I simply check wheter there is data in the Serial2 buffer and if so, I read until I reach the start of frame.
I then check the address and if the message is for this node, I process it, otherwise, I read the buffer until I read the end of frame before starting the cycle again.

### Data format
To communicate order between the master and the nodes, I chose a very simple encoding.
Since I only want to switch on or off some LEDs, I use a pair _cmd/param_. The _cmd_ variable indicates which LED to switch state, and the _param_ variable indicates wheter it should be turned on or off.
For example, to light up the LED2, I type '21'.

The addresses are encoded as alphabetical values. The master being 'a' and all the nodes being 'b', 'c', ... up to 'z'.

### Communicating
Testing this idea proved to be very efficient and I could turn all the LEDs on and off on the slave by sending '11', '21', '31', '10', '20', '30' in loop. You can also slightly see the green LED blink on the master each time it communicates on the SerialUSB.

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/communicating.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/communicating2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

### Giving order through the SerialUSB
Now that it is working automatically, the final step is to incorporate the possibility to specifically give the order to switch on or off an LED through the SerialUSB terminal. There is however another bug where the Serials will get confused if you try sending data over UART right after reading incoming data on the USB buffer, and it will send '0x00' over the UART. I couldn't find the exact reason and it seems this bug as not yet been reported. The only solution is to add a small delay (300ms works) between the read of the USB buffer and sending the data over UART.

Here is the final result and the code

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/command
.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


This code works for both the master and the slaves. You only need to comment or uncomment the first line.
````
#define MASTER //uncomment if programming master, comment for slave

#define startFrame 0x02 // STX :start of frame
#define endFrame 0x03 // ETX : end of frame
#define DLY 250
#define slave1Address 'b'
#define masterAddress 'a'

#if defined (MASTER)
  #define myAddress masterAddress
#else
  #define myAddress slave1Address
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
}

#if defined(MASTER)

void loop() { //MASTER loop: write input data or pre-selected data to UART to slave1
  #if 1
  if(SerialUSB.available()){
    String input = "";
    while(SerialUSB.available()){
      input+=(char)SerialUSB.read();
    }
    SerialUSB.println(input);
    delay(DLY);
    sendMessage(slave1Address, input);
  }
  #else
  SerialUSB.println("start");
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
  #endif
}

#else
void loop() { //Slave loop: awaits data
  readMessage();
}

#endif

void sendMessage(byte address, String msg){ //adds start and end of frames
  while(Serial2.available()){ //flush receive buffer
        Serial2.read();  
      }

  Serial2.write(startFrame); //Add SOF
  Serial2.write(address); // write slave adress
  SerialUSB.println("sent message : " + msg);
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
  if(Serial2.available()){
    SerialUSB.println("reading message...");
    if( (d = (byte)Serial2.read()) == startFrame){ //checks SOF
      SerialUSB.println("start frame detected");
      while(!done){ //gather all data
        if(Serial2.available()){
          c = (char)Serial2.read();
          if(c == endFrame){ // until EOF
            done = true;
          }
          else{
            receivedMsg += c;    
          }
        }
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
  SerialUSB.println("processing message : " + String(cmd) + " " + String(param));
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
````


## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod13.zip)
