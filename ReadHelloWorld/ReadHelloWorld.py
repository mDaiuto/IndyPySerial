import serial

while True:
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
    ser.flushInput()
    s = ser.readLine()
    ser.close()
    print s
