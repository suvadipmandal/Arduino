#include <IRremote.h>

int RECV_PIN = A2,flag=5,sw1=0,sw2=0,sw3=0,sw4=0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(9,0);
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(7,0);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if(results.value==3191976015 || results.value==50153655)
    {
      digitalWrite(8,0);
      digitalWrite(2,0);
      digitalWrite(4,0);
      digitalWrite(6,0);
    }
    else if(results.value==3191963775 || results.value==50167935)
    {
     if(sw1==0)
      {
        digitalWrite(2,1);
        sw1=1;
      }
      else
      {
        digitalWrite(2,0);
        sw1=0;
      }
    }
    else if(results.value==3191947455 || results.value==50151615)
    {
     if(sw2==0)
      {
        digitalWrite(4,1);
        sw2=1;
      }
      else
      {
        digitalWrite(4,0);
        sw2=0;
      }
    }
    else if(results.value==3191980095 || results.value==50184255)
    {
      if(sw3==0)
      {
        digitalWrite(6,1);
        sw3=1;
      }
      else
      {
        digitalWrite(6,0);
        sw3=0;
      } 
    }
    else if(results.value==3191939295 || results.value==50143455)
    {
     if(sw4==0)
      {
        digitalWrite(8,1);
        sw4=1;
      }
      else
      {
        digitalWrite(8,0);
        sw4=0;
      }
    }
    irrecv.resume(); // Receive the next value
  }

  delay(100);
}
