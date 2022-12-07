#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
const char* SSID = "Sou lindo";
const char* password = "vitorteamo";
char criptografia;
String mensagem;
bool enviar = false;

void postDataToServer() {

  Serial.println("Posting JSON data to server...");
  HTTPClient http;
  http.begin("https://ur524n-3000.preview.csb.app/teobaldo");
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<200> doc;
  doc["nome"] = "Yves Levi";
  doc["turma"] = "Turma 1";
  doc["grupo"] = "Grupo 4";
  doc["mensagem"] = "olá teobaldo";
  mensagem = "olá teobaldo";
  for (int i = 0; i <= mensagem.length(); i++) {
    if (mensagem[i] == 'a') {
      mensagem[i] = '4';
    }
    if (mensagem[i] == 'e') {
      mensagem[i] = '3';
    }
    if (mensagem[i] == 'i') {
      mensagem[i] = '1';
    }
    if (mensagem[i] == 'o') {
      mensagem[i] = '0';
    }
    if (mensagem[i] == 'u') {
      mensagem[i] = 'j';
    }
  }

  doc["criptografada"] = mensagem;
  String requestBody;
  serializeJson(doc, requestBody);

  int httpResponseCode = http.POST(requestBody);

  if (httpResponseCode > 0) {

    String response = http.getString();

    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  enviar = true;
}

void EnviarDados() {
  Serial.println("Conectando na rede... ");
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  Serial.println("Conectado.");
  postDataToServer();

  WiFi.disconnect();
  Serial.println("Desconectei!");
}


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
}

void loop() {
  if (enviar == false) {
    EnviarDados();
  }
}