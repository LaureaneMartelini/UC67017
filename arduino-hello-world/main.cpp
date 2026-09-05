#include <Arduino.h>

void setup() {
 Serial.begin(9600);

}

void loop() {
  int s = digitalRead(4);
  Serial.print("s - ");
  Serial.println(s);
  if(s) {
    Serial.println("Botao pressionado");
  } else {
    Serial.println("Botao nao pressionado");
  }

  Serial.println("Hello, world");
  delay(1000);
}


