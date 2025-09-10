# Medidor-Velocidade-IoT

1. Integrantes do grupo

Lucas Cavalcante RM 562857  
Matheus Rodrigues RM 561689  
Manoah Leão RM 563713
Caio Nascimento RM 561383

2. Descrição do projeto

O projeto “Passa a Bola” utiliza conceitos de IoT para medir a velocidade média da bola em chutes de futebol feminino amador.

Como não há hardware real disponível para esta entrega acadêmica, a solução é simulada no Node-RED, permitindo demonstrar:

Coleta de dados em tempo real

Processamento e visualização em dashboard

Integração entre dispositivos IoT e plataforma de gerenciamento

O objetivo é mostrar como a tecnologia IoT pode agregar valor a campeonatos, fornecendo métricas de desempenho e análise de dados de forma automatizada.

3. Arquitetura proposta

Diagrama conceitual:

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
