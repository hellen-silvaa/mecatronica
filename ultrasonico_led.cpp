
//declarar variaveis pinos
int trigger = 7; // emite pulso
int echo =8; // recebe o pulso
float dist = 0;
int led_Y = ;
int led_G = ;
int led_R = ;
  

// declarar pinos
void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin (9600);
  pinMode(, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(trigger, OUTPUT);
}

void loop()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  dist = pulseIn(echo, HIGH); // armazena o valor lido
  dist = dist/58; // converter para cm
  Serial.print ("distancia = ");
  Serial.print (dist);
  Serial.println ("cm");
  delay (100);
  

}
