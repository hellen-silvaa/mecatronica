#include <Servo.h>
int servoPin = 9; 
int potPin = A0;
int potValor = 0;
int servoPos = 0;

Servo motor; 

 void setup()
{
  pinMode(servoPin, OUTPUT);
  pinMode(potPin, INPUT);
  motor.attach(servoPin); 
}
void loop()
{
  potValor = analogRead(potPin); 
  servoPos=map(potValor, 0, 1023, 0, 180);
  motor.write(servoPos);
}
