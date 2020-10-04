
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid="Laxmi_Auto";
const char *password="none";
const char *myssid = "Suvadip_WIFI";
const char *mypassword = "Suv@dip7679";

ESP8266WebServer server(80);

IPAddress ip(192,168,11,4);
IPAddress gateway(192,168,11,1);
IPAddress subnet(255,255,255,0);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected now</h1>");
}

void setup() {
  delay(1000);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(myssid, mypassword);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
