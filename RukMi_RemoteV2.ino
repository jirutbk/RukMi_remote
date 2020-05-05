#include <ESP8266WiFi.h>    //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <WiFiManager.h>     //https://github.com/tzapu/WiFiManager 
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <Ticker.h>
#include "mainPage2.h"
#include "fullPage2.h" 
//#include "TrueHD_raw.h"     //raw ir_dump data
#include "TrueHD.h"

#define led  D0
#define ConfigWiFi_Pin D1         
#define kIrLed  D2 
#define ESP_AP_NAME "RukMi_Remote Config AP"

ESP8266WebServer server(80);
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.
Ticker ticker;

void setup() 
{  
  pinMode(led, OUTPUT);  
  pinMode(ConfigWiFi_Pin,INPUT_PULLUP);    
  ticker.attach(0.6, tick);
  
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
   
  WiFiManager wifiManager;
  if(digitalRead(ConfigWiFi_Pin) == LOW) // Press button
  {
    //reset saved settings
    wifiManager.resetSettings(); // go to ip 192.168.4.1 to config
  }
  wifiManager.setTimeout(300); // กำหนด timeout ของโหมด AP 
  wifiManager.setAPCallback(configModeCallback); // กำหนด callback ของ AP ไปที่ configModeCallback
    
  if (!wifiManager.autoConnect(ESP_AP_NAME)) { 
    Serial.println("failed to connect and hit timeout");
    ESP.reset(); // reset อุปกรณ์
    delay(1000);
  }
  
  ticker.detach();
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(led,LOW);
    
  // เริ่มการทำงานของ Server
  server.on("/", handleRoot); 
  server.on("/fullPage", handleFullPage);
  server.on("/cmd", handleCMD);
  
  server.begin();
  Serial.println("Server started");
}

void sendNumCh(String numCh){ 
  String digit; 
  for(byte i=0;i<(numCh.length());i++)    
  {
    digit = numCh.substring(i,i+1);
    //irsend.sendRaw(num[digit.toInt()], 71, 38); 
    irsend.sendNEC(num[digit.toInt()]); 
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
    delay(250);       
  }
}

void tick() { 
  int state = digitalRead(led); 
  digitalWrite(led, !state); 
}

void configModeCallback (WiFiManager *myWiFiManager) { // callback เมื่อเชื่อม access point ไม่สำเร็จจะเข้าสู่โหมด AP
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
  ticker.attach(0.2, tick); 
}

void handleRoot()  
{
  String page = MAIN_page;  
  server.send(200, "text/html", page); 
}

void handleFullPage()  
{
  String page = FULL_page;  
  server.send(200, "text/html", page); 
}

void handleCMD()  
{
  String cmd = server.arg("cmd");

  if (cmd == "power") {
    irsend.sendNEC(power);  // Send a raw data capture at 38kHz.              
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "source") {
    irsend.sendNEC(source);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }  
  else if (cmd == "mute") {
    irsend.sendNEC(mute);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  } 
  else if (cmd == "soundInc") {
    irsend.sendNEC(soundInc);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  } 
  else if (cmd == "soundDec") {
    irsend.sendNEC(soundDec);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "chInc") {
    irsend.sendNEC(chInc);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "chDec") {
    irsend.sendNEC(chDec);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "info") {
    irsend.sendNEC(binfo);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "exit") {
    irsend.sendNEC(bexit);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "ok") {
    irsend.sendNEC(ok);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "menu") {
    irsend.sendNEC(menu);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "up") {
    irsend.sendNEC(up);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "down") {
    irsend.sendNEC(down);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "left") {
    irsend.sendNEC(left);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "right") {
    irsend.sendNEC(right);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "ch") { //ถ้ากดเลขช่อง 
    String chanel =  server.arg("num");     //ตัดเลขช่องรายการ      
    sendNumCh(chanel);  
  }
  
  server.send(200, "text/html", "OK"); 
}

void loop() 
{  
  server.handleClient(); 

}
