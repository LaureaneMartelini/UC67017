#include <Arduino.h>
int botao1 = 8;
int led = 4;

void setup() {
  pinMode(botao1, INPUT);//Botao 1
  pinMode(led, OUTPUT); // led
  Serial.begin(9600); // inicia o monitor serial
}

void loop() {
  int estado1 = digitalRead(botao1);

  if (estado1 == LOW) {
    Serial.println("Botão1 pressionado!");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("Botão1 NAO pressionado!");
    digitalWrite(led, LOW);
  }
  delay(1000);
}