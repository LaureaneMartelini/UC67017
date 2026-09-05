#include <Arduino.h>

int botao = 3;
int rele = 2;

void setup() {
  pinMode(botao, INPUT);
  pinMode(rele, OUTPUT);
  Serial.begin(9600); // inicia o monitor serial
}

void loop() {
  int estado = digitalRead(botao);
  if (estado == LOW) {
    Serial.println("Botão pressionado!");
    digitalWrite(rele, HIGH);
  } else {
    Serial.println("Botão solto.");
  }
  delay(1000);
}

