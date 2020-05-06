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
//#include "SonyTV.h"
String code = "NEC";  //SONY, NEC

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
    if(code == "NEC") 
      irsend.sendNEC(num[digit.toInt()]);
    else if(code == "SONY")     
      irsend.sendSony(num[digit.toInt()], 12, 2);   //12 bits &  repeats 2 time
    //irsend.sendRaw(num[digit.toInt()], 71, 38); // Send a raw data capture at 38kHz.       
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

void handleRoot(){  
  server.send(200, "text/html", MAIN_page); 
}

void handleFullPage(){    
  server.send(200, "text/html", FULL_page); 
}

void handleCMD()  
{
  String cmd = server.arg("cmd");

  if (cmd == "power") {
    if(code == "NEC")
      irsend.sendNEC(power);      
    else if(code == "SONY")
      irsend.sendSony(power,12,2);      
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "source") {
    if(code == "NEC")
      irsend.sendNEC(source);      
    else if(code == "SONY")
      irsend.sendSony(source,12,2);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }  
  else if (cmd == "mute") {
    if(code == "NEC")
      irsend.sendNEC(mute);      
    else if(code == "SONY")
      irsend.sendSony(mute,12,2);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  } 
  else if (cmd == "soundInc") {
    if(code == "NEC")
      irsend.sendNEC(soundInc);      
    else if(code == "SONY")
      irsend.sendSony(soundInc,12,2);               
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  } 
  else if (cmd == "soundDec") {
    if(code == "NEC")
      irsend.sendNEC(soundDec);      
    else if(code == "SONY")
      irsend.sendSony(soundDec,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "chInc") {
    if(code == "NEC")
      irsend.sendNEC(chInc);      
    else if(code == "SONY")
      irsend.sendSony(chInc,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "chDec") {
    if(code == "NEC")
      irsend.sendNEC(chDec);      
    else if(code == "SONY")
      irsend.sendSony(chDec,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "info") {
    if(code == "NEC")
      irsend.sendNEC(binfo);      
    else if(code == "SONY")
      irsend.sendSony(binfo,15,2);  // ใช้เป็นปุ่ม stretch              
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "exit") {
    if(code == "NEC")
      irsend.sendNEC(bexit);      
    else if(code == "SONY")
      irsend.sendSony(bexit,15,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "ok") {
    if(code == "NEC")
      irsend.sendNEC(ok);      
    else if(code == "SONY")
      irsend.sendSony(ok,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "menu") {
    if(code == "NEC")
      irsend.sendNEC(menu);      
    else if(code == "SONY")
      irsend.sendSony(menu,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "up") {
    if(code == "NEC")
      irsend.sendNEC(up);      
    else if(code == "SONY")
      irsend.sendSony(up,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "down") {
    if(code == "NEC")
      irsend.sendNEC(down);      
    else if(code == "SONY")
      irsend.sendSony(down,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "left") {
    if(code == "NEC")
      irsend.sendNEC(left);      
    else if(code == "SONY")
      irsend.sendSony(left,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
    else if (cmd == "right") {
    if(code == "NEC")
      irsend.sendNEC(right);      
    else if(code == "SONY")
      irsend.sendSony(right,12,2);                
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
  }
  else if (cmd == "ch") { //ถ้ากดเลขช่อง           
    sendNumCh(server.arg("num"));  
  }
  
  server.send(200, "text/html", "OK"); 
}

void loop() {  
  server.handleClient(); 

}
