void setup ()
{
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (8, OUTPUT);

}

void loop ()
{
digitalWrite(0, HIGH);
digitalWrite(3, HIGH);
delay(3000); 
digitalWrite(0, LOW);
digitalWrite(3, LOW);
  
digitalWrite(0, HIGH);
digitalWrite(4, HIGH);
delay(3000); 
digitalWrite(0, LOW);
digitalWrite(4, LOW);
  
digitalWrite(5, HIGH);
digitalWrite(2, HIGH);
delay(3000); 
digitalWrite(5, LOW);
digitalWrite(2, LOW);
  
digitalWrite(5, HIGH);
digitalWrite(1, HIGH);
delay(3000); 
digitalWrite(5, LOW);
digitalWrite(1, LOW);


  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); 
  
digitalWrite(8, HIGH);
digitalWrite(8, HIGH);
delay(3000); 


  digitalWrite(6, HIGH);
digitalWrite(9, HIGH);
delay(3000); 
digitalWrite(6, LOW);
digitalWrite(9, LOW);
  
digitalWrite(7, HIGH);
digitalWrite(9, HIGH);
delay(3000); 
digitalWrite(7, LOW);
digitalWrite(9, LOW);
}

