#include <Arduino.h>
int botao = 3;
int rele = 4;

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
    delay(500);
    digitalWrite(rele, LOW); 
  } else {
    Serial.println("Botão solto.");
  }
  delay(500);
}
