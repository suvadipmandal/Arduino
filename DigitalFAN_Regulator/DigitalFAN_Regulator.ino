#include <TimerOne.h>           
volatile int i=0;               // Variable to use as a counter
volatile boolean zero_cross=0;  // Boolean to store a "switch" to tell us if we have crossed zero
int AC_pin = 5;

int dim2 = 0;                   // led control
int dim = 128;                  // Dimming level (0-128)  0 = on, 128 = 0ff                  
int freqStep = 75;    // This is the delay-per-brightness step in microseconds.
int buttonchk=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(AC_pin, OUTPUT);                          // Set the Triac pin as output
  pinMode(10, INPUT); 
  pinMode(11, INPUT); 
  attachInterrupt(0, zero_cross_detect, RISING);    // Attach an Interupt to Pin 2 (interupt 0) for Zero Cross Detection
  Timer1.initialize(freqStep);                      // Initialize TimerOne library for the freq we need
  Timer1.attachInterrupt(dim_check, freqStep);  
}

void zero_cross_detect() 
{    
  zero_cross = true;               // set the boolean to true to tell our dimming function that a zero cross has occured
  i=0;
  digitalWrite(AC_pin, LOW);
}                                 
// Turn on the TRIAC at the appropriate time
void dim_check() 
{                   
  if(zero_cross == true) {              
    if(i>=dim) {                     
      digitalWrite(AC_pin, HIGH);  // turn on light       
      i=0;  // reset time step counter                         
      zero_cross=false;    // reset zero cross detection
    } 
    else {
      i++;  // increment time step counter                     
}}} 

void translateIR() // takes action based on IR code received
{
  switch(buttonchk)
  {
  case 1:  
    {
   
    if (dim<127)  
   {
    dim = dim + 8;
    if (dim>127) 
    {
      dim=128; // in vechiul sketch era 127
    }
    delay(100);
    buttonchk=0;
    }}
    
    break;

  case 2:  
    {
    
      {
  if (dim>5)  
  {
     dim = dim - 8;
  if (dim<0) 
    {
      dim=0;  // in vechiul sketch era 1
    } }}
    delay(100);
    buttonchk=0;
    }
    break;
  }}
  
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(10)==HIGH)
  {
    buttonchk=1;
  }
  if(digitalRead(11)==HIGH)
  {
    buttonchk=2;
  }
translateIR(); 
}
