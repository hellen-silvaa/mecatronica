// C++ code
//
void setup()
{
  pinMode(13, OUTPUT); //LED VERMELHO
  pinMode(12, OUTPUT); //LED AMARELO
  pinMode(11, OUTPUT); //LED VERDE
}

void loop()
{
  digitalWrite(13, HIGH); // LIGA LED VERMELHO
  delay(5000); // Wait for 5000 millisecond(s)
  digitalWrite(13, LOW); // DESLIGA LED VERMELHO
  
  
  digitalWrite(12, HIGH); // LIGA LED AMARELO
  delay(3000); // Wait for 3000 millisecond(s)
  digitalWrite(12, LOW);// DESLIGA LED AMARELO
  
  
  digitalWrite(11, HIGH); // LIGA LED VERDE
  delay(5000); // Wait for 5000 millisecond(s)
  digitalWrite(11, LOW); // DESLIGA LED VERDE
 
  
}
