#include "ESP8266WiFi.h" 
const int RSSI_MAX =-50; // define maximum strength of signal in dBm 
const int RSSI_MIN =-100;// define minimum strength of signal in dBm 

int count =0; 
int scanDelayTime = 1000; 
int wiFiDisplayTime = 3000; 
void setup() {   // Set WiFi to station mode and 
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect();
  Serial.begin(115200);
  //disconnect from an AP if it was previously connected 
  Serial.println("ESP8266"); 
  delay(2000); 
  Serial.println("Wifi Scan Demo"); 
  delay(2000); 
  scan();
} 
void loop() { 
scan();
  delay(scanDelayTime);
}
void scan()
{
  int n = WiFi.scanNetworks(); 
  Serial.println("scan done"); 
  if (n == 0) 
  { 
    Serial.println("No WiFI found");
  }
  else {
  Serial.print(n);
  Serial.println( " AP found");
  for (int i = 0; i < n; ++i)
   {
      // Print SSID and RSSI for each network found 
      Serial.print(i+1);
      Serial.print(") ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal: ");
      Serial.print(dBmtoPercentage(WiFi.RSSI(i)));
      Serial.println("%\n\n\n");
      delay(wiFiDisplayTime);
    } 
  }
}
int dBmtoPercentage(int dBm) 
 { 
 int quality; 
 if(dBm <= RSSI_MIN) 
 { 
  quality = 0;
 } 
 else if(dBm >= RSSI_MAX) 
 {
   quality = 100;
 } else 
 { 
  quality = 2 * (dBm + 100); 
 }   
 return quality;
}
