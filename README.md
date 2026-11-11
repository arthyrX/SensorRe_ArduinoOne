# Sensor de Ré com Arduino e HC-SR04

Projeto de simulação de um sensor de estacionamento veicular desenvolvido no Tinkercad e implementado em C++ para Arduino. O sistema utiliza emissão de ondas ultrassônicas para medir a distância de obstáculos em tempo real, fornecendo alertas visuais e sonoros com frequência variável conforme a proximidade.

---

## 🛠️ Componentes Utilizados

* 1x Arduino Uno R3
* 1x Sensor Ultrassônico HC-SR04
* 1x Buzzer Piezoelétrico
* 1x LED Difuso
* 1x Resistor de 220 Ω
* 1x Protoboard (Breadboard)
* Cabos jumpers

---

## 🔌 Esquema de Conexões

| Componente | Pino do Componente | Pino no Arduino | Descrição |
| :--- | :--- | :--- | :--- |
| HC-SR04 | VCC | 5V | Alimentação positiva |
| HC-SR04 | GND | GND | Referência de aterramento |
| HC-SR04 | TRIG | Pino Digital 13 | Disparo do pulso ultrassônico |
| HC-SR04 | ECHO | Pino Digital 12 | Leitura do tempo de retorno |
| Buzzer | Terminal (+) | Pino Digital 11 | Sinal sonoro via frequência |
| Buzzer | Terminal (-) | GND | Aterramento |
| LED | Ânodo (via 220 Ω) | Pino Digital 10 | Sinal de controle luminoso |
| LED | Cátodo | GND | Aterramento |

---

## ⚙️ Lógica de Funcionamento

O cálculo da distância baseia-se na velocidade de propagação do som no ar (~0.034 cm/µs), dividido por 2 para compensar o trajeto de ida e volta:

> Distância (cm) = (Duração do Eco em µs * 0.034) / 2

### Zonas de Alerta:

* **Zona Crítica (0 < distância <= 10 cm):**
  * LED ligado continuamente.
  * Buzzer com tom contínuo de 1500 Hz (alerta de colisão iminente).
* **Zona Intermediária (10 cm < distância <= 30 cm):**
  * Intermitência rápida (pulsos de 80 ms).
  * Frequência sonora de 1000 Hz.
* **Zona de Atenção (30 cm < distância <= 60 cm):**
  * Intermitência lenta e espaçada (pulso de 100 ms ligado, pausa de 400 ms).
  * Frequência sonora de 800 Hz.
* **Zona Segura (distância > 60 cm):**
  * LED e Buzzer em repouso (desligados).

---

## 📷 Circuito

<img width="1920" height="823" alt="SensorRe" src="https://github.com/user-attachments/assets/b064c678-ad32-4f4b-b215-ce75778a0c17" />
