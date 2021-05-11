# -*- coding: utf-8 -*-
"""
Created on Mon May 10 13:56:50 2021

@author: Vmaxi
"""

import serial
import sys
import time


LEDs = ['b1','b2','b3', 'c1','c2','c3']
DLY = 0.1

ser = serial.Serial('COM12', 19200, timeout = 0)

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
