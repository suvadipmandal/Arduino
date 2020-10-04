#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

const char *ssid="Suvadip_WIFI";
const char *password="Suv@dip7679";
const char *ssidExt="Laxmi_Auto";
const char *passwordExt="none";

IPAddress apIP(192,168,4,1);
byte DNS_PORT =53;

WiFiUDP Udp;
byte packetBuffer[512];

WiFiUDP Udp8;

IPAddress ip(192,168,0,13);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_AP_STA);

  Serial.println("!!!!!!!!");
  WiFi.begin(ssidExt,passwordExt);
  WiFi.config(ip, gateway, subnet);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssidExt);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("dnsIP address: ");
  Serial.println(WiFi.dnsIP());
  Serial.print("gatewayIP address: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("subnetMask address: ");
  Serial.println(WiFi.subnetMask());

  Serial.println("");
  Serial.println("Configuring access point...");
  WiFi.softAP(ssid,password);

  IPAddress myIP= WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Udp.begin(DNS_PORT);
  Udp8.begin(DNS_PORT);
}

void loop() {
  int noBytes = Udp.parsePacket();
  if(noBytes){
    Udp.read(packetBuffer, noBytes);
    IPAddress ip8(8,8,8,8);
    Udp8.beginPacket(ip8,DNS_PORT);
    Udp8.write(packetBuffer, noBytes);
    Udp8.endPacket();
    delay(100);

    int cb = Udp8.parsePacket();
    if(!cb){
      Serial.println("no packet yet");
    }
    else{
      byte packetBuffer8[cb];
      Udp8.read(packetBuffer8,cb);
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(packetBuffer8,cb);
      Udp.endPacket();
    }
  }
}
