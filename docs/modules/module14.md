# 14. Interface and Application Programming

## Objectives

<div class="objectivePanel">
  <ul>
    <li> Group Assignment: Compare as many tools options as possible. </li>
    <li> Write an application that interfaces a user with an input and/or output device that you made.</li>
  </ul>
</div>
<div class="dottedLine"></div>


## Group assignment
Jason and I compared several possibilities when it comes to languages and interfaces on the [group page](http://fab.academany.org/2021/labs/ulb/assignments/week15/).

## Previous design
During last week, I developed my network featuring three boards (one master, two slaves) that can communicate so I can switch on and off the LEDs on the boards using the Serial USB port with the master.
Initially, I only had one slave and one master and I finally added a second slave:

<figure> <center>
  <img src="./../../img/mod13/3nodes.jpg" alt="logo text" width="80%" />
  <figcaption>The 2 slaves and the master together</figcaption>
</figure>

_Making the LEDs subsequently blink_
<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/blink3Nodes.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

<br>

_Commanding the indivual LEDs through the network_
<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod13/command3Nodes.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>


## This week's objective
This week, I intend to develop a Python interface using Kivy to command the LED on each board with this interface. Kivy is an open-source Python framework to develop mainly mobile apps and multitouch application software. I won't really be using these capabilities but it I will learn the basics and if I ever want to develop a mobile application, that will be useful.

Moreover, initially, I wanted to use PyQt but I already know some of it as I used it for other projects so I wanted to try something else !
<figure> <center>
  <img src="./../../img/mod14/pyqt.jpg" alt="logo text" width="80%" />
  <figcaption>A previous project made with PyQt</figcaption>
</figure>

### 1. Talking with the board
First, I needed to have a working Python script that allows me to communicate with my board. For the moment, I type the commands (like b21 to switch on the second led on the slave on address b) directly in the terminal with a Serial connection through Putty or the Arduino IDE.

I installed PySerial (`pip install pyserial`), opened a new serial connection on the right port, with the right baudrate and then, using `serial.write()` I can automate the sending of the commands and light up the LEDs. The code itself is pretty easy but works well.

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod14/blink.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

````
import serial
import sys
import time

LEDs = ['b1','b2','b3', 'c1','c2','c3']
DLY = 0.1

ser = serial.Serial('COM7', 19200, timeout = 0)

if(ser.is_open):
    print("connected")
else:
    print("Serial not connected")
    try:
        ser.close()
    except:
        pass
    sys.exit()


for i in range(len(LEDs)):
    cmd = (LEDs[i]+"0")
    print(cmd)
    ser.write(cmd.encode())
    line = ser.readline()
    print(line)
    ser.flush()
    time.sleep(DLY)

for i in range(len(LEDs)):    
    cmd = (LEDs[i]+"1")
    print(cmd)
    ser.write(cmd.encode())
    line = ser.readline()
    print(line)
    ser.flush()
    time.sleep(DLY)

ser.close()
````

### 2. Installing Kivy and playing with it
To install Kivy, simply use `pip install kivy`. This is a lightweight version and if you need audio and video, you can use `pip install kivy[base.media]`.

When designing a Kivy app, the idea is to:

- sub-classing the App class
- Implement the `build()` method and returns the widget instance
- instantiate the App class and call its `run()` method  

I started by launching some examples from the documentation and I ran into an annoying issue with my Python IDE (Spyder 4.0): Whenever I want to close the window, it freezes and I need to shut down the kernel to make it quit and be able to launch a new instance of my app.

I quickly realized that I was having issues with the built-in Spyder console so I changed the settings in the `run - Configuration per file` options to make this particular script run in an external window. I then added some shebang line to make sure my terminal understands it's a Python3 script.
`#!/usr/bin/env python3`

<figure> <center>
  <img src="./../../img/mod14/config1.jpg" alt="logo text" width="80%" />
  <figcaption>Configuration per file</figcaption>
</figure>

<figure> <center>
  <img src="./../../img/mod14/config2.jpg" alt="logo text" width="80%" />
  <figcaption>External console</figcaption>
</figure>

Now when I close the window, or the terminal, everything closes correctly.

### 3. Kivy basics and Pong tutorial
To learn Kivy basics, I follow the [Pong tutorial](https://kivy.org/doc/stable/tutorials/pong.html) in the documentation. I learned how to create the application, build it, add widgets, play with properties, ...

<figure> <center>
  <img src="./../../img/mod14/pong.jpg" alt="logo text" width="80%" />
  <figcaption>Early pong design</figcaption>
</figure>

_The video presents artifacts but they are due to encoding issues._

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod14/pong.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

### 4. Making my app
To design my app, I played with many more Kivy possibilities and added iteratively new components.
First, I added some buttons and labels in a simple Grid layout. I changed their colors and behaviors on presses and I could detect the presses on the buttons really easily.

````
def on_press(self):
    self.background_color = (0.0, 0.8, 0.0, 1.0)
    print("pressed")
````

But I didn't know which button was pressed really easily by using the buttons object attributes.
````
def callback(instance):
    print('The button <%s> is being pressed' % instance.text)

### in the layout:
btn1 = LEDButtons(text='LED 1')
btn1.bind(on_press=callback)
self.add_widget(btn1)
````
<figure> <center>
  <img src="./../../img/mod14/button1.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

Finally, we can do that for all the buttons to detect which one was pressed.
<figure> <center>
  <img src="./../../img/mod14/button2.jpg" alt="logo text" width="80%" />
  <figcaption></figcaption>
</figure>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod14/interface1.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

Then I added some Serial detection of connection and disconnections and the button to initialize a new connection. The serial connection is refreshed and detected every 66ms. I also started playing around with multiple layouts to make my app more modular.

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod14/interface2.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

Finally, I mixed my PySerial script with the buttons, using dictionaries and arrays to store all the values, added some more layouts and buttons as well as a "spinner" to select the COM port and I was finally happy with my interface. I can now make my LEDs blink in sequence or light every single one on demand. It also detects connections and disconnections.


<figure> <center>
  <img src="./../../img/mod14/finalInterface.jpg" alt="logo text" width="80%" />
  <figcaption>Final interface</figcaption>
</figure>

<video width="700" height="480" autoplay loop>
  <source src="./../../img/mod14/interface3.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

The final code:
````
# #!/usr/bin/env python3
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.boxlayout import BoxLayout
from kivy.graphics import Color, Rectangle, Line
from kivy.core.window import Window
from kivy.clock import Clock
from kivy.uix.spinner import Spinner

### serial USB connection
import serial
import serial.tools.list_ports
import time

COM = "COM7" #Default COM port
LEDs = ['b1','b2','b3', 'c1','c2','c3'] #LEDs list
LEDsStates = [0,0,0,0,0,0]# Current LED states
LEDDict = { #dictionnary to go from LED name to index
    "b1": 0,
    "b2": 1,
    "b3": 2,
    "c1": 3,
    "c2": 4,
    "c3": 5
    }
DLY = 0.1 #Delay between transmissions (s)

def cmdLED(led,param):
    """transmit data to switch on/off an LED"""
    #led = LED name
    #param = 1 (on) or 0 (off)
    cmd = (led+param)
    print(cmd)
    ser.write(cmd.encode())
    line = ser.readline()
    print(line)
    ser.flush() #empty the outgoing buffer
    time.sleep(DLY)

def blinkLEDs(instance=None):
    """Blink all LEDs in sequence"""
    for i in range(len(LEDs)):    
        cmdLED(LEDs[i],'1')
    for i in range(len(LEDs)):
        cmdLED(LEDs[i],'0')

def scanPorts():
    """scan serial ports to find available ones"""
    ports = serial.tools.list_ports.comports()
    portList = []
    for p in ports:
        portList.append(str(p.device))
    return portList

connectionLabel = None
COMSpinner = None
ser = None
portList = scanPorts()
### Connection
try:
    ser = serial.Serial(COM, 19200, timeout = 0.1)
    if(ser.is_open):
        print("connected")
    else:
        print("Serial not connected")
        try:
            ser.close()
        except Exception as e:
            print(e)
except Exception as e:
    print(e)
    ser = None
    # sys.exit()


if(ser):
    #Initialization of LEDs: all off
    for i in range(len(LEDs)):
        cmdLED(LEDs[i],'0')
        LEDsStates[i] = 0
    blinkLEDs() #then blink them


class AppLayout(BoxLayout):
    """main layout"""
    def __init__(self, **kwargs):
        super(AppLayout, self).__init__(**kwargs)

        self.orientation = 'vertical'
        ### Connection Info
        connectLyt = connectLayout(size_hint=(1,0.2))
        self.add_widget(connectLyt)

        ### blink button
        blinkBtn = BlinkButton(text="Blink LEDs",size_hint=(1,0.2))
        self.add_widget(blinkBtn)

        ### LEDs and slaves layout
        slaveLyt = slaveLayout()
        self.add_widget(slaveLyt)


    def checkPortPresence(self):
        """runs at 15Hz, scan ports and detects (dis)connections"""
        global COM, ser
        availablePorts = scanPorts()
        COMSpinner.values = availablePorts
        if(COM not in availablePorts):
            print("Device disconnected")
            connectionLabel.notConnected()
            ser = None
        else:
            connectionLabel.connected()
        if(ser):
            try:
                if(ser.is_open):
                    connectionLabel.connected()
                else:
                    connectionLabel.notConnected()
            except Exception as e:
                print(e)
                connectionLabel.notConnected()
        else:
            connectionLabel.notConnected()


class connectLayout(BoxLayout):
    """layout with COM spinner, connect button and connection label"""
    def __init__(self, **kwargs):
        super(connectLayout, self).__init__(**kwargs)        
        global portList, COMSpinner, connectionLabel
        COMSpinner = Spinner(text="COM ports", values = portList, text_autoupdate = True)
        self.add_widget(COMSpinner)
        reconnectBtn = Button(text="RECONNECT")
        reconnectBtn.bind(on_press=tryReconnect)
        self.add_widget(reconnectBtn)
        connectionLabel = labelConnection(text = "SERIAL CONNECTION")
        self.add_widget(connectionLabel)

class labelConnection(Label):
    """redefines label for connection with connected and not connected states, with corresponding colors"""
    def on_size(self, *args):
        self.canvas.before.clear()
        with self.canvas.before:
            Color(1, 0, 0, 0.8) #background color
            Rectangle(pos=self.pos, size=self.size) ##background
            Color(0,0,0,1) #border color
            Line(width= 1.1, rectangle = (self.x, self.y, self.width, self.height)) #adds a border
        self.bold = True
        self.italic = True
        self.font_size='25sp'

    def connected(self):
        with self.canvas.before:
            Color(0, 0.8, 0, 1) #background color
            Rectangle(pos=self.pos, size=self.size) ##background
            Color(0,0,0,1) #border color
            Line(width= 1.1, rectangle = (self.x, self.y, self.width, self.height)) #adds a border
        self.text = "SERIAL CONNECTED"

    def notConnected(self):
        with self.canvas.before:
            Color(1, 0, 0, 1) #background color
            Rectangle(pos=self.pos, size=self.size) ##background
            Color(0,0,0,1) #border color
            Line(width= 1.1, rectangle = (self.x, self.y, self.width, self.height)) #adds a border
        self.text = "DISCONNECTED"

def tryReconnect(instance):
    global COMSpinner, COM, ser
    port = COMSpinner.text
    COM = port #updates current COM port from the spinner choice
    ### try to connect
    try:
        ser = serial.Serial(port, 19200, timeout = 0.1)
        if(ser.is_open):
            print("connected")
        else:
            print("Serial not connected")
            try:
                ser.close()
            except:
                pass
    except Exception as e:
        print(e)
        ser = None

class slaveLayout(BoxLayout):
    """Layout that places slave layout side by side"""
    def __init__(self, **kwargs):
        super(slaveLayout, self).__init__(**kwargs)

        #Slave1
        slave1 = LEDLayout()
        slave1.add_widget(labelSlave(text = "Slave \"a\" LEDs", size_hint = (1,0.5)))
        slave1.addLEDsButtons("Slave 1 ", "b")
        self.add_widget(slave1)

        #Slave2
        slave2 = LEDLayout()
        slave2.add_widget(labelSlave(text = "Slave \"b\" LEDs", size_hint = (1,0.5)))
        slave2.addLEDsButtons("Slave 2 ", "c")
        self.add_widget(slave2)

class labelSlave(Label):
    def on_size(self, *args):
        self.canvas.before.clear()
        with self.canvas.before:
            Color(51/255, 204/255, 204/255, 1) #background color
            Rectangle(pos=self.pos, size=self.size) ##background
            Color(0,0,0,1) #border color
            Line(width= 1.1, rectangle = (self.x, self.y, self.width, self.height)) #adds a border
        self.bold = True
        self.italic = True
        self.font_size='25sp'       

class LEDLayout(BoxLayout):
    """Layout with LED buttons"""
    def __init__(self, **kwargs):
        super(LEDLayout, self).__init__(**kwargs)
        self.orientation = 'vertical'

    def addLEDsButtons(self, slaveID, customSlaveName):
        btn1 = LEDButtons(text=(slaveID + 'LED 1'))
        btn1.custom = customSlaveName+"1" #used in callback to get slave adress
        btn1.bind(on_press=ledButtonCallback)
        btn2 = LEDButtons(text=(slaveID + 'LED 2'))
        btn2.custom = customSlaveName+"2"
        btn2.bind(on_press=ledButtonCallback)
        btn3 = LEDButtons(text=(slaveID + 'LED 3'))
        btn3.custom = customSlaveName+"3"
        btn3.bind(on_press=ledButtonCallback)
        self.add_widget(btn1)
        self.add_widget(btn2)
        self.add_widget(btn3)

class LEDButtons(Button):
    """redefines the buttons for LEDs with different colors"""
    def on_size(self, *args):
        self.background_color = (0.75,0.75,0.75,1)
    def on_press(self):
        self.background_color = (0.0, 0.8, 0.0, 1.0)
    def on_release(self):
        self.background_color = (0.75,0.75,0.75,1)

def ledButtonCallback(instance):
    btnID = instance.text
    LEDID = instance.custom
    print('The button <%s> is being pressed' % btnID)
    newValue = (not LEDsStates[LEDDict[LEDID]])
    LEDsStates[LEDDict[LEDID]] = newValue
    cmdLED(LEDID, str(int(newValue)))

class BlinkButton(Button):
    """redefines blink button with different color and blink function binding on press"""
    def on_size(self, *args):
        self.background_color = (0.75,0.75,0.75,0.5)
    def on_press(self):
        self.background_color = (0.2, 0.2, 0.6, 0.8)
        blinkLEDs()
    def on_release(self):
        self.background_color = (0.75,0.75,0.75,0.5)



class LEDInterfaceApp(App):
    def build(self):
        app = AppLayout
        Clock.schedule_interval(app.checkPortPresence, 1.0 / 15.0) #15Hz refresh of connected state
        return app()

    def close_application(self):
        # closing application
        App.get_running_app().stop()
        # removing window
        Window.close()
        if(ser):
            ser.close()

if __name__ == '__main__':
    LEDInterfaceApp().run()
````

## My design files
:material-download-box: [My Design files](https://gitlab.fabcloud.org/academany/fabacademy/2021/labs/ulb/students/maxime-verstraeten/-/raw/master/docs/files/mod14.zip)
