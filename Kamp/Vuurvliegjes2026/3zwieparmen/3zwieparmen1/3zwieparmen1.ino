#include <Servo.h>

Servo servo[3];
int arm[] = {3,5,6};

int red[] = {2,8,11};
int green[] = {4,9,12};
int blue[] = {7,10,13};

const int rood = 6;
const int geel = 4;
const int groen = 5;
const int cyaan = 1;
const int blauw = 3;
const int paars = 2;
const int wit = 0;
const int sweeptime = 900;

int kleur =0;
int hoek =0;
int hoekDelta = 180;


void setup() {
  // put your setup code here, to run once:
 // arm1.attach(3);
 for(int i=0; i<3; i++){
    pinMode(red[i], OUTPUT);
    pinMode(green[i], OUTPUT);
    pinMode(blue[i],OUTPUT);
 }
 pinMode(A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  kleur++;
  hoek+=hoekDelta;
  if (hoek>150 || hoek<30)
  {
    hoekDelta = -hoekDelta;
  }
  if (kleur > 6 ) { 
    kleur = 0;
    
    }
  
  digitalWrite(A0, HIGH);
  if (hoek>30){
  for (int i =0; i<3; i++){
    servo[i].attach(arm[i]);
    aan(i, kleur);
    servo[i].write(hoek) ;
    delay(sweeptime);
    uit(i);
    servo[i].detach();
  }
  }
  else 
  {
    for (int i=2; i>=0; i--){
      servo[i].attach(arm[i]);
      aan(i,kleur);
          servo[i].write(hoek) ;
          delay(sweeptime);
          uit(i);
          servo[i].detach();
    }
  }
  digitalWrite(A0, LOW);
  delay(1000);
}


void uit(int i){
  digitalWrite(red[i], HIGH);
  digitalWrite(green[i], HIGH);
  digitalWrite(blue[i], HIGH);  
}

void aan(int i, int kleur){
  digitalWrite(red[i], (kleur & 1)==1?HIGH:LOW);
  digitalWrite(green[i], (kleur & 2)==2?HIGH:LOW);
  digitalWrite(blue[i], (kleur & 4)==4?HIGH:LOW);
}
