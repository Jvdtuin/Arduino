const int DataPin = 2;
int preValue;
unsigned long time; 
void setup() {
  // put your setup code here, to run once:
  pinMode(DataPin, INPUT);
  Serial.begin(9600);
  preValue = digitalRead(DataPin);
  time = micros();
}



void loop() {
  // put your main code here, to run repeatedly:
  int input= digitalRead(DataPin);
  if (input != preValue)
  {    
    unsigned long t = micros();
    Serial.println(t - time);  
    time = t;
    preValue = input;    
  }

  
}
