#include <ESP8266WiFi.h>    //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>     //https://github.com/tzapu/WiFiManager 
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define led  D0
#define ConfigWiFi_Pin D1         
#define kIrLed  D2 
#define ESP_AP_NAME "RukMi_Remote Config AP"

WiFiServer server(80);
String header;
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

// Data captured by IRrecvDumpV2.ino
uint16_t power[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t source[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};                       
uint16_t mute[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t soundInc[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t soundDec[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};                   
uint16_t chInc[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600}; 
uint16_t chDec[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
                         
uint16_t num[][67] = {{9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600},
                        {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600}}; 
                        /**  
uint16_t num2[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t num3[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t num4[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};  
uint16_t num5[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};   
uint16_t num6[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t num7[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t num8[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
uint16_t num9[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};                                            
**/
void setup() 
{  
  pinMode(led, OUTPUT);  
  pinMode(ConfigWiFi_Pin,INPUT_PULLUP);  
  digitalWrite(led,LOW);
  
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  if(digitalRead(ConfigWiFi_Pin) == LOW) // Press button
  {
    //reset saved settings
    wifiManager.resetSettings(); // go to ip 192.168.4.1 to config
  }
  //fetches ssid and password from EEPROM and tries to connect
  //if it does not connect, it starts an access point with the specified name
  //and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect(ESP_AP_NAME); 
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(250);
     Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
    
  // เริ่มการทำงานของ Server
  server.begin();
  Serial.println("Server started");
}

void sendNumCh(String numCh){ 
  String digit; 
  for(byte i=0;i<(numCh.length()-1);i++)    
  {
    digit = numCh.substring(i,i+1);
    irsend.sendRaw(num[digit.toInt()], 67, 38);  
    delay(200);        
  }
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
    while (client.connected()) { 
      if (client.available()) { 
        char c = client.read(); 
        Serial.write(c); // 
        header += c;

        if (c == '\n') {
          // ถ้าไม่มีข้อมูลเข้ามาแสดงว่า Client ตัดการเชื่อมต่อไปแล้ว 
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // ชุดคำสั่งในการเปิด-ปิด LED
            if (header.indexOf("GET /power") >= 0) {
              irsend.sendRaw(power, 67, 38);  // Send a raw data capture at 38kHz.              
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /source") >= 0) {
              irsend.sendRaw(mute, 67, 38);               
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            }  
            else if (header.indexOf("GET /mute") >= 0) {
              irsend.sendRaw(mute, 67, 38);               
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            } 
            else if (header.indexOf("GET /sound/inc") >= 0) {
              irsend.sendRaw(soundInc, 67, 38);               
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            } 
            else if (header.indexOf("GET /sound/dec") >= 0) {
              irsend.sendRaw(soundDec, 67, 38);                
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/inc") >= 0) {
              irsend.sendRaw(chInc, 67, 38);                
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/dec") >= 0) {
              irsend.sendRaw(chDec, 67, 38);                
              digitalWrite(led, HIGH);
              delay(100);
              digitalWrite(led, LOW);
            }
            else if (header.indexOf("GET /ch/") >= 0) { //ถ้ากดเลขช่อง 
              String chanel =  header.substring(header.indexOf("GET /ch/")+8, header.indexOf("HTTP/1.1"));     //ตัดเลขช่องรายการ      
              sendNumCh(chanel);                
              digitalWrite(led, HIGH);
              delay(50);
              digitalWrite(led, LOW);
              delay(20);
              digitalWrite(led, HIGH);
              delay(50);
              digitalWrite(led, LOW);
            }

            // ส่วนโค้ดแสดงหน้าเว็บที่ส่งไปให้ Client แสดง
            client.println("<!DOCTYPE html><html><head><meta charset='utf-8'><meta name='viewport' content='width=device-width, initial-scale=1'><link rel='icon' href='data:,'>");
            client.println("<style>html{ font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}  .button { background-color: #4CAF50; border: none; color: white; padding: 10px 20px; text-decoration: none; font-size: 23px; margin: 2px; cursor: pointer;}");
            client.println(".buttonCh {background-color: rgb(248, 199, 36); width:150px;border-radius: 12px;} .buttonR{border-radius: 12px;}  .buttonC{border-radius: 50px;}  .buttonBlue {background-color: #008CBA;}  .buttonRed {background-color: #f44336;}  .buttonGreen {background-color: #4CAF50;}</style>");
            client.println("</head><body><h1>RukMi remote V 1.0</h1><table align='center'><tr><td colspan=2 width=170><a href='/power'><button class='button buttonC buttonRed'>Power</button></a></td><td width=50>&nbsp;</td><td colspan=2 width=170><a href='/source'><button class='button buttonC '>เสา/จาน</button></a></td>");
            client.println("</tr><tr><td colspan=5>&nbsp;</td></tr><tr><td>&nbsp;</td><td align='right'><a href='/ch/inc'><button class='button buttonR buttonBlue' style='width:60px'>+</button></a></td><td>&nbsp;</td><td align='left'><a href='/sound/inc'><button class='button buttonR buttonBlue' style='width:60px'>+</button></a></td>");
            client.println("<td>&nbsp;</td></tr><tr><td colspan=5>&nbsp;</td></tr><tr><td>&nbsp;</td><td align='right'><a href='/ch/dec'><button class='button buttonR buttonBlue' style='width:60px'>-</button></a></td><td>&nbsp;</td><td align='left'><a href='/sound/dec'><button class='button buttonR buttonBlue' style='width:60px'>-</button></a></td>");
            client.println("<td>&nbsp;</td></tr><tr><td>&nbsp;</td><td align='right' style='font-size:20px'>ช่อง&nbsp;&nbsp;&nbsp</td><td>&nbsp;</td><td align='left' style='font-size:20px'>&nbsp;&nbsp;เสียง</td><td>&nbsp;</td></tr><tr><td colspan=5>&nbsp;</td></tr><tr><td>&nbsp;</td><td colspan=3><a href='/mute'><button class='button buttonC buttonGreen '>ปิดเสียง</button></a></td>"); 
            client.println("<td>&nbsp;</td></tr><tr><td colspan=5 align='left' style='font-size:22px'>ช่องรายการ</td></tr><tr><td colspan=2><a href='/ch/33'><button class='button buttonCh'>3 HD</button></a></td><td colspan=2><a href='/ch/35'><button class='button buttonCh'>7 HD</button></a></td></tr><tr><td colspan=2><a href='/ch/29'><button class='button buttonCh'>Mono</button></a></td>");
            client.println("<td colspan=2><a href='/ch/23'><button class='button buttonCh'>Workpoint</button></a></td></tr><tr><td colspan=2><a href='/ch/31'><button class='button buttonCh'>One</button></a></td><td colspan=2><a href='/ch/27'><button class='button buttonCh'>Ch 8</button></a></td></tr><tr><td colspan=2><a href='/ch/32'><button class='button buttonCh'>ThaiRath</button></a></td>");
            client.println("<td colspan=2><a href='/ch/222'><button class='button buttonCh'>TrueFilm</button></a></td></tr><tr><td colspan=2><a href='/ch/118'><button class='button buttonCh'>XZYT</button></a></td><td colspan=2><a href='/ch/46'><button class='button buttonCh'>Movie Hit</button></a></td></tr><tr><td colspan=2><a href='/ch/246'><button class='button buttonCh'>Fox Thai</button></a></td>");
            client.println("<td colspan=2><a href='/ch/41'><button class='button buttonCh'>SPKJump</button></a></td></tr><tr> <td colspan=2><a href='/ch/39'><button class='button buttonCh'>EXPWLD</button></a></td> <td colspan=2><a href='/ch/1'><button class='button buttonCh'>5 HD</button></a></td></tr></table></body></html>");

     // ส่วนตอนปิดการทำงาน
            client.println();            
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  
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
