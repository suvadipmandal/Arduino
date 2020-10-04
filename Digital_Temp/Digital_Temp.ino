#include <LiquidCrystal.h>
LiquidCrystal lcd(2,0,11,10,9,8);

double tempC,tempF;
int val;

void setup() {
  pinMode(OUTPUT,3);
  pinMode(OUTPUT,4);
  pinMode(INPUT,A0);
  analogWrite(3,70);
  lcd.begin(16, 2);
  lcd.print("Temp1=");
  lcd.setCursor(0,1);
  lcd.print("Temp2=");
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
digitalWrite(4,1);
tempC=analogRead(A0);
tempC=(tempC*1100)/(1024*10);
//tempC=map(tempC,0,1024,-50,150);
tempF=((tempC*9)/5)+32;
Serial.println(tempC);
/*
lcd.setCursor(7,0);
lcd.print(tempC,1);
lcd.print(" 'C");

lcd.setCursor(7,1);
lcd.print(tempF,1);
lcd.print(" 'F");
*/
delay(5000);
}
