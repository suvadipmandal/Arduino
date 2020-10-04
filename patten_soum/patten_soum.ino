void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,0);
delay(10000);
digitalWrite(2,0);
digitalWrite(3,1);
digitalWrite(4,0);
delay(10000);
digitalWrite(2,0);
digitalWrite(3,0);
digitalWrite(4,1);
delay(10000);
}
