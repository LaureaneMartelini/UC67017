#include <Arduino.h>
int botao= 2;
int botao2= 3;
int opcao= 0;

void setup(){
  Serial.begin(9600);

  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);

}

void loop(){
  //Testar se o botao1 esta a ser pressionado

 if (digitalRead(botao) == LOW) //Se pressionar o botao, opçao = a 0
 {
   opcao = 0;
 }

 //Testar se o botao2 está a ser pressionado , opçao e = a 1
 if(digitalRead(botao2) == LOW)
 {
  opcao = 1;

 }
//Testar se os dois botoes estao a ser pressionados, da opcao = a 2
if(digitalRead(botao) == LOW && digitalRead(botao2) == LOW)
{
  opcao = 2;
}

switch (opcao)
{
  case 0:
  Serial.println("Case0");
  break;

case 1:
  Serial.println("Case1");
  break;

default:
Serial.println("Default");// Como nao existe opcao 2, vai para o default e volta o ciclo. 

break;
}
}

