# 12. Output devices

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group Assignment: Measure the power consumption of an output device. </li>
    <li> Add an output device to a microcontroller board you've designed and program it to do something</li>
  </ul>
</div>
<div class="dottedLine"></div>

## Group assignment
For the group assignment, I had already measured the current consumption of an LED on my ESP32 board right [here](./../module10/#making-a-program).

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod10/blink2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

Because I was powering the board with 3.3V and the current consumption increased from 0.37 to 0.44mA when lighting up the diode, I can deduce the current consumption of the LED to be 7mA which gives a total heat dissipation of 23.1mW through the LED and the current limiting resistor of 220Ohms.

We can also compute it in another way. I have a current limiting resistor of 220Ohms and the LED has a forward voltage drop of 1.6V for 7mA. Powering from 3.3V, that leaves 1.7V through the resistor, which is indeed very close to 7mA.

<figure> <center>
  <img src="./../../img/mod12/LED.jpg" alt="logo text" width="80%" />
  <figcaption>Forward voltage Vs forward current for the LTST-C150 RED LED</figcaption>
</figure>

Also, for another project, I powered another LED through inductive powering. I supply my class E amplifier with 9V DC and the current consumption is about 30mA (varies with the distance between the primary and the secondary of course). The power consumed is therefore about 270mW in the class E.


<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod12/inductive.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

## Output device 1: LED 7 segments
I found an LED 7 segment display KINGBRIGHT SA23-12SRWA. The datasheet is available [here](https://www.mouser.be/datasheet/2/216/SA23-12SRWA-57377.pdf) but is quite short.


<figure> <center>
  <img src="./../../img/mod12/LEDDisplay.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

We can see it is a common anode display, meaning all the anodes of the LED are connected together. Also, there are no resistors so we'll need to add them ourselves
<figure> <center>
  <img src="./../../img/mod12/commonAnode.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

The pins are indicated for each segment and we can also see that the number of LEDs for the decimal point (DP) is less than for the other segments so we'll have to increase its resistor value.

We can find the pin relation to the segments by having a look at the package diagram:
<figure> <center>
  <img src="./../../img/mod12/package.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

We can also see that maximum current flow is 30mA and that we'll need at least 7V DC to light up the LED.
<figure> <center>
  <img src="./../../img/mod12/maxCurrent.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>
<figure> <center>
  <img src="./../../img/mod12/forwardVoltage.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Based on this, I know I will not be able to power it directly from a microcontroller. I decided to use a 12V power supply and the ESP32 board that I already designed in the past. I also got COVID-quarantined this week so I was limited to working on a breadboard with the few components I had at hand...

Note that you cannot use a single resistor for all the LEDS as, if you do that, the diode with the lesser forward voltage (tolerance and imperfection being at play here) will receive all the current before it fries and the current goes through the next one.
<figure> <center>
  <img src="./../../img/mod12/LEDDONT.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

The circuit is simple: I use PNP transistors (PN2222) to activate each individual segment. The transistors are toggled using the GPIOs of the ESP32 and are in saturation from 2V (so they will be with the 3.3V output of the GPIOs). Each BJT has a base resistor of 1kOhms and the LEDs are limited in current by a 100ohms resistor each.

<figure> <center>
  <img src="./../../img/mod12/schematic1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

### Making the circuit
As said, I didn't have access to the CNC engraver so I did my work on a breadboard but I took special care to make sure it is readable and well-organized.

I first tested the displays by powering a single segment (the DP here) by supplying it with low voltage:

<figure> <center>
  <img src="./../../img/mod12/firstTest.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then when I was sure it worked, I made the breadboard design:

<figure> <center>
  <img src="./../../img/mod12/bread1.jpg" alt="logo text" width="80%" />
  <figcaption>The display, 12V and the circuit</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod12/bread2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod12/bread4.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


Then I tested to toggle the transistor with a commercial devkit for ESP32.

<figure> <center>
  <img src="./../../img/mod12/bread3.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Then when I knew it worked well, I connected it all to my own ESP32 board.

<figure> <center>
  <img src="./../../img/mod12/working.jpg" alt="logo text" width="80%" />
  <figcaption>Ok it works !</figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod12/esp32.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>


<figure> <center>
  <img src="./../../img/mod12/zero.jpg" alt="logo text" width="80%" />
  <figcaption>Final result</figcaption>
</figure>

### Counting to 15!
Once I could get a simple zero to show up, I made a quick code to go from 0 to 15 (or F in hex) and blink the decimal point twice as fast.
Pretty simple all in all. I first made my truth table for all the numbers and I then apply it in a function by reading the bits (by applying a mask) and selecting the correct segment to light based on the bit value:
````
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
````

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod12/counting1.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br> A zoomed out view :smile:

<video width="854" height="480" autoplay loop>
  <source src="./../../img/mod12/counting2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

### Possible improvement and extension
With NPN transistors, it would also be possible to multiplex multiple displays. We then link each display segment together (a's with a's, b's with b's, ...) and we select the display we want to light up by toggling the corresponding NPN transistor to allow current from the 12V supply to flow. The eye "low-pass filter" will simply let you see all displays light up together even though they toggle real fast. You therefore need 8(7 segments + DP-) +1 per display(selectDisplayPin) pins in total instead of 8 per display.

This requires NPN transistors, as it is impossible to do with PNP (VB should be close to 12V which I cannot supply) so I couldn't do it this week but it isn't difficult per se.


<figure> <center>
  <img src="./../../img/mod12/multiplexing.jpg" alt="logo text" width="80%" />
  <figcaption>Final result</figcaption>
</figure>

## Output device 2: speaker
Finally, I had a speaker lying around so I gave it a try as well.
To make it work, nothing is complicated electrically as it is a simple coil that you make vibrate through a PWM at a set frequency for each note.

Obviously, I chose to power it from 12V as well (but it could work with 5V as well, without needing a resistor then) and the inner resistance of the speaker being 8ohms, I protected it with a 100Ohms resistor and the base resistor is again, like for the first project, 1k as well.
<figure> <center>
  <img src="./../../img/mod12/speakerSchematic.jpg" alt="logo text" width="80%" />
  <figcaption>Final result</figcaption>
</figure>

I then found a nice code to modulate the PWM using the "ledc" functions of the ESP to obtain notes and melody! ([credits](http://electroniqueamateur.blogspot.com/2019/09/jouer-une-melodie-avec-lesp32.html))

Here is my version of the code:
````
const int out = 18;

// note frequencies: C, C#, D, D#, E, F, F#, G, G#, A, A#, B
const float note[12] = {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47
                       };

const int notesNumber = 32;
const int bpm = 150;

const int song[][3] = { {4, 2, 2}, {5, 2, 1}, {7, 2, 3}, {0, 3, 6},
{2, 2, 2}, {4, 2, 1},{5, 2, 8},
{7, 2, 2},  {9, 2, 1},  {11, 2, 3},  {5, 3, 6},
{9, 2, 2}, {11, 2, 1}, {0, 3, 3}, {2, 3, 3}, {4, 3, 3},
{4, 2, 2}, {5, 2, 1}, {7, 2, 3}, {0, 3, 6},
{2, 3, 2}, {4, 3, 1},{5, 3, 8},
{7, 2, 2}, {7, 2, 1}, {4, 3, 3}, {2, 3, 2},
{7, 2, 1}, {5, 3, 3}, {4, 3, 2}, {2, 3, 1},{0, 3, 8}
};

void setup() {
  ledcAttachPin(out, 0); //broche 18 associée au canal PWM 0
}

void loop() {

  int freq;

  for ( int i = 0; i < notesNumber ; i++ ) {
    freq = round(note[song[i][0]] * 2.0 * (song[i][1] - 1));
    ledcSetup(0, freq, 12);   
    ledcWrite(0, 2048);  // duty cycle 50%
    delay(bpm * song[i][2] - 50);
    ledcWrite(0, 0); // duty cycle 0% to slice notes
  }
delay(2000);
}
````

And the nice result:
<video width="700" height="480" controls>
  <source src="./../../img/mod12/speaker.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

You can see I used my commercial devkit to test it out and then I later broke my USB-B connector on my own board without a means to solder it back so it was good news I had the commercial board with me!
## My design files
:material-download-box: [My Design files](http://academany.fabcloud.io/fabacademy/2021/labs/ulb/students/maxime-verstraeten/files/mod12.zip)
