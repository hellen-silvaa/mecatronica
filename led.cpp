#include <Servo.h>

int servoPin = 9;

//objeto do tipo Servo
Servo servoMotor;
  
void setup(){
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  
  // anexa o objeto do tipo servo ao pino do servo
  servoMotor.attach(servoPin);
}

void loop(){
servoMotor.write(0);
delay(2000);
Serial.print ("O amgulo e: ") + String (servoMotor.read());


servoMotor.write(90);
delay(2000);
Serial.print ("O amgulo e: ") + String (servoMotor.read());
      
servoMotor.write(180);
delay(2000);
Serial.print ("O amgulo e: ") + String (servoMotor.read());
        
}

