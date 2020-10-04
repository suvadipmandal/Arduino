/* * Display WiFi Access Point Signal Strength on LCD1602-I2C as dBm or Percentage with ESP8266 Arduino 
* Written by Ahmad Shamshiri on Aug 12, 2019 * in Ajax, Ontario, Canada * for Robojax.com * Watch video
instruction for this code: https://youtu.be/HYMnCUtNMnw * Get this code and other Arduino codes from 
Robojax.com Learn Arduino step by step in structured course with all material, wiring diagram and library
all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62 If you found this tutorial
helpful, please support me so I can continue creating content like this. You can support me on Patreon
http://robojax.com/L/?id=63 or make donation using PayPal http://robojax.com/L/?id=64 */ 
#include "ESP8266WiFi.h" 
const int RSSI_MAX =-50; // define maximum strength of signal in dBm 
const int RSSI_MIN =-100;// define minimum strength of signal in dBm 
// start of settings for LCD1602 with I2C 
#include <LiquidCrystal_I2C.h> // Set the LCD address to 0x27 for a 16 chars and 2 line display 
LiquidCrystal_I2C lcd(0x38); // end of settings for LCD1602 with I2C 
int count =0; 
int scanDelayTime = 1000; 
int wiFiDisplayTime = 3000; 
void setup() {   // Set WiFi to station mode and 
  WiFi.mode(WIFI_STA); 
  WiFi.disconnect();
  //disconnect from an AP if it was previously connected 
  lcd.home(); 
  lcd.backlight(); 
  lcd.print("Robojax ESP8266"); 
  lcd.setCursor(0,1); 
  lcd.print("Wifi Scan Demo"); 
  delay(2000); 
  } 
  void loop() { 
    // Robojax D1 Mini LCD-1602-I2C WiFi Scan 
    // WiFi.scanNetworks will return the number of networks found 
    int n = WiFi.scanNetworks(); 
    lcd.clear();
    // clear previous values from screen 
    lcd.print("scan done"); 
    if (n == 0) 
    { 
      lcd.print("No WiFI found");
    }
    else {
        lcd.setCursor(0,1);
        lcd.print(n);
        lcd.print( " AP found");
        for (int i = 0; i < n; ++i)
        {
          // Print SSID and RSSI for each network found 
          lcd.clear();
          // clear previous values from screen 
          lcd.setCursor(0,0);
          lcd.print(i+1);
          lcd.print(") ");
          lcd.print(WiFi.SSID(i));
          lcd.setCursor(0,1);
          lcd.print("Signal: ");
          lcd.print(dBmtoPercentage(WiFi.RSSI(i)));
          lcd.print("%");
          delay(wiFiDisplayTime);
          } 
         }
          delay(scanDelayTime);
        }
          // loop end 
          /* * Written by Ahmad Shamshiri * with lots of research, this sources was used: 
          * https://support.randomsolutions.nl/827069-Best-dBm-Values-for-Wifi * This is 
          approximate percentage calculation of RSSI * Wifi Signal Strength Calculation 
          * Written Aug 08, 2019 at 21:45 in Ajax, Ontario, Canada */ 
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
}//dBmtoPercentage
