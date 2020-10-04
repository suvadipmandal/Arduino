/*

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 0, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  // set up the LCD's number of columns and rows:
  pinMode(A2,OUTPUT);
  digitalWrite(A2,1);
  pinMode(A5,OUTPUT);
  digitalWrite(A5,0);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(3,OUTPUT);
  analogWrite(3,70);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Object Distance");
}

void loop() {
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  digitalWrite(A3,0);
  digitalWrite(A3,1);
  digitalWrite(A3,0); 
  int time=pulseIn(A4,HIGH); 
  time=time/2; //time in microsecond
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print((time)/29.1);
  lcd.print("  cm");
}
