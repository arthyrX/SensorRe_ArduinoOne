// Definindo pinos conforme as suas ligações físicas
const int trig = 13;
const int echo = 12;
const int buzzer = 11;
const int led = 10;

long duracao;
float distancia;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  // inicia a comunicação serial para comunicaçao a distância
  Serial.begin(9600);
}

void loop()
{
  // dispara o pulso ultrassônico
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  // mede o tempo de resposta em microssegundos
  duracao = pulseIn(echo, 1);

  // converte o tempo em distancia (cm)
  distancia = duracao * 0.034 / 2;

  // mostra a distancia no monitor
  Serial.println("Distância: " + String(distancia) + "cm");

  // faixa de distância e alertas
  if (distancia <= 10){
    // zona crítica (perto demais): som e LED contínuo
    digitalWrite(led, 1);
    tone(buzzer, 1500);
    delay(100);
  }
  else if (distancia > 10 && distancia <=30){
    // zona intermediária: bips e piscadas rápidas
    digitalWrite(led, 1);
    tone(buzzer, 1000);
    delay(80);
    digitalWrite(led, 0);
    noTone(buzzer);
    delay(80);
  }
  else if (distancia > 30 && distancia <=60){
    // zona segura: bips lentos e espaçados
    digitalWrite(led, 1);
    tone(buzzer, 800);
    delay(100);
    digitalWrite(led, 0);
    noTone(buzzer);
    delay(400);
  }
  else {
    // fora de alcance: em repouso
    digitalWrite(led, 0);
    noTone(buzzer);
    delay(100);
  }

}