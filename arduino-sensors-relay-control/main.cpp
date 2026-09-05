#include <Arduino.h>
int botao = 2;

void setup() 
{

  pinMode(botao, INPUT);
  Serial.begin(9600); // inicia o monitor serial
}

void loop() {
  int estado = digitalRead(botao);

  if (estado == LOW)
   {
    Serial.println("Botão pressionado!");
    digitalWrite(3, HIGH);
  } else {
    Serial.println("Botão solto.");
    digitalWrite(3, LOW);
  }
  delay(1000);
}

