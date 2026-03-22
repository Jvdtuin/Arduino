#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(4000, 2, 12, 10, false);

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init()){
      Serial.println("init failed");
    }
    else{
      Serial.println("init success");
    }  
    pinMode(11,INPUT);    
}

void loop()
{
    uint8_t buf[25];
    uint8_t buflen = sizeof(buf);

    
   if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
 // Message with a good checksum received, dump it.
    Serial.print(buflen);
     Serial.print("Message: ");
Serial.println((char*)buf);         
    }    
}
