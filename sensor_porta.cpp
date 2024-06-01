#include<Servo.h>

int led = 4;
int servoPin = 5;
int trigger = 3;
int echo = 2;

int dist = 0;

Servo servoMotor;

void setup(){
pinMode(led, OUTPUT);
pinMode(servoPin, OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, OUTPUT);
Serial.begin (9600);
servoMotor.attach(servoPin);
}

void loop(){
digitalWrite(trigger,LOW);
delayMicroseconds(5);
digitalWrite(trigger,HIGH);
delayMicroseconds(10);
digitalWrite(trigger,LOW);


dist = pulseIn (echo, HIGH);
dist = dist/58;

if (dist <= 100){
digitalWrite(led,HIGH);
servoMotor.write(90);
delay(500);
Serial.println("Distancia = " + String(dist) + " cm");
}
else {
digitalWrite(led,LOW);
servoMotor.write(0);
delay(500);
Serial.println("Distancia = " + String(dist) + " cm");
}
}
