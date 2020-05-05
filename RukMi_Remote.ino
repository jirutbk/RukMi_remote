#include <ESP8266WiFi.h>    //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <WiFiManager.h>     //https://github.com/tzapu/WiFiManager 
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <Ticker.h>
#include "mainPage.h"       //HTML webpage contents with javascripts
#include "fullPage.h" 
#include "TrueHD_raw.h"     //raw ir_dump data

#define led  D0
#define ConfigWiFi_Pin D1         
#define kIrLed  D2 
#define ESP_AP_NAME "RukMi_Remote Config AP"

WiFiServer server(80);
String header;
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
  server.begin();
  Serial.println("Server started");
}

void sendNumCh(String numCh){ 
  String digit; 
  for(byte i=0;i<(numCh.length()-1);i++)    
  {
    digit = numCh.substring(i,i+1);
    irsend.sendRaw(num[digit.toInt()], 71, 38);  
    digitalWrite(led, HIGH);
    delay(60);
    digitalWrite(led, LOW);
    delay(500);       
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

void loop() 
{  
  // รอ Client มาเชื่อมต่อ
  WiFiClient client = server.available(); 

  // ถ้ามี Client ใหม่มาเชื่อมต่อ
  if (client) {
    Serial.println("New Client."); 
    String currentLine = ""; 

    // เช็คสถานะว่า Cient ยังเชื่อมต่ออยู่หรือไม่
    while (client.connected())
    { 
      if (client.available())
      { 
        char c = client.read(); 
        Serial.write(c); // 
        header += c;

        if (c == '\n') 
        {
          // ถ้าไม่มีข้อมูลเข้ามาแสดงว่า Client ตัดการเชื่อมต่อไปแล้ว 
          if (currentLine.length() == 0) 
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // ชุดคำสั่งในการเปิด-ปิด LED
            if (header.indexOf("GET /power") >= 0) {
              irsend.sendRaw(power, 67, 38);  // Send a raw data capture at 38kHz.              
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /source") >= 0) {
              irsend.sendRaw(source, 71, 38);               
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }  
            else if (header.indexOf("GET /mute") >= 0) {
              irsend.sendRaw(mute, 67, 38);               
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            } 
            else if (header.indexOf("GET /sound/inc") >= 0) {
              irsend.sendRaw(soundInc, 71, 38);               
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            } 
            else if (header.indexOf("GET /sound/dec") >= 0) {
              irsend.sendRaw(soundDec, 67, 38);                
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/inc") >= 0) {
              irsend.sendRaw(chInc, 71, 38);                
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/dec") >= 0) {
              irsend.sendRaw(chDec, 71, 38);                
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /info") >= 0) {
              irsend.sendRaw(binfo, 71, 38);                
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /exit") >= 0) {
              irsend.sendRaw(bexit, 71, 38);                
              digitalWrite(led, HIGH);
              delay(60);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/") >= 0) { //ถ้ากดเลขช่อง 
              String chanel =  header.substring(header.indexOf("GET /ch/")+8, header.indexOf("HTTP/1.1"));     //ตัดเลขช่องรายการ      
              sendNumCh(chanel);  
            }

            // ส่วนโค้ดแสดงหน้าเว็บที่ส่งไปให้ Client แสดง
            String page;
            if (header.indexOf("GET /fullPage") >= 0) 
              page = FULL_page;           
            else 
              page = MAIN_page;         
            client.println(page);
           
            // ส่วนตอนปิดการทำงาน
            client.println(); 
            client.stop(); //หยุดการเชื่อมต่อ         
            break;
          } 
          else currentLine = "";
        }
        else if (c != '\r') 
        {  
          currentLine += c;      
        }
      }
    }
    // เคลียร์ส่วน Header
    header = "";

    // ตัดการเชื่อมต่อ
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
