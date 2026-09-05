#include <Arduino.h>

unsigned long t = 0;
int botao1 = 0;
int botao_Nao_pressionado = 0;
int tempo_anterior = 0;
int botao_foi_pressionado = 0;
int t4 = 0;
int tempo_anterior_4 = 0;
int LED = 0;
int comeca_a_descontar = 0;
unsigned long tempo_anterior_4 = 0;
void setup() {
  pinMode(botao1, INPUT);//Botao 1
  Serial.begin(9600); // inicia o monitor serial
  pinMode(LED, OUTPUT);
}

void loop() {

  botao1 = !digitalRead(2);
  LED = digitalRead(3);

  if (botao1) 
  {
    botao_foi_pressionado = 1;
    Serial.println("Botão foi pressionado! - ");
    Serial.println(botao_foi_pressionado);

    digitalRead(3); //Ler o LED
    digitalWrite(LED, HIGH);
    //inicio da contagem 
    tempo_anterior_4 = millis() ;
  }

  if(botao_foi_pressionado) 
  {
    //se maior do que 2 segundos

    if (t4 - tempo_anterior_4 > 2000)
      digitalWrite(LED, HIGH);
      
      Serial.print("t - ");
      Serial.print(t);
    tempo_anterior_4 = millis() ;
    
    }

   
    if(comeca_a_descontar){
        t4 = millis();
        if (t4 - tempo_anterior_4 > 2000)
        digitalWrite(LED, LOW);

        //desligo 
     //Cancela o comeca_a_descontar
     comeca_a_descontar = 0;
        //  incompleto, finalizar o codigo para que o LED PISQUE!!!!!!!
        //Terminar o codigo e analisar novamente o codigo do inicio.
        //o botao espera 2 segundos e ele liga/desliga- depois de ligado passado 2 segundos desliga!!!!!
        //Sem delay

    }
  }




