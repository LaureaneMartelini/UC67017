#include <Arduino.h>

int s = 0; // variável global para leitura do pino

void setup()
{
  Serial.begin(9600);

  pinMode(2 , OUTPUT);

  pinMode(4 , INPUT);

}


void loop() {
  // Ler o estado do pino 4 (entrada)
  s = digitalRead(4);

  if (s) {
    Serial.println("Dentro do IF");
    digitalWrite(2, LOW);
    delay(500);
  } else {
    Serial.println("Dentro do ELSE");
    digitalWrite(2, HIGH);
    delay(500);
  }


}