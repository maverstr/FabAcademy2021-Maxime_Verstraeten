# Inputs, outputs and electronics

There are multiple inputs and outputs in this project.

## Chamber pressure
To handle the chamber pressure, I chose a vacuum pomp from Digi-key for its low price and availability. It is a very simple DC pump (ROB-10398) that I will connect to a L293D motor driver and control via the ESP32 (see below).

<figure> <center>
  <img src="./../../img/finalProject/ROB.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

## Phantom filling
To fill the phantom with air or water, I will use cheap no-name 12V DC peristaltic pump available from Amazon. Because they are cheap, I am going to use two of them to reach the correct flowrate (cystometric rate of 10-100mL/min and physiological filling rate of 1.4mL/min).

<figure> <center>
  <img src="./../../img/finalProject/peristaltic.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

Also, because they are cheap once again, I use "inertia" tanks to smooth the response curve.

They will be controlled like the chamber pump with the L293D.


## Data visualization
To output some data like the current flowrate or pressure, I initially wanted to use a LCD TFT screen. One of the most common LCD driver is the ILI9341. Multiple brands sell boards with this LCD as well as a touchscreen interface.

I was hoping to be able to communicate with it through the SPI interface (the ILI9341 is capable of that) but I chose a wrong brand (AZdelivery) for the board that redirected the SPI to a SD card reader. It is then only possible to send data to it using the 8-bit parallel bus, which requires a total of 12 pins to make it work, which is a lot on a small ESP32, already dealing with other inputs and outputs.

<figure> <center>
  <img src="./../../img/finalProject/TFT.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>

## Control inputs
To control some parameters like the pomp flow rate, I use a potentiometer and some push buttons that are connected to the ESP32.

Initially, I also wanted to use the LCD touchscreen to be able to control some variables.

## alphanumeric LCD
BTHQ21605AV-YETF-LED04-12C-5V


##  Inputs: pressure measurements
To control the pressure inside the chamber, it is nice to have a measurement of this.
To do so, I chose a pressure sensor that is able to measure up to 2 bars: the MPRLS0030PG0000SA. I wanted it be reachable using I2C but this version was not available on the vendors I checked, so I took the SPI version.

<figure> <center>
  <img src="./../../img/finalProject/MPRL.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>


For the pressure of the phantom, the pressure increase is much less, around 196mbar maximum. It must also be waterproof. I will also need an absolute pressure sensor because it will sit inside the pressure chamber so the "outside" reference will be false (it also makes sense for possible implantation of the sensor in a real use-case).

I chose the MS5837.
<figure> <center>
  <img src="./../../img/finalProject/ms5837.jpg" alt="phantomDrawing" width="80%" />
  <figcaption></figcaption>
</figure>
It is communicating through I2C but the address is fixed. I am going to need two of these sensors so I plan to use an I2C multiplexer like the PCA9846.
The other possibilities would include:
- selectively unpower the one we don't want to talk to: also adds additional hardware and is far from perfect.
- having manual jumpers to change the configuration: not suitable for simultaneous acquisition
- having a reprogrammable address would be nice but is not the case

<figure> <center>
  <img src="./../../img/finalProject/ms58372.jpg" alt="phantomDrawing" width="80%" />
  <figcaption>Perfect pressure range</figcaption>
</figure>

It does not seem perfectly waterproof but nothing in stock is waterproof. The pressure is going to be small and it should be able to resist that according to the datasheet.

## The microcontroller: ESP32
I chose to use an ESP32 for multiple reasons. The first being the fact that it is a very high-end microcontroller, with a lot of memory and lot of IOs. It is also capable of Bluetooth and Wifi communication if I ever need them. I can program it using the UART pins.

## Possible improvements
I could add a solenoid valve to handle fast compression in the chamber by filling a pressure tank and releasing it in a short amount of time through the valve. This would allow the simulation of detrusor contractions.

It would also be nice to be able to empty the phantom with a valve after the experiment.

An humidity sensor would be interesting to add, especially in the strain gauge encapsulation.
