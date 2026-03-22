/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  
  // Optional set protocol (default is 1, will work for most outlets)
   mySwitch.setProtocol(6);

  // Optional set pulse length.
   mySwitch.setPulseLength(419);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
  
}

void loop() {



  /* Same switch as above, but using binary code */
  mySwitch.send("0100101011111101100011000001001");
  delay(1000);  
  mySwitch.send("0100101011111101100000000001001");
  delay(1000);
}
