#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "SHARE-RESIDENTE 2";  // Enter SSID here
const char* password = "Share@residente";  //Enter Password here

WebServer server(80);

uint8_t LED1pin = 4;
bool LED1status = LOW;

uint8_t LED2pin = 5;
bool LED2status = LOW;


void handle_x(){
  digitalWrite(LED1pin, HIGH);
  server.send(200, "sent");
  delay(1000);
  digitalWrite(LED1pin, LOW);
}

void handle_o(){
  digitalWrite(LED2pin, HIGH);
  server.send(200, "sent");
  delay(1000);
  digitalWrite(LED2pin, LOW);
}



void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/x", handle_x);
  server.on("/o", handle_o);
  
  server.begin();
  Serial.println("HTTP server started");
}



void loop() {
  server.handleClient();
}
