#include <Arduino.h>

    // Configuraçoes gerais do codigo
    //objetivo: definir constantes, tipos e variaveis globais


    enum Botoes_EstadoBotoes {
    BOTAO_DIREITA,
    BOTAO_ESQUERDA,
    BOTAO_CIMA,
    BOTAO_BAIXO
    };

    enum estado_Sistema {
    DESLIGADO,
    DIREITA,
    ESQUERDA,
    CIMA,
    BAIXO
    };

    //Array
    int pinosLEDS[] = {2, 3, 4, 5 };
    int numLeds = 4;
    int pinosBotoes[] = {8, 9, 10, 11};
    int numBotoes = 4;

    //criaçao da varivael global (para saber quais botoes foram pressionados)
    estado_Sistema estadoAtual = DESLIGADO;

    void setup()
    {
    Serial.begin(9600);

     //LEDS
    for (int i = 0; i < numLeds; i++){
    pinMode(pinosLEDS[i], OUTPUT);
    }
    
     //Divisao entre pinagem BOTOES 
    for (int i = 0; i < numBotoes; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
    } 
    }
    //Configuracao antes de rodar o loop
    //Objetivo de iniciar a comunicacao serial e definir os pinos
    // Tempo para o monitor_speed,apresentacaO
    void loop()
    {
        //Repetiçao infinita
        //Objetivo ler os botoes, definir direçao e println
        //Leitura digital do estado do botao
        //Leitura digital do LED nao é usado
         // Lógica para ler os botões e mudar o estado
    if (digitalRead(pinosBotoes[BOTAO_DIREITA]) == LOW) 
    {estadoAtual = DIREITA;
    Serial.print("DIREITA");}
    else if (digitalRead(pinosBotoes[BOTAO_ESQUERDA]) == LOW) 
    {estadoAtual = ESQUERDA;
    Serial.print("ESQUERDA");}
    else if (digitalRead(pinosBotoes[BOTAO_CIMA]) == LOW)
     {estadoAtual = CIMA;
     Serial.print("CIMA");}
    else if (digitalRead(pinosBotoes[BOTAO_BAIXO]) == LOW)
     {estadoAtual = BAIXO;
     Serial.print("BAIXO");}
    else {
    // Se nenhum botão estiver pressionado, volta ao estado APAGADO
    estadoAtual = DESLIGADO;
    Serial.print("DESLIGADO");
    }

        
    // Bloco switch e case para executar a ação baseada no estado

  switch (estadoAtual) {

    case BOTAO_DIREITA:
      digitalWrite(pinosLEDS[DIREITA], HIGH);
      // Apaga os outros para evitar que fiquem acesos
      digitalWrite(pinosLEDS[ESQUERDA], LOW);
      digitalWrite(pinosLEDS[CIMA], LOW);
      digitalWrite(pinosLEDS[BAIXO], LOW);
      break;

    case BOTAO_ESQUERDA:
      digitalWrite(pinosLEDS[ESQUERDA], HIGH);
      // Apaga os outros para evitar que fiquem acesos
      digitalWrite(pinosLEDS[DIREITA], LOW);
      digitalWrite(pinosLEDS[CIMA], LOW);
      digitalWrite(pinosLEDS[BAIXO], LOW);
      break;

    case BOTAO_CIMA:
      digitalWrite(pinosLEDS[CIMA], HIGH);
      // Apaga os outros para evitar que fiquem acesos
      digitalWrite(pinosLEDS[DIREITA], LOW);
      digitalWrite(pinosLEDS[ESQUERDA], LOW);
      digitalWrite(pinosLEDS[BAIXO], LOW);
      break;

    case BOTAO_BAIXO:
      digitalWrite(pinosLEDS[BAIXO], HIGH);
      // Apaga os outros para evitar que fiquem acesos
      digitalWrite(pinosLEDS[DIREITA], LOW);
      digitalWrite(pinosLEDS[ESQUERDA], LOW);
      digitalWrite(pinosLEDS[CIMA], LOW);
      break;

    default:
      // Se nenhum modo for selecionado, apaga todos os LEDs
      digitalWrite(pinosLEDS[BAIXO], LOW);
      digitalWrite(pinosLEDS[DIREITA], LOW);
      digitalWrite(pinosLEDS[ESQUERDA], LOW);
      digitalWrite(pinosLEDS[CIMA], LOW);
      
      break;
    }
    }

    

