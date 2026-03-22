#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(4000,11,12,10,false);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    const char *msg = "Hello World!";
    digitalWrite(LED_BUILTIN, HIGH);
    driver.send((uint8_t *)msg, strlen(msg));
    digitalWrite(LED_BUILTIN, LOW);
    
    driver.waitPacketSent();
    delay(1000);
}
