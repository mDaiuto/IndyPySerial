#include <AFMotor.h>

AF_DCMotor motor(1);
int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
 
  motor.run(RELEASE);
}

void loop() {
     // send data only when you receive data:
     if (Serial.available() > 0) {
           // read the incoming byte:
           incomingByte = Serial.read();
           incomingByte = incomingByte - 48;
           Serial.println(incomingByte);
           if (incomingByte < 5)
           {
              motor.run(BACKWARD);
              motor.setSpeed((5 - incomingByte) * 50);
           }
           if (incomingByte == 5)
           {
              motor.run(RELEASE);
           }
           if (incomingByte > 5)
           {
              motor.run(FORWARD);
              motor.setSpeed((incomingByte - 5) * 50);
           }
     }
}
