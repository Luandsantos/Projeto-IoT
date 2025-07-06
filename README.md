
# 🐾 Monitoramento de Umidade para Conforto e Saúde de Pets

## 📋 Contextualização do Problema

O nível da umidade afeta a todos, inclusive os animais de estimação. Para cachorros, a faixa ideal de umidade é cerca de 30% a 70%, e para gatos, de 45% a 65%, valores que variam conforme a raça e características individuais dos animais.

Assegurar que essas faixas sejam respeitadas reflete diretamente no conforto e saúde dos pets. Em níveis mais altos, o excesso de umidade pode provocar alergias, asmas ou outros problemas respiratórios, além de favorecer a proliferação de fungos e bactérias. Já o ar muito seco pode causar desidratação, irritação das mucosas e complicações dermatológicas.

Este projeto tem como objetivo monitorar a umidade de um ambiente com o uso de IoT, permitindo que os tutores tomem providências — como o uso de umidificadores ou desumidificadores — para manter a umidade em níveis adequados.

**Referências:**

- https://maximarcas.com.br/blog/post/seu-pet-merece-respirar-melhor.html  
- https://arsec.com.br/desumidificadores-para-pets-criando-um-ambiente-saudavel-para-seus-animais-de-estimacao/

## 🔧 Tecnologias Utilizadas

- ESP32
- Sensor DHT22
- Wokwi Simulator
- ThingSpeak
- Biblioteca ThingSpeak.h (oficial)
- Linguagem C++ (Arduino)

## ⚙️ Funcionamento do Projeto

1. O sensor DHT22 realiza leituras periódicas da umidade do ar no ambiente.
2. Os dados coletados são enviados para o canal público do ThingSpeak.
3. Os gráficos no ThingSpeak exibem em tempo real os níveis de umidade monitorados.
4. Com base nesses dados, é possível avaliar se o ambiente está adequado para o bem-estar dos pets.

## 🔗 Links

- 🔌 Projeto no Wokwi: [Clique aqui](https://wokwi.com/projects/435662750335194113)
- ☁️ Canal no ThingSpeak: [Clique aqui](https://thingspeak.mathworks.com/channels/3003938)

## 🛠️ Como Replicar o Projeto

1. Acesse o link do projeto no Wokwi.
2. Faça login no ThingSpeak e crie um canal com uma API Key.
3. Copie a API Key e cole no código no lugar apropriado.
4. Compile o código e simule o circuito.
5. Acesse o canal no ThingSpeak para visualizar os dados.

## 📁 Código-Fonte

> O código está disponível no arquivo `main.ino` com comentários explicativos.

## 👥 Integrantes

- Gabriel Afonso dos Santos
- Luan dos Santos Sales Pinheiro
