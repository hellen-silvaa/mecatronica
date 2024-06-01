////sensor de temperatura usando o LM35
//
//const int LM35 = A0; //define o pino que lera a saida do LM35
//int temperatura; // variavel que armazenara a temperatura medida
//
////funcao que sera executada uma vez quando ligar ou resetar o arduino
//void setup()
//{
//  Serial.begin(9600);//inicializa a comunicacao serial
//}
//
//void loop()
//{
//
//  //getting the voltage reading from the temperature sensor
// int reading = analogRead(LM35);  
// 
// // converting that reading to voltage, for 3.3v arduino use 3.3
// float voltage = reading * 5.0;
// voltage /= 1024.0; 
// 
// // print out the voltage
// Serial.print(voltage); Serial.println(" volts");
// 
// // now print out the temperature
// float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
//                                               //to degrees ((voltage - 500mV) times 100)
// Serial.print(temperatureC); Serial.println(" degrees C");
// 
// // now convert to Fahrenheit
// float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
// Serial.print(temperatureF); Serial.println(" degrees F");
// 
// delay(1000);    
//}

//sensor de temperatura usando o LM35
#define ledRed 13
#define ledYellow 12
#define ledGreen 11

const int LM35 = A0; //define o pino que lera a saida do LM35
int temperatura; // variavel que armazenara a temperatura medida



//funcao que sera executada uma vez quando ligar ou resetar o arduino
void setup()
{
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  
  Serial.begin(9600);//inicializa a comunicacao serial
}

void loop()
{
  
  temperatura = int((float(analogRead(LM35))*5/(1024.0))/0.01);
  Serial.println(temperatura);
  delay(2000);
  
  if(temperatura<25){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    
  } else if (temperatura <= 30 && temperatura >= 25){
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
   
  } else if (temperatura>30){
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
  }

  
}
