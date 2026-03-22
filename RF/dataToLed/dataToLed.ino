
const int reciverPin =2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (reciverPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(reciverPin);
  
  digitalWrite( LED_BUILTIN, data);
 
   
}
