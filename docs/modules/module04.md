# 4. Electronics production

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group assignment: Characterize the design rules for your PCB production process </li>
    <li> Individual assignment: Make an in-circuit programmer by milling the PCB, program it</li>
    <li> Optionally try other PCB processes</li>
  </ul>
</div>

<div class="dottedLine"></div>

So this week, we started to produce some electronics, meaning that we had to "create" our boards with different processes such as CNC milling, ink deposit, chemical production, ...

I learned a lot about using the CNC and the production of electronics board with it. I also learned about communication protocols and micro-controllers and how to program them.

I had some experience making my PCB using chemical processes and "industrial process" (i.e. sending the Gerber files to a production company) and how to solder both through-holes and SMD but I took the time to improve my soldering techniques.

1206 SMD seems big but is so tiny when you need to make the soldering yourself.. I feel bad for my technician at the Uni which solders 0805 every time I ask him. Thanks Jof !

## Introduction to Electronics Production

### CNC design rules

Note that since the copper is directly in contact with the humid air, it tends to oxidize over time. A good practice is therefore to either cover the tracks with solder or to cover the board in an epoxy resin or any king of protection.

<video width="640" height="480" autoplay loop>
  <source src="./../../img/mod04/cncVideo.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

## Using the Vynil cutter
Last week I used the Vynil cutter to make a small PCB. I didn't make any more but I think it suits this week's assignments well so here is a pic!

<figure> <center>
  <img src="./../../img/mod03/onPlastic.jpg" alt="logo text" width="80%" />
  <figcaption> My PCB using the Vynil cutter</figcaption>
</figure>

### others

<video width="640" height="480" autoplay loop>
  <source src="./../../img/mod04/volteraVideo.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

## Introduction to microcontrollers
A µ-controller is an integrated circuit (IC) that is like a very small computer, able to perform specific tasks. They are programmed to perform these tasks over and over again, on loop (but can be programmed to respond to conditions of course).

A µ-controller contains multiple parts: a processing unit of course but also some memory. This memory is either volatile: DRAM (dynamic, inexpensive and space-efficient and SRAM (static, much faster but also more expensive) that will be erased when not powered or non-volatile like EEPROM or Flash memory.

The µ-controller does not work on its own but is rather embedded and works with other components so it needs inputs and outputs (I/O) for peripheral access.

Finally, a big requirement for the µ-C to function is the clock which is sometimes provided externally and allows the µ-C to perform timer conditions.

### µ-C Families
There are two main microcontroller families: the AVRs and the ARMs:
AVRs are manufactured by Atmel (now Microchip) and the most common examples are the ATTiny and ATmega chips which are cheap and effective. That is somewhat of an issue as if you produce something industrially that relies on an AVR controller and Atmel stops producing them...

ARMs are produced by multiple companies and are usually used for embedded systems as they provide more features and memory than their AVRs counterparts. They are however more difficult to solder (less DIP format and usually more pins), less available in general and are usually constrained to 3.3V (requires additional converter from 5V therefore).

They both use RISC (reduced instruction set computer) instructions, meaning they require a few clock cycles (usually one) to perform an instruction but these instructions are rather primitives, allowing more space for registers.

```asm
#RISC instructions
LOAD A, 2:3
LOAD B, 5:2
PROD A, B
STORE 2:3, A

#CISC instructions
MULT 2:3, 5:2
```

### µ-C programming
As said before, µ-C can perform specific tasks like switching an LED on or off or actuating some servo-motors. To specify these tasks, the µ-C needs to be programmed.

To be programmed, a µ-c must first be loaded with a bootloader, i.e. a small piece of code that can reprogram the rest of the memory based on what is sent to the µ-C and is interpreted by the bootloader. At reset, it's the bootloader that runs first and has a look at the programming port to either reprogram the rest of the memory or jump directly to the programmed main code.
Then, code can be sent to program the µ-C the way you want it.

#### AVR
AVRs are programmed using ISP (in-system programming), PDI (Program and Debug Interface) or UPDI (unified Program and Debug Interface). The latter is the one used on newer AVR devices and consists in a one-wire interface.

#### ARM
ARMs are programmed using either a JTAG (Joint test Action Group, the group who designed the standard) interface or a SWD (Serial Wire Debug) interface.

JTAG uses 5 pins: clock, mode select, data-in, data-out and reset. It can be reduced to only serial data and clock.

SWD is an implementation of JTAG for ARM processors and consists of simply two pins: data and clock (SDIO and SDCLK) along with VDD and GND obviously and an optional reset.


## First board: AVR programming board (using SAMD11)
The first board is a programmer (or rather a USB-UPDI converter) board for AVR device. I used my instructor [Quentin](http://fabacademy.org/2020/labs/ulb/students/quentin-bolsee/projects/samd11c_uart-updi/)'s board. It is very minimalist and does the work flawlessly.

So the idea here is to use an ARM board (SAMD11) to convert USB (serial emulation) data to UPDI so that we can use this to program AVR (Atmel, like ATTiny ou ATMega) µ-controllers.

The board is rather simple:
<figure> <center>
  <img src="./../../img/mod04/schematicAVRProgrammer.png" alt="logo text" width="80%" />
  <figcaption> Quentin's board</figcaption>
</figure>

It uses the USB 5V and a 5V-3.3V converter to power the ATSAMD11 and consists of a reduced-JTAG connection (Clock, data, VDD, GND) to first install the bootloader and will be able to convert Serial to UPDI or UART based on the jumper selection and can provide 5V or 3.3V to the AVR device. Some protection resistors limit the current.

The board has been manufactured using the CNC milling machine described before. I used a 1/64" flat mill for accurate traces and a 1" flat mill for cutting the edges of the board and increase the clearance between the tracks.

<figure> <center>
  <img src="./../../img/mod04/boardMilled.jpg" alt="logo text" width="80%" />
  <figcaption> The board is milled</figcaption>
</figure>

It was then time to solder the components on it. Nothing too difficult as I'm used to soldering still 1206 SMD is tiny so it's always a bit challenging!

<figure> <center>
  <img src="./../../img/mod04/boardAVR.jpg" alt="logo text" width="80%" />
  <figcaption> The soldered board</figcaption>
</figure>

### The Bootloader
Time to install the bootloader on the SAMD11 !
Because the SAMD11 is powered (5V) from the USB, it has to be connected. At that time I noticed two things.
First, the **board is too thin to sit tight in an USB port**... So I added extra duct tape under it to make it bigger (real tinkering there !)
Second, I must have done a mistake in the CNC file because the **board edges were a bit too big**... Time to file the excess to make it fit the USB port !

<figure> <center>
  <img src="./../../img/mod04/filing.jpg" alt="logo text" width="80%" />
  <figcaption> Oops, I gotta file the excess</figcaption>
</figure>

Then I used my instructor's own programmer to program my board (after an initial struggle with another one, see below). Plugged his board's USB into my computer along my own board (for the 5V). finally, I connected the JTAG from his board to mine.
The SAMD11 is filled with a bootloader ([sam_ba_Generic_D11C14A_SAMD11C14A.bin](https://github.com/mattairtech/ArduinoCore-samd/blob/master/bootloaders/zero/binaries/sam_ba_Generic_D11C14A_SAMD11C14A.bin)) and I downloaded [edbg](https://github.com/ataradov/edbg), a CMSIS-DAP programmer that is used with the command line.
Linux is cool for that... You can easily check if your USB port is working and what is connected to it. Moreover, edbg is easier to use once compiled on a Linux machine. Anyway, I succeeded with Windows eventually but that was a bit harder.

First, I connected the programmer and I could find it with edbg. Then I wanted to try and erase the memory of my chip using the -e flag. That's when I realized I had to find the exact name for my SAM target (which is samd11).

<figure> <center>
  <img src="./../../img/mod04/attachedDebug.jpg" alt="logo text" width="80%" />
  <figcaption> Good, the debugger is found</figcaption>
</figure>

Unfortunately, I initially couldn't make it work. It is probably the programmer that I first used and the fact that my USB ports did not always respond immediately.

<figure> <center>
  <img src="./../../img/mod04/noresponse.jpg" alt="logo text" width="80%" />
  <figcaption> Nope, can't program</figcaption>
</figure>

I then changed it for my instructor's programmer and it went through successfully.
`edbg -bpv -e -t samd11 -f sam_ba_Generic_D11C14A_SAMD11C14A.bin`

<figure> <center>
  <img src="./../../img/mod04/programmed.jpg" alt="logo text" width="80%" />
  <figcaption> Victory !</figcaption>
</figure>

### USB-UPDI converter
Once done, we can use the Arduino IDE and some libraries to program the SAMD11 using the USB port since a bootloader is now present.

I installed the Arduino core for SAMD board into Arduino. First, I tried to install those that are natively available in the board manager (SAMD Core) but I couldn't compile my test code.

I then looked up online only to find a fork of this core for the exact bootloader that I loaded;
[Arduino Core](https://github.com/mattairtech/ArduinoCore-samd).

The procedure to install it on Arduino is as follows:
First, add the JSON index of the core into the board manager (preferences menu)

<figure> <center>
  <img src="./../../img/mod04/arduinoPreferences.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then open the board manager and look for the mattairTech SAM D Core.

<figure> <center>
  <img src="./../../img/mod04/boardManager.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Once installed, select the correct COM port on which the board is connected and make sure to choose the correct board (Generic D11C14A):


<figure> <center>
  <img src="./../../img/mod04/boardChoice.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Finally, make sure to change the Serial config:

<figure> <center>
  <img src="./../../img/mod04/serialConfig.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

We can now start to program our board with the code we want.
In this particular case, because we want to convert Serial to UPDI, we simply ask the chip to convert USB data (if data is awaiting on the serial/USB bus) to UPDI (then write it on the UPDI port) or the inverse (if data is received on the UPDI end, then write the data on the Serial port).

```c++
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
```

<figure> <center>
  <img src="./../../img/mod04/programmingComplete.jpg" alt="logo text" width="80%" />
  <figcaption> Programming complete ! Yeah !</figcaption>
</figure>

Our programmer is ready to... Program !


## Second board: ARM programmer



## To go further
I would like to use the CNC milling to make USB keys and an AVR controller to be able to... do things. I don't know what yet but I'm sure I'll find more ideas. I could use a 3D-printer to make a small case for it, maybe some epoxy resin to protect the circuit...

## My files
:material-download-box: [My Design files](./../files/mod04.zip)
