#include <Arduino.h>

  typedef struct Botao
{   //Estrutura definida para o botao;ou qualquer coisa que queira para otimizar.

  int estado;
  int periferico;

};
//Padronizando os estados e perifericos;
  Botao b1;
  Botao b2;
  Botao b3;
  Botao b4;
  int opcao= 0;

void setup (){
  //Inicializacao;

  Serial.begin(9600);
 
  b1.periferico= 2;
  b2.periferico= 3;
  b3.periferico= 4;
  b4.periferico= 5;


  b1.estado= LOW;
  b2.estado= LOW;
  b3.estado= LOW;
  b4.estado= LOW;


  pinMode(b1.periferico,INPUT);
  pinMode(b2.periferico,INPUT);
  pinMode(b3.periferico,INPUT);
  pinMode(b4.periferico,INPUT);

}

  void loop(){

    //B1-cima;
    //B2-baixo;
    //B3-esquerda;
    //B4-direita;

    if (digitalRead(b1.periferico) == LOW) {
      opcao = 1;
    }
    
    if (digitalRead(b2.periferico) == LOW) {
      opcao = 2;
    }
    
    if (digitalRead(b3.periferico) == LOW) {
      opcao = 3;
    }
    
    if (digitalRead(b4.periferico) == LOW) {
      opcao = 4;
    }
    
    if (digitalRead(b1.periferico) == LOW && digitalRead(b2.periferico) == LOW) {
      opcao = 5;
    }
    
    if (digitalRead(b2.periferico) == LOW && digitalRead(b1.periferico) == LOW) {
      opcao = 6;
    }
    
    if (digitalRead(b3.periferico) == LOW && digitalRead(b4.periferico) == LOW) {
      opcao = 7;
    }
    
    if (digitalRead(b4.periferico) == LOW && digitalRead(b2.periferico) == LOW) {
      opcao = 8;
    }
    
    if (digitalRead(b1.periferico) == LOW && digitalRead(b2.periferico) == LOW && 
        digitalRead(b3.periferico) == LOW && digitalRead(b4.periferico) == LOW) {
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







