int PWM1 = 11;
int IN1 = 7;
int IN2 = 6;
int PWM2 = 10;
int IN3 = 4;
int IN4 = 5;

int SETPOINT1 = 127;
int SETPOINT2 = 127;

void setup()
{
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
void loop()
{
  // Anda para FRENTE (1-DIRETO | 2-DIRETO)
  analogWrite (PWM1, SETPOINT1);
  analogWrite (PWM2, SETPOINT2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  delay(3000);
  
  // Anda para TRAS (1-DIRETO | 2-DIRETO)
  analogWrite (PWM1, SETPOINT1);
  analogWrite (PWM2, SETPOINT2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  delay(3000);
  
  // Anda para DIREITA (1-DIRETO | 2-DIRETO)
  analogWrite (PWM1, SETPOINT1);
  analogWrite (PWM2, SETPOINT2);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay(3000);
  
  // Anda para ESQUERDA (1-DIRETO | 2-DIRETO)
  analogWrite (PWM1, SETPOINT1);
  analogWrite (PWM2, SETPOINT2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  delay(3000);
  
  // Carro PARADO (1-PARADO | 2-PARADO)
  analogWrite (PWM1, SETPOINT1);
  analogWrite (PWM2, SETPOINT2);
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  delay(3000);
}
