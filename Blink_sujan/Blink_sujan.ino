
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, HIGH); 
  digitalWrite(8, HIGH); 
  delay(1000);                       // wait for a second
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW); 
  delay(1000);                       // wait for a second
}
