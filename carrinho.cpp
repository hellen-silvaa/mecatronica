// ROBM4 - 24/10/2021
// Atividade 1 - Carrinho com dois motores DC controlado por Arduino
// Mateus Moraes Toledo (BP3011127)

// Variáveis:
int botaoFrente   = 2;      // entrada digital 2 (pino)
int botaoTras     = 4;      // entrada digital 4 (pino)
int botaoDireita  = 6;      // entrada digital 6 (pino)
int botaoEsquerda = 5;      // entrada digital 5 (pino)

int valorBotaoFrente   = 0;      // armazena valor (0 ou 1 - HIGH ou LOW)
int valorBotaoTras     = 0;      // armazena valor (0 ou 1 - HIGH ou LOW)
int valorBotaoDireita  = 0;      // armazena valor (0 ou 1 - HIGH ou LOW)
int valorBotaoEsquerda = 0;      // armazena valor (0 ou 1 - HIGH ou LOW)

int in1 =  7;      // saída digital 7  (pino)
int in2 =  8;      // saída digital 8  (pino)
int in3 = 12;      // saída digital 12 (pino)
int in4 = 13;      // saída digital 13 (pino)

void setup() {
  pinMode(botaoFrente, INPUT)  ;       // pino digital 2 definido como entrada
  pinMode(botaoTras, INPUT)    ;       // pino digital 4 definido como entrada
  pinMode(botaoDireita, INPUT) ;       // pino digital 6 definido como entrada
  pinMode(botaoEsquerda, INPUT);       // pino digital 5 definido como entrada
  
  pinMode(in1, OUTPUT);       // pino digital 7 definido como saída
  pinMode(in2, OUTPUT);       // pino digital 8 definido como saída
  pinMode(in3, OUTPUT);       // pino digital 12 definido como saída
  pinMode(in4, OUTPUT);       // pino digital 13 definido como saída
}

void loop() {
  valorBotaoFrente   = digitalRead(botaoFrente)  ;       // faz a leitura digital (0 ou 1 - LOW ou HIGH)
  valorBotaoTras     = digitalRead(botaoTras)    ;       // faz a leitura digital (0 ou 1 - LOW ou HIGH)
  valorBotaoDireita  = digitalRead(botaoDireita) ;       // faz a leitura digital (0 ou 1 - LOW ou HIGH)
  valorBotaoEsquerda = digitalRead(botaoEsquerda);       // faz a leitura digital (0 ou 1 - LOW ou HIGH)

  if(valorBotaoFrente == LOW && valorBotaoTras == LOW && valorBotaoDireita == LOW && valorBotaoEsquerda == LOW){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else if(valorBotaoFrente == HIGH && valorBotaoTras == LOW && valorBotaoDireita == LOW && valorBotaoEsquerda == LOW){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW) ;
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW) ;
  }
  else if(valorBotaoFrente == LOW && valorBotaoTras == HIGH && valorBotaoDireita == LOW && valorBotaoEsquerda == LOW){
    digitalWrite(in1, LOW) ;
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW) ;
    digitalWrite(in4, HIGH);
  }
    else if(valorBotaoFrente == LOW && valorBotaoTras == LOW && valorBotaoDireita == HIGH && valorBotaoEsquerda == LOW){
    digitalWrite(in1, LOW) ;
    digitalWrite(in2, LOW) ;
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW) ;
  }
    else if(valorBotaoFrente == LOW && valorBotaoTras == LOW && valorBotaoDireita == LOW && valorBotaoEsquerda == HIGH){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW) ;
    digitalWrite(in3, LOW) ;
    digitalWrite(in4, LOW) ;
  }
  else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }  
}
