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