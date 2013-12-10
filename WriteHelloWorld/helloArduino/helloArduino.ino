void setup (){
  Serial.begin(9600);
  Serial.flush();
  digitalWrite (13, HIGH);      //turn on debugging LED
}

void loop (){

  int i=0;
  char commandbuffer[100];

  if(Serial.available()){
     delay(100);
     while( Serial.available() && i< 99) {
        commandbuffer[i++] = Serial.read();
     }
     commandbuffer[i++]='\0';
  }

  if(i>0)
     Serial.println((char*)commandbuffer);

}
