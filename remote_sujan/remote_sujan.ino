
#include "IRremote.h"

int receiver =4,sw1=0,sw2=0,sw3=0; 
IRrecv irrecv(receiver);           
decode_results results;            

#include <TimerOne.h>           
volatile int i=0;               // Variable to use as a counter
volatile boolean zero_cross=0;  // Boolean to store a "switch" to tell us if we have crossed zero
int AC_pin = 5;                 // Output to Opto Triac

int dim2 = 0;                   // led control
int dim = 128;                  // Dimming level (0-128)  0 = on, 128 = 0ff                  
int freqStep = 75;    // This is the delay-per-brightness step in microseconds.

void setup() {  
  Serial.begin(9600); 
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the IR receiver (classic remote)
  Serial.println("Enabled IRin");
  pinMode(AC_pin, OUTPUT);                          // Set the Triac pin as output
  attachInterrupt(0, zero_cross_detect, RISING);    // Attach an Interupt to Pin 2 (interupt 0) for Zero Cross Detection
  Timer1.initialize(freqStep);                      // Initialize TimerOne library for the freq we need
  Timer1.attachInterrupt(dim_check, freqStep);      
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
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
  Serial.println(results.value);
  switch(results.value)
  {
  
  case 33448095:  
    {
   Serial.println("UP");
    if (dim<127)  
   {
    dim = dim + 8;
    if (dim>127) 
    {
      dim=128; // in vechiul sketch era 127
    }
    }}
    break;

  case 33464415:  
    {
    Serial.println("down");
      {
  if (dim>5)  
  {
     dim = dim - 8;
  if (dim<0) 
    {
      dim=0;  // in vechiul sketch era 1
    } }}}
    break;
    
    case 33444015:
    {
      if(sw1==0)
      {
        digitalWrite(6,1);
        sw1=1;
      }
      else
      {
        digitalWrite(6,0);
        sw1=0;
      }
    }
    break;

    case 33478695:
    {
      if(sw2==0)
      {
        digitalWrite(7,1);
        sw2=1;
      }
      else
      {
        digitalWrite(7,0);
        sw2=0;
      }
    }
    break;

    case 33486855:
    {
      if(sw3==0)
      {
        digitalWrite(8,1);
        sw3=1;
      }
      else
      {
        digitalWrite(8,0);
        sw3=0;
      } 
    }
    break;
  }
  }
  
void loop() {  
 if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  

}
