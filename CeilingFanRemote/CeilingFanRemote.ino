#include "remote.h"
#include <RCSwitch.h>
#include <NewRemoteReceiver.h>

/*
 Name:		CeilingFanRemote.ino
 Created:	7/1/2021 9:56:14 PM
 Author:	jvdtu

 De plafont ventilator gebruikt protocol 6 (HT6P20B)
*/

RCSwitch mySwitch = RCSwitch();

// the setup function runs once when you press reset or power the board
void setup() 
{
	mySwitch.setProtocol(6);
	mySwitch.enableReceive(0);


}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
