#include <ESP8266WiFi.h>
#include "ESPAsyncTCP.h"
#include "ESPAsyncWebServer.h"
#include "index.h" //Our HTML webpage contents

const char* PARAM_INPUT = "output";
// Create stepper object called 'myStepper', note the pin order:

//SSID and Password of your WiFi router
const char* ssid = "....";
const char* password = "datdeptrai123456";

//String state_led = "";

AsyncWebServer server(8080); //Server on port 8080

void setup() {
  Serial.begin(9600); 
  WiFi.begin(ssid, password);

// Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", MAIN_page);
  });
  server.begin();                  //Start server
  Serial.println("HTTP server started");
  
server.on("/Gate", HTTP_GET, [](AsyncWebServerRequest *request){
   String inputMessage;
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value(); // 1
      if(inputMessage == "open" ){
            Serial.println('o');
      }
      if (inputMessage == "close"){
            Serial.println('c');
      }
    }
    else {
      inputMessage = "No message sent";
    }
 });

 server.on("/Led", HTTP_GET, [](AsyncWebServerRequest *request){
   String inputMessage;
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value(); // 
      if(inputMessage == "on" ){
            Serial.println('l');
      }
      if (inputMessage == "off"){
            Serial.println('k');
      }
    }
    else {
      inputMessage = "No message sent";
    }
  request->send(200, "text/plain","OK");
    
 });

 server.on("/status_gate", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", send_statusGate().c_str());
 });
}

String send_statusGate()
{
  String state_door ="";
  while(Serial.available())
  {
    state_door = char(Serial.read());    
    break; 
  } 
  return state_door;
}

void loop() {

 }
