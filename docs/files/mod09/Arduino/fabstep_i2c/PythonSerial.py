import time
import serial

ser = Serial.Serial(COM16, baudrate=115200)
ser.open()
for i in range(10):
    ser.write(b'0:0:80)
    time.sleep(0.85)
    ser.write(b'1:0:80)
    time.sleep(0.85)
    ser.write(b'0:0:0)
    time.sleep(0.85)
    ser.write(b'1:0:0)
    time.sleep(0.85)
    
ser.close()