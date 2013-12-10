import serial

while True:
    a = raw_input("Motor speed (1-9, 5=STOP): ")
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
    ser.write(str(a))
    ser.close()

