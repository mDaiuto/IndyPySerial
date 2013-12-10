
#include <VirtualWire.h>
char buff[8][50];
int sensorValue = 0;
void setup() {
  //Serial.begin(9600);
  vw_set_ptt_inverted(true);  // Required by the RF module
  vw_setup(2000);            // bps connection speed
  vw_set_tx_pin(3);         // Arduino pin to connect the receiver data pin
}

void loop() {
  char *msg = " ";
  sensorValue = analogRead(A3);
  if (sensorValue > 1021)
  {
      msg = "Board is tilted";
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx();
  }
  else
  {
      msg = "Board is not tilted";
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx();
  }
  sensorValue = analogRead(A4);
  if (sensorValue > 1018)
  {
      msg = "Room is lit";
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx();
  }
  else
  {
      msg = "Room is not lit";
      vw_send((uint8_t *)msg, strlen(msg));
      vw_wait_tx();
  }
  
  delay(2000);
}
