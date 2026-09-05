#include <Arduino.h>

int opcao = 0;
int botaoCima = 2;
int botaoBaixo = 3;
int botaoDireita = 4;
int botaoEsquerda = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(botaoCima, INPUT);
  pinMode(botaoBaixo, INPUT);
  pinMode(botaoDireita, INPUT);
  pinMode(botaoEsquerda, INPUT);
  
}

void loop() { 
  // 0 -> parar
  // 1 -> cima
  // 2 -> baixo
  // 3 -> direita
  // 4 -> esquerda
  // 5 -> cima direita
  // 6 -> cima esquerda
  // 7 -> baixo direita
  // 8 -> baixo esquerda

 if (digitalRead(botaoCima) == LOW) {
    opcao = 1;
  }
  
  if (digitalRead(botaoBaixo) == LOW) {
    opcao = 2;
    }
  
  if (digitalRead(botaoDireita) == LOW) {
    opcao = 3;
  }
  
  if (digitalRead(botaoEsquerda) == LOW) {
    opcao = 4;
  }
  
  if (digitalRead(botaoCima) == LOW && digitalRead(botaoDireita) == LOW) {
    opcao = 5;
  }
  
  if (digitalRead(botaoCima) == LOW && digitalRead(botaoEsquerda) == LOW) {
    opcao = 6;
  }

  if (digitalRead(botaoBaixo) == LOW && digitalRead(botaoDireita) == LOW) {
    opcao = 7;
  }
  
  if (digitalRead(botaoBaixo) == LOW && digitalRead(botaoEsquerda) == LOW) {
    opcao = 8;
  }
  
  if (digitalRead(botaoCima) == LOW && digitalRead(botaoBaixo) == LOW && digitalRead(botaoDireita) == LOW && digitalRead(botaoEsquerda) == LOW) {
    opcao = 0;
  }
  
  switch(opcao) {
    case 1:
    Serial.println("cima");
    break;
    
    case 2:
    Serial.println("baixo");
    break;

    case 3:
    Serial.println("direita");
    break;

    case 4:
    Serial.println("esquerda");
    break;

    case 5:
    Serial.println("diagonal cima direita");
    break;

    case 6:
    Serial.println("diagonal cima esquerda");
    break;

    case 7:
    Serial.println("diagonal baixo direita");
    break;

    case 8:
    Serial.println("diagonal baixo esquerda");
    break;

    default:
    Serial.println("parado");
  }
}