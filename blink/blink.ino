int blue[] = {13,10,7};
int green[] = {12, 9,4};
int red[] = {11, 8, 2};

const int uit = 7;
const int rood = 6;
const int groen = 5;
const int geel = 4;
const int blauw = 3;
const int paars = 2;
const int cyaan = 1;
const int wit = 0;

const int kleur[] ={rood, geel, groen, cyaan, blauw, paars};

void setup(){
  for (int i=0; i<3; i++){
    pinMode(red[i], OUTPUT);
    pinMode(green[i], OUTPUT);
    pinMode(blue[i], OUTPUT);
    setKleur(i, uit);
  }   
}


void loop(){
  for (int i=0; i<6; i++)
    
   for (int j=0; j<3; j++){
     setKleur(j, kleur[i]);
     delay(100);
     setKleur(j, uit);
   }  
}

void setKleur(int led, int kleur){
   digitalWrite(red[led], kleur & 0x1);
   digitalWrite(green[led], (kleur>>1) & 0x1 );
   digitalWrite(blue[led], (kleur>>2)& 01);

}