int sensorValue=0;

void setup() {
  // put your setup code here, to run once:
pinMode(A5,OUTPUT); //ground connection
pinMode(A4,OUTPUT); //Sensor Vcc connection
pinMode(A3,INPUT);  //Sensor Value Input
pinMode(A2,OUTPUT); //Speaker Out
pinMode(A1,OUTPUT); //LED out
digitalWrite(A5,0);
digitalWrite(A4,1);
Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  sensorValue=digitalRead(A3);
  
if(digitalRead(A3)==HIGH)
{
alart();
}
else
{
  digitalWrite(A2,LOW);
}
sensorValue=0;
Serial.println(sensorValue);
delay(1000);
}

void alart()
{

digitalWrite(A1,LOW);
digitalWrite(A2,HIGH);
delay(200);
digitalWrite(A1,HIGH);
digitalWrite(A2,LOW);
delay(200);

}
