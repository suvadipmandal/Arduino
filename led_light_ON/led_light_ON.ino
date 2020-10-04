
int time=1500; //wating time
void setup() {
  // put your setup code here, to run once:
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(20,OUTPUT);
  
  
  digitalWrite(1,0);
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(7,0);
  digitalWrite(9,0);
  digitalWrite(11,0);
  digitalWrite(13,0);
  digitalWrite(15,0);
  digitalWrite(17,0);
  digitalWrite(19,0);
}

void loop() {
  //white LED
  digitalWrite(2,1);
  digitalWrite(6,1);
  digitalWrite(10,1);
  digitalWrite(16,1);
  delay(time);
  digitalWrite(2,0);
  digitalWrite(6,0);
  digitalWrite(10,0);
  digitalWrite(16,0);

  //BLUE LED
  digitalWrite(0,1);
  digitalWrite(4,1);
  digitalWrite(8,1);
  delay(time);
  digitalWrite(0,0);
  digitalWrite(4,0);
  digitalWrite(8,0);

  //RED LED
  digitalWrite(12,1);
  digitalWrite(14,1);
  digitalWrite(18,1);
  delay(time);
  digitalWrite(12,0);
  digitalWrite(14,0);
  digitalWrite(18,0);
}
