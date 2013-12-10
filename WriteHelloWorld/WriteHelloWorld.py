import serial
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
ser.write("Hello Arduino") 
ser.close()   
