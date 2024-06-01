const int buzzerPin = 10; // Piezo no pino 8
const int ldrPin = 0; // LDR no pino analógico 0
const int ledPin = 9; // LED no pino digital 2 

const int ledVerde = 11;
const int ledAmarelo = 12;
const int ledVermelho = 13;

int ldrValue = 0; // Valor lido do LDR
const int freq = 5; // altera frequencia do sonorizador

void setup() {
    //Ativa o serial monitor que exibirá os valores lidos no sensor.
    Serial.begin(9600);
    //Define os pinos digitais dos leds e buzzer como de saída.
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledVerde,OUTPUT);
    pinMode(ledAmarelo,OUTPUT);
    pinMode(ledVermelho,OUTPUT);
}

void loop() {
ldrValue = analogRead(ldrPin); // lê o valor do LDR
 
  //PROBLEMA DETECTADO
  if (ldrValue < 40) {
    apagaLeds();
    digitalWrite(ledVermelho,HIGH);
    
  }
   
  //NÍVEL DE ALERTA
  if (ldrValue >= 40 && ldrValue <= 200) {
    apagaLeds();
    digitalWrite(ledAmarelo,HIGH);
    
    //apita por 3s
    tone(buzzerPin,1000); //apita em um tom de 1000 Hz do piezo
    digitalWrite(ledPin, HIGH);
    delay(3000); // espera um pouco
    noTone(buzzerPin); // interrompe o tom
    digitalWrite(ledPin, LOW); // Apaga o LED
    delay(ldrValue); // espera a quantidade de milissegundos em ldrValue
  }
   
  //SISTEMA OK
  if (ldrValue > 200) {
    apagaLeds();
    digitalWrite(ledVerde,HIGH);
  }
   
  //Exibindo o valor do sensor no serial monitor.
  Serial.println(ldrValue);
  
  delay(500); 
}

//Apaga todos os leds de uma vez.
void apagaLeds() {
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledAmarelo,LOW);
  digitalWrite(ledVermelho,LOW);
} 
