int sensorValue=0;
int spk=11;
int analogInput=A0;
void setup() 
{
  pinMode(spk,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  sensorValue=analogRead(analogInput);
  Serial.println(sensorValue);
  if(sensorValue>700)
  {
  tone(spk, 800, 100);
  }
  else
  {
    noTone(spk);
  }
}
