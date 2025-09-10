#include <WiFi.h>
#include <HTTPClient.h>

// --- CONFIGURAÇÕES DE REDE ---
const char* ssid = "SEU_SSID";
const char* password = "SUA_SENHA";

// --- CONFIGURAÇÃO DO NODE-RED ---
const char* serverUrl = "http://localhost:1880/chute"; // mudar a url do server **

// --- SENSORES ---
const int sensor1Pin = 12; // Linha de chute
const int sensor2Pin = 13; // Linha do gol
const float distancia = 18.0; // metros entre sensores

// --- VARIÁVEIS ---
unsigned long t1 = 0;
unsigned long t2 = 0;
bool sensor1Triggered = false;

void setup() {
  Serial.begin(115200);
  pinMode(sensor1Pin, INPUT_PULLUP);
  pinMode(sensor2Pin, INPUT_PULLUP);

  // Conectar Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
}

void loop() {
  int s1 = digitalRead(sensor1Pin);
  int s2 = digitalRead(sensor2Pin);

  // Sensor 1 acionado
  if (!sensor1Triggered && s1 == LOW) { // feixe interrompido
    t1 = millis();
    sensor1Triggered = true;
    Serial.println("Sensor 1 acionado!");
  }

  // Sensor 2 acionado
  if (sensor1Triggered && s2 == LOW) {
    t2 = millis();
    float v_m_s = distancia / ((t2 - t1) / 1000.0); // m/s
    float v_kmh = v_m_s * 3.6; // km/h
    Serial.print("Velocidade: ");
    Serial.print(v_kmh);
    Serial.println(" km/h");

    // Criar JSON
    String payload = "{";
    payload += "\"device_id\":\"medidor01\",";
    payload += "\"velocidade\":" + String(v_kmh) + ",";
    payload += "\"timestamp_ms\":" + String(millis());
    payload += "}";

    // Enviar HTTP POST
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverUrl);
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST(payload);
      Serial.println("HTTP Response code: " + String(httpResponseCode));
      http.end();
    }

    // Reset para próximo chute
    sensor1Triggered = false;
    delay(500); // evita múltiplos disparos do mesmo chute
  }
}
