int ledPin[] = {5,6, 9, 10};

byte fast = 0;
byte slow = 0;

int mode = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<4; i++){
     pinMode(ledPin[i], OUTPUT);
  }
  
}

void loop() {
// put your main code here, to run repeatedly:
  int a = (slow % 2);
  int b = (slow +1)%2;

  switch (mode){
    case 0:
  digitalWrite(ledPin[0], (fast % 2)* a);
  digitalWrite(ledPin[1], b);
  digitalWrite(ledPin[3], (fast % 2)* b );
  digitalWrite(ledPin[2], a);
  
  break;
  case 1:
  digitalWrite(ledPin[0],  a);
  digitalWrite(ledPin[1], (fast % 2) * b);
  digitalWrite(ledPin[3],  b );
  digitalWrite(ledPin[2], (fast % 2) * a );
  break;
  case 2:
  digitalWrite(ledPin[0],  (fast % 2)* a);
  digitalWrite(ledPin[1], (fast % 2)* b);
  digitalWrite(ledPin[3],  (fast % 2)* b );
  digitalWrite(ledPin[2], (fast % 2) * a );
  break;
  }

  


  fast++;
  fast = fast % 8;
  if (fast == 0){
    slow++;
  }
  if (slow > 8){
    mode ++;
    mode %= 3;
    slow = 0;
  }

  delay(100);



}


