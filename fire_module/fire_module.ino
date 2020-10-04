int analogInPin=A1;
int sensorValue=0;

int buzz=9   ;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(analogInPin);
  Serial.print("sensor=");
  Serial.println(sensorValue);
  delay(500);
  if(sensorValue<900)
  {
    digitalWrite(buzz,1 );
  }
  else
  {
    digitalWrite(buzz,0);
  }
}
