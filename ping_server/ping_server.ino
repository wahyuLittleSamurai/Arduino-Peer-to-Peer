#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

char data[32];
void setup(){
  Serial.begin(115200);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"1111");
  Mirf.payload = 32;
  Mirf.channel = 99;
  Mirf.config();
  
  Serial.println("Listening..."); 
}

void loop(){
  if(!Mirf.isSending() && Mirf.dataReady()){
    Serial.println("Got packet");
     
    Mirf.getData((byte *)&data);
    
    Serial.println(data);
     
    Mirf.setTADDR((byte *)"2222");
    
    Mirf.send((byte *)data);
    
    Serial.println("Reply sent.");
  }
}
