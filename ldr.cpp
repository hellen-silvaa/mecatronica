// Programa controle de luminosidade com LDR

int ledverde = 11;
int ledazul = 10;
int ledvermelho = 9;
float LDR = A0;
float valorLDR = 0; //Leitura inicial do LDR

void setup() {
  
Serial.begin(9600);
pinMode(ledverde , OUTPUT);
pinMode(ledazul , OUTPUT);
pinMode(ledvermelho , OUTPUT);
pinMode(LDR , INPUT);

}

void loop() {
  
  
  valorLDR = analogRead(LDR);
  
  
//Luminosidade baixa
  
  if (valorLDR < 100){
    
    apagaLeds();
    
    digitalWrite(ledverde, HIGH);
  }
  
  // Luminosidade média
  
  if(valorLDR >= 300 && valorLDR<450){
    
    apagaLeds();
    digitalWrite(ledazul, HIGH);
    
  }
  
  
  // Luminosidade alta
  
  if(valorLDR>450){
    
    apagaLeds();
    
    digitalWrite(ledvermelho, HIGH);
    
  }
  
  Serial.print(valorLDR);
  
}
  
  void apagaLeds(){
    
    digitalWrite(ledverde, LOW);
    digitalWrite(ledazul, LOW);
    digitalWrite(ledvermelho, LOW);
  
  
}
