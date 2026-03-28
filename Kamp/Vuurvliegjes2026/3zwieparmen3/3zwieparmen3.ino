#include <Servo.h>

Servo servo[3];
const int arm[] = {5,9,A3};

const int red[] = {4,6,A0};
const int green[] = {3,7,A1};
const int blue[] = {2,8,A2};

const int aanUit = 13;

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
 pinMode(aanUit, OUTPUT);
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
  
  digitalWrite(aanUit, HIGH);
  if (hoek>30){
    for (int i =0; i<3; i++){
      aan(i, kleur);
      sweep(i, 0,10, sweeptime);
      uit(i);
    }
  }
  else 
  {
    for (int i=2; i>=0; i--){
      aan(i, kleur);
      sweep(i, 180,0, sweeptime);
      uit(i);
    }
  }
  digitalWrite(aanUit, LOW);
  delay(1000);
}

void sweep(int armIndex, int start, int end, int time){
  servo[armIndex].attach(arm[armIndex]);
  bool richting = start>end;
  servo[armIndex].write(start) ; 
  int delta = end - start;
  int t =0;
  while (t < time){
    int hoek = (delta * t) / time + start;
    servo[armIndex].write(hoek);
    delay(20);
    t +=20;
  }
  servo[armIndex].detach();
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
