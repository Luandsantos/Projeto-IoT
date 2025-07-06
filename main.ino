// Projeto: Monitoramento de Umidade para Conforto e Saúde de Pets
// Alunos: Gabriel Afonso dos Santos e Luan Salles Pinheiro

#include <WiFi.h>
#include "DHT.h"
#include "ThingSpeak.h"

// Configurações do Wi-Fi
const char* ssid = "SUA_WIFI";
const char* password = "SUA_SENHA";

// Configurações do DHT
#define DHTPIN 15      // Pino do sensor DHT22
#define DHTTYPE DHT22  // Tipo do sensor
DHT dht(DHTPIN, DHTTYPE);

// Configuração do cliente WiFi e ThingSpeak
WiFiClient client;
unsigned long myChannelNumber = 3003938;
const char * myWriteAPIKey = "mwa0000038098904";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Conectando-se ao WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" conectado.");

  ThingSpeak.begin(client);  // Inicializa ThingSpeak
}

void loop() {
  float humidity = dht.readHumidity();

  if (isnan(humidity)) {
    Serial.println("Falha na leitura do sensor DHT!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.println(" %");

  ThingSpeak.setField(1, humidity);  // Envia para o campo 1
  int statusCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (statusCode == 200) {
    Serial.println("Dados enviados com sucesso ao ThingSpeak!");
  } else {
    Serial.print("Erro ao enviar dados. Código: ");
    Serial.println(statusCode);
  }

  delay(20000);  // Aguarda 20 segundos para próxima leitura
}
