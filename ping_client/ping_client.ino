#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

char data[32];
void setup(){
  Serial.begin(115200);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"2222");
  Mirf.payload = 32;
  Mirf.channel = 99;
  Mirf.config();
  
  Serial.println("Beginning ... "); 
}

void loop(){

  int dataAnalog = analogRead(A0);
  sprintf(data,"%4d",dataAnalog);
  
  Mirf.setTADDR((byte *)"1111");
  
  Mirf.send((byte *)&data);
  
  while(Mirf.isSending()){
  }
  Serial.println("Finished sending");
  Serial.println(data);
  delay(10);
 
  Mirf.getData((byte *) &data);
  
  Serial.print("Ping: ");
  Serial.println(data);
  
  delay(1000);
} 
  
  
  
