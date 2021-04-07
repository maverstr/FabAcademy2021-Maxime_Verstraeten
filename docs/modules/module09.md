# 8. Mechanical and Machine Design

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: Design a machine that includes mechanism, actuation and automation.
</li>
    <li> Build the mechanical parts and operate it manually.</li>
    <li> Actuate and automate your machine. </li>
  </ul>
</div>
<div class="dottedLine"></div>


*Urumbu X-Y flexure machine*
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/square.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br>

<video width="600" height="auto" autoplay loop>
  <source src="./../../img/mod09/urumbu.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br>
*Automatic Sun-avoidance blinders*
<video width="600" height="auto" autoplay loop>
  <source src="./../../img/mod09/automaticStore.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


## Introduction
Most of the work will be depicted as well in our [group assignment page](http://fabacademy.org/2021/labs/ulb/) and on [Jason's website](http://fabacademy.org/2021/labs/ulb/students/jason-pettiaux/).

This week, Jason and I decided to improve the [Urumbu project](https://gitlab.fabcloud.org/academany/fabacademy/2020/bootcamp/spicy/-/tree/master/Urumbu). The idea of this machine is to use flexure to decompose X and Y axis and to be able to actuate them with separate actuators that do not need to move with the other one (contrary to classical CNC machines for example).

We also wanted to make a "machine-day" where we built a machine in a single day!

## The Urumbu improvement
### Mechanical Design
The Urumbu project is inspired from the flexures and in particular this [2004 thesis from Shorya Awtar](http://academy.cba.mit.edu/classes/computer_cutting/56836505.pdf) and has been later reworked by Denis Terwagne.

We re-designed the stage and several other parts in both SolidWorks and Fusion360.
#### The stage
Most of this part has been done by Jason. He decided to redraw the Urumbu and optimize most of the design to mainly increase the range of motion, increase the rigidity and finally, decrease the size.
<figure> <center>
  <img src="./../../img/mod09/UrumbuAnalysis.svg" alt="logo text" width="80%" />
  <figcaption> Improvements done by Jason</figcaption>
</figure>


We decided to print the new design using PLA but ideally, it would be better to CNC it in Teflon or Polypropylene to reduce the friction.

We also added a new stage for the motors and the new actuators.

**add a pic**

The motors are fixed on the side of the machine due to the spiral actuators (see below) and they are connected together using I²C.
<figure> <center>
  <img src="./../../img/mod09/motorMounting.jpg" alt="logo text" width="80%" />
  <figcaption>Motor placement</figcaption>
</figure>

We initially took the wrong measurements so the motors were too high for our stage but with quick thinking we were able to add some parts to raise our stage higher.

<figure> <center>
  <img src="./../../img/mod09/patin.jpg" alt="logo text" width="80%" />
  <figcaption>Adding some pads to raise the stage!</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/stageAssembly.jpg" alt="logo text" width="80%" />
  <figcaption>Assembling the stage</figcaption>
</figure>

#### The actuators
The Urumbu machine was already more or less working but it lacked actuators. [Quentin Bolsee](http://fabacademy.org/2020/labs/ulb/students/quentin-bolsee/) added some motors last year but they were not working as easily as intended and they actually only made use of a quarter of the full range of motion.

I decided to design new actuators based on a spiral shape. The idea of this design is to have actuators that are really easy and fast to make (laser cut or 3D-printed), have a high resolution and do not require specific material. Moreover, this kind of design does not need a lot of room. To be ideal, the spirals should be made of Teflon and bearings should be added (which we did) but they are not necessary for the machine to work.

The initial was to directly place the spiral on top of the motor:

<figure> <center>
  <img src="./../../img/mod09/spiral1.jpg" alt="logo text" width="80%" />
  <figcaption>Initial design</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/spiral2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

The idea is to obtain this kind of movement:
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/spiralPrinciple.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

However, I then realized that 3D-printing takes quite some time and also, it would reduce the friction if we use laser-cut plexiglas.
<figure> <center>
  <img src="./../../img/mod09/spiral3.jpg" alt="logo text" width="80%" />
  <figcaption>Laser-cut plexiglas spiral</figcaption>
</figure>

This early design was just a test (_spiral management_ :smile:) but we ended keeping the same idea.

One other advantage of the spiral design is that even though you are limited by the size of the pin that will insert into the spiral, you can add many revolutions, and the more revolutions there are, the smaller the displacement resolution is.

We made several tests and in the end, to conserve some rigidity with the plexiglas and for this first version, we decided to use only a single revolution. Since we use stepper motors with 200 steps (see below) the resolution is still quite enough.

We used to Teflon bearings to reduce the friction between the 3D-printed pin of the flexure design and the plexiglas.

due to the fact that the spiral have to be centered initially, we had to offset the motor position on the stage.

<figure> <center>
  <img src="./../../img/mod09/spiral4.jpg" alt="logo text" width="80%" />
  <figcaption>Spiral mounted on the stage with the motor</figcaption>
</figure>

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/spiral.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

As it can be seen on the video, the spiral design is not very big, very simple and easy to make and assemble, has a nice resolution, features low backlash and are easily changeable to increase or reduce the resolution (number of revolutions, materials, ...).

Another mirrored spiral could be added on top to reduce the torsion and improve the rigidity of the mechanism. We did not find it necessary but it might be a way to improve the system response and increase the number of revolutions (and thus the resolution) without losing too much rigidity.

#### Final design
<figure> <center>
  <img src="./../../img/mod09/stageFull1.jpg" alt="logo text" width="80%" />
  <figcaption>Top-view</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/stageFull2.jpg" alt="logo text" width="80%" />
  <figcaption>Bottom-view</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/stageFull3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


### Electronics design
To actuate our machine, we obviously needed some motors and some control.

We decided to use Nema-17 stepper motors and Quentin's recent motor control boards. These were still in development so we spent some time troubleshooting them but, spoiler alert, it worked in the end.

#### Communication
The way it works is pretty simple. The idea is to have several nodes, all identical that can be linked together. The first node will be the one the USB is connected to so we can send some orders to the motors.
We used the I²C communication protocol. In this protocol, we have one master and several slaves (in practice there can be multiple masters as well but not in our case). Each node can sense (using pull-down resistors) whether a node is following or preceding it. Using this information, we can easily deduce the master as the node not being preceded (except by the alimentation board but it does not pull-down this pin). Then, each following node receives the current address offset, sets its address based on this value, and forwards the message to the next node with an incremented address. Once there are no node behind, the last node knows it is the last in the chain.

<figure> <center>
  <img src="./../../img/mod09/soldering.jpg" alt="logo text" width="80%" />
  <figcaption>Soldering: a critical step</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod09/nodes.jpg" alt="logo text" width="80%" />
  <figcaption>Two motors and the supply board, all connected together in chain</figcaption>
</figure>


To communicate orders, we use the classical I²C, meaning we have a data and a clock lines. The clock is set by the master.

The master receives some orders through the Serial communication (either directly through a terminal or a Python script). If the orders are for him, then he does them, otherwise, he will broadcast the message over I²C (address first, followed by the message). The receiving node will then be able to acknowledge the message and reply if necessary.

Several orders can be defined using this syntax that we developed.

`address:port=value`

First, we specify the adress (i.e. the node) that we want to talk to. Then, we specify the port, i.e. the value that we want to set for this node. For the moment, this can be either 0 for the position and 1 for the movement speed. Finally, we specify the value.

For example:

- `1:1:200` Will set the speed of the second node to 200steps/second.
- `0:0:100` Will ask the first node (the master) to move to the position equal to a 100 steps from its initial position.


The I²C communication protocol can be seen on the oscilloscope and has been tested up to 30cm of wire length, at 100kHz:
<figure> <center>
  <img src="./../../img/mod09/i2cClock.jpg" alt="logo text" width="80%" />
  <figcaption>The clock signal at 70kHz here</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/i2cData.jpg" alt="logo text" width="80%" />
  <figcaption>The address is sent over the data and will then be followed by the message</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/i2cTest.jpg" alt="logo text" width="80%" />
  <figcaption>Successfully sent and received "test" message ! (Using a logic analyzer)</figcaption>
</figure>


All of the code is available in the design files but here is a snippet of it for fun, and as you can see, this not quantum mechanics :smile:
````
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

  // USB CDC (so baudrate doesnt matter)
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
````

Additionally, for later developments and complex shapes, it will be required to handle the synchronicity of the movements. We can therefore implement it as a "sync" message that is broadcasted (no address) over the I²C network.


### Motors and supply
The motors are 12V Nema-17 stepper motors. We need a board that will be able to supply and regulate this voltage.
The supply board can be fixed onto the stage and the motors are screwed directly on the stage on the side.
<figure> <center>
  <img src="./../../img/mod09/supplyFixed.jpg" alt="logo text" width="80%" />
  <figcaption>Fixing the supply board</figcaption>
</figure>

Then, we had to connect the motors to the communication boards but first, let's test the motors before assembling everything:
<figure> <center>
  <img src="./../../img/mod09/motorTesting.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod09/motorToBoard.jpg" alt="logo text" width="80%" />
  <figcaption>Connecting the motors to the board</figcaption>
</figure>

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/stepperTurning.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

**It works !** Let's finish the assembly.

<figure> <center>
  <img src="./../../img/mod09/motorAssembled.jpg" alt="logo text" width="80%" />
  <figcaption>Finished!</figcaption>
</figure>




<figure> <center>
  <img src="./../../img/mod09/motorsChained.jpg" alt="logo text" width="80%" />
  <figcaption>Motors chained together and on the stage</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod09/connectedMotor.jpg" alt="logo text" width="80%" />
  <figcaption>Zoom on a chained motor</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/elegant.jpg" alt="logo text" width="80%" />
  <figcaption>The plexiglas really makes it aesthetic...</figcaption>
</figure>



### End result:
In the end, using a Python code that sends the data over Serial, it was really easy to make a square shape.

````
import serial
import time

ser = serial.Serial("COM13", baudrate=115200)

delay = 0.85

for i in range(2):
    ser.write(b"0:0=80\n")
    time.sleep(delay)
    ser.write(b"1:0=80\n")
    time.sleep(delay)
    ser.write(b"0:0=-80\n")
    time.sleep(delay)
    ser.write(b"1:0=-80\n")
    time.sleep(delay)


ser.write(b"0:0=80\n")
ser.write(b"1:0=80\n")
time.sleep(delay)
ser.write(b"0:0=-80\n")
time.sleep(delay)
ser.write(b"1:0=80\n")


ser.close()

````

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/square.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>



## Automatic window shutter
As Spring is finally coming around, the sun starts hiding our screens at the end of the day when the sun sets.
Because of this, we also decided to design a machine in a single day that would be a prototype to avoid this kind of issue.

The idea is really simple: having a shutter that moves with a motor, some fishing lines and a pulley and a pair of photoresistor to detect whether the light is present or not.

### Mechanical design
We need only a few things:
- A motor case.
- A pulley system
- Some wires or fishing lines
- A capstan to wrap these wires
- Some cardboard to make our testing window prototype

Using SolidWorks I designed these parts, making sure they were all designed parametrically so that changes could happen very fast if we needed to iterate !

#### The motor case:
The DC motor we found was not flat, mainly because it also features a gearbox (Oops forgot to take a pic...). So we needed to make it flat so that it is just easier to manipulate and place in our design. Nothing too difficult, here is the result
<figure> <center>
  <img src="./../../img/mod09/motorCase1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/motorCase2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

#### Pulley system
We need a "circle" with a narrow band to hold the wire in place. This circle must be able to rotate freely on an axis that will be placed horizontally.

<figure> <center>
  <img src="./../../img/mod09/circle.jpg" alt="logo text" width="80%" />
  <figcaption>The circle</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/holder.jpg" alt="logo text" width="80%" />
  <figcaption>The axis</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/holder2.jpg" alt="logo text" width="80%" />
  <figcaption>Adding some locking pins</figcaption>
</figure>

With this design, the wheel can turn freely while being held in place, exactly like we want.

Then I wanted to test the topology optimization. I made some stress-strain simulations in SolidWorks and made a new topology study to try to remove as much material as possible while minimizing the impact on the deformations.
<figure> <center>
  <img src="./../../img/mod09/simulation1.jpg" alt="logo text" width="80%" />
  <figcaption>Using the motion simulation addon</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/simulation2.jpg" alt="logo text" width="80%" />
  <figcaption>Creating a new study</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/simulation3.jpg" alt="logo text" width="80%" />
  <figcaption>Making a new topology study</figcaption>
</figure>

I then needed to define the material (I chose ABS but we used PLA instead, it did not impact our design much), the fixtures (i.e. the parts that are fixed in the design), and the external load (I estimated a safety margin of 2kg of force in the vertical direction).
<figure> <center>
  <img src="./../../img/mod09/simulation4.jpg" alt="logo text" width="80%" />
  <figcaption>Defining the external load</figcaption>
</figure>

Finally, you can set the goal of the simulation: here, obtaining the best stiffness to weight ratio.
<figure> <center>
  <img src="./../../img/mod09/simulation5.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Time to run the study:
<figure> <center>
  <img src="./../../img/mod09/simulation6.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

And observe the results
<figure> <center>
  <img src="./../../img/mod09/simulation7.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/simulation8.jpg" alt="logo text" width="80%" />
  <figcaption>After some post-processing and tweaks</figcaption>
</figure>

In this case, I was not really happy with how much material was left near the screw holes...
Let's try again but this time while specifying that we want to keep some material there.

<figure> <center>
  <img src="./../../img/mod09/simulation9.jpg" alt="logo text" width="80%" />
  <figcaption>Adding preserved region</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/simulation10.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/simulation11.jpg" alt="logo text" width="80%" />
  <figcaption>New result</figcaption>
</figure>

This time, we are much more happy ! In the end, it held the load extremely well, while having a reduced printing time and material cost highly reduced !
<figure> <center>
  <img src="./../../img/mod09/topology.jpg" alt="logo text" width="80%" />
  <figcaption>Normal VS optimized topology</figcaption>
</figure>

#### Capstan
To wrap the wire (or rather the fishing lines that we used), I made a capstan really easily in SolidWorks using the revolution, helixes and linear patterns functions.
Why the capstan you may ask ?
Well, the critical influence of  friction on this kind of devices emphasizes the importance of how the motion is transmitted along the system. The selected design is a pulley-capstan system because this reduction technique introduces negligible friction forces in comparison to traditional gearboxes, avoid backlash and provide a reduction efficiency of nearly 100%.
I chose of V-thread instead of smooth capstan to have two contact points between the cross-section of the cable and the thread which increases adhesion.
To avoid slipping, we can do multiple turns and we know that wrap friction increases exponentially with the wrapping angle. 3 turns should be enough.
Finally, it will prevent the cable to wrap around itself and therefore will limit the change in response to a specific command as the diameter of the capstan will always stay the same.
<figure> <center>
  <img src="./../../img/mod09/capstan.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

#### Assembly
We mounted everything on a cardboard box that was made to imitate the window in a room.
<figure> <center>
  <img src="./../../img/mod09/cardboard.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/wires1.jpg" alt="logo text" width="80%" />
  <figcaption>Making some knots</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod09/wires2.jpg" alt="logo text" width="80%" />
  <figcaption>Being a team really helps there !</figcaption>
</figure>

### Electronics design
#### Motor control
To control the DC motor, I used a circuit that uses a 7404 (inverter IC) and a L293. the L293D is a Half-H driver, with the D version already features some diodes to protect the circuit from the high voltage when switching the motor off (the role of a flyback diode is especially to prevent this overvoltage by providing a return path for the current to discharge in the motor inductor resistance, otherwise V = Ldi/dt... and boom!).

Here is a simple schematic that explains it.
<figure> <center>
  <img src="./../../img/mod09/schematic.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
I have multiple wires at the end of board: I can control two motors, meaning I have 4 outputs (two per motor).
The grey wire is the GND.
Yellow and green = +12V motor supply.
Orange and red = Enable (motor turning) (active low)
Purple and blue = Direction of the motors.
Brown = logical high (5V).

To have an easy time, I used an Arduino Due to control the motor (two digital pins for the direction and the enable) as well as the 3.3V, 5V and 12V from the Vin pin (I supplied the Arduino using a 12V DC Jack).
<figure> <center>
  <img src="./../../img/mod09/DCMotor.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
With everything connected, it was really easy to get the motor to turn in both ways.

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/DCTurning.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

We can then simply hook it to the mechanical design to get a moving shutter
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/shutterMoving.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

#### Light information
To get the information about the lighting, we used some phototransistors. Jason did the schematic but all in all, it is quite easy: we have two pull-down resistors and a 3.3V source. The phototransistor let the current flow more or less depending on the amount of light received so the value of the voltage just above the resistors vary depending on the amount of light !

we can then fix this little PCB inside our "cardboard box" and start experimenting:

As we approach an infrared LED, we can observe that the voltage increases:
<figure> <center>
  <img src="./../../img/mod09/LED.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/lightInfo.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

We can also observe the voltage variation as we are near the window and the "shutter" moves around
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/lightInfo2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

As the shutter is raised or lower, the amount of light changes.
<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod09/lightInfo3.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

### End result

In the end, it was snowing the day we built it so... We were not really able to showcase its ability but we were able to:
a. Detect the amount of light received (though it was really difficult as the weather was horrible and our photoresistor was not reactive to the LED light of our phones which was all we had)
b. Move the shutter using the motor according to the amount of light perceived by each phototransistor.


## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod09.zip)
