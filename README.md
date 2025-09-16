# Medidor-Velocidade-IoT

link do video no youtube [youtu.be/AgjCpLPqBDw](https://youtu.be/AgjCpLPqBDw)  

## 1. Integrantes do grupo

Lucas Cavalcante RM 562857  
Matheus Rodrigues RM 561689  
Manoah Leão RM 563713  
Caio Nascimento RM 561383

## 2. Descrição do projeto

O projeto “Passa a Bola” utiliza conceitos de IoT para medir a velocidade média da bola em chutes de futebol feminino amador.  
Como não há hardware real disponível para esta entrega acadêmica, a solução é simulada no Node-RED, permitindo demonstrar:  
Coleta de dados em tempo real.  
Processamento e visualização em dashboard.  
Integração entre dispositivos IoT e plataforma de gerenciamento.  
O objetivo é mostrar como a tecnologia IoT pode agregar valor a campeonatos, fornecendo métricas de desempenho e análise de dados de forma automatizada.  
## 3. Arquitetura proposta

Diagrama conceitual:

```
[Sensor 1 – Linha de Chute]  ──┐
                                │
[Sensor 2 – Linha do Gol]  ─────┤
                                ▼
                               ESP32 (simulado)
                                │ HTTP POST
                                ▼
                               Node-RED
                                │
                                ├─ Function Node (extrai velocidade)
                                │
                                ├─ Debug Node (mostra JSON)
                                │
                                └─ Gauge / Chart (Dashboard)

```
Componentes:

Sensores virtuais: simulam passagem da bola.  
ESP32: microcontrolador que enviaria dados via HTTP (simulado com inject node).  
Node-RED: plataforma de gerenciamento, recebe os dados, processa e atualiza o dashboard.  
Dashboard: mostra a velocidade em tempo real usando gauge/chart.
## 4. Recursos necessários

• Node-RED [nodered.org](https://nodered.org/)  
• Node-RED Dashboard (para gauge/chart).  
• Computador ou Raspberry Pi com navegador web.  
• Arquivos do projeto:  
• fluxo_medidor_velocidade.json (Node-RED).  
• esp32_simulado.ino (código ESP32 conceitual).  
## 5. Instruções de uso

• Instalar Node-RED e Dashboard.  
• Node-RED [nodered.org](https://nodered.org/)  
• Instalar Dashboard via Manage Palette → node-red-dashboard.  
• Importar fluxo Node-RED.  

Menu → Import → Clipboard → colar conteúdo de fluxo_medidor_velocidade.json → Import  

Executar simulação.  
Use o inject node para simular chutes.  
Observe os valores no dashboard (gauge/chart).  
Debug node mostra o JSON completo do “dispositivo IoT”.  
Acesse em: http://localhost:1880/ui  
Veja a velocidade em tempo real conforme disparos do inject node.  
## 6. Códigos Fonte

esp32_simulado.ino (código conceitual para ESP32).  
fluxo_medidor_velocidade.json (Node-RED).  
## 7. Benefícios do projeto

Demonstração de IoT aplicada ao futebol sem depender de árbitro ou hardware real.  
Visualização de métricas em tempo real.  
Escalável: adicionando mais sensores ou medindo outros parâmetros de desempenho.
