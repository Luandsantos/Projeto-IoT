// Tema: Monitoramento de Umidade para Conforto e Saúde de Pets
// Alunos: Gabriel Afonso dos Santos e Luan dos Santos Sales Pinheiro

#include <WiFi.h>
#include "DHTesp.h"
#include "ThingSpeak.h"

const int DHT_PIN = 15; // Pin do sensor DHT22
const char* WIFI_NAME = "Wokwi-GUEST"; // SSID do Wi-Fi
const char* WIFI_PASSWORD = ""; // Senha do Wi-Fi 
const int myChannelNumber = 3003938; // Número do canel do Thingspeak 
const char* myApiKey = "R3TRS90VU1STBLR7"; // Key da API do Thingspeak
const char* server = "api.thingspeak.com"; // Endereço de Servidor do ThingSpeak

float dataAtual;

// Cria uma instância da biblioteca DHTesp (biblioteca do sensor)
DHTesp dhtSensor; 
// Cria um objeto de cliente do Wi-Fi
WiFiClient client; 

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22); // Iniciar o sensor
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD); // Conecta na rede Wi-Fi
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Wifi não conectado."); // Mostra uma mensagem no console se a conexão não foi realizada
  }
  Serial.println("Wifi conectado."); // Mostra uma mensagem no console se a conexão foi realizada
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client); // Inicializa a biblioteca do ThingSpeak (que permite a integração com o site)
}

void loop() {
  float data = dhtSensor.getHumidity(); // Lê a umidade definida no sensor
  ThingSpeak.setField(1,data); // Define o primeiro campo do canal do ThingSpeak como a umidade lida

  int status = ThingSpeak.writeFields(myChannelNumber,myApiKey); 
  
  Serial.println("Umidade: " + String(data, 1) + "%"); // Mostra o valor da umidade no console
  
  if(status == 200){
    Serial.println("Dados transferidos."); // Mostra uma mensagem no console se os dados foram passados para o ThingSpeak
  }else{
    Serial.println("Erro em transferir os dados: " + String(status)); // Mostra uma mensagem no console se os dados NÃO foram passados para o ThingSpeak, bem como o erro que de
  }
  Serial.println("---");

  dataAtual = data;
  delay(15000);
}
