#include <Wire.h>
#include <RTClib.h>
#include <BluetoothSerial.h>
#include <RTClib.h>
#include <BluetoothSerial.h>


RTC_DS3231 rtc;
BluetoothSerial ESP_BT;
 
bool bluetoothConnected = false;
bool expectingTimeCommand = false; // Flag to indicate whether we are expecting the time command
 
 
 
#define IN1 25
#define IN2 14
#define IN3 27
#define IN4 26
 
int velocidade = 2;
int passoAtual = 0;
 
int passosSegunda = 100;
int passosTerca = 110;
int passosQuarta = 120;
int passosQuinta = 130;
int passosSexta = 140;
int passosSabado = 150;
int passosDomingo = 160; 
 
int SegundaRecebida = 0;
int TercaRecebida = 0;
int QuartaRecebida = 0;
int QuintaRecebida = 0;
int SextaRecebida = 0;
int SabadoRecebida = 0;
int DomingoRecebida = 0;
 
void girarMotorSegunda(int passos);
void girarMotorTerca(int passos);
void girarMotorQuarta(int passos);
void girarMotorQuinta(int passos);
void girarMotorSexta(int passos);
void girarMotorSabado(int passos);
void girarMotorDomingo(int passos);
 
 
void girarMotorAoContrarioSegunda(int passos);
void girarMotorAoContrarioTerca(int passos);
void girarMotorAoContrarioQuarta(int passos);
void girarMotorAoContrarioQuinta(int passos);
void girarMotorAoContrarioSexta(int passos);
void girarMotorAoContrarioSabado(int passos);
void girarMotorAoContrarioDomingo(int passos) ;
 
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"}; //Dias da semana
 
//const int ledPin = 25;
 
void setup() {
  Serial.begin(9600);
  ESP_BT.begin("ESP32_Control");
 
  Wire.begin(21, 22); // SDA, SCL
 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
 
  //pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, LOW); // Ensure the LED is initially off
 
  Serial.println("Esperando por uma conexão Bluetooth...");
 
  // Initialize RTC module
  if (!rtc.begin()) {
    Serial.println("RTC não encontrado!");
    while (1);
  } //if (!rtc.begin()) {
}//void setup() {
 
void loop() {//1





  if (ESP_BT.available()) { //2






      String received = ESP_BT.readStringUntil('\n');
      Serial.println("Recebido: " + received);
      received.trim(); // Remove extra whitespace


  
      // Check if the received command is "SEXTA-FEIRA" and if the current day is Friday
      if (received == "SEGUNDA-FEIRA" && rtc.now().dayOfTheWeek() == 1) {//3
        Serial.println("DIA ESCOLHIDO: SEGUNDA!");
        SegundaRecebida = 1;
        bluetoothConnected = true;
        expectingTimeCommand = true; // We are now expecting the time command
  
                                                                //SE TERÇA RECEBIDA
                                                                if (TercaRecebida == 1) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de TERÇA-FEIRA");
                                                                  girarMotorAoContrarioTerca(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                        } //if (TercaRecebida == 1)
                                                    
                                                    
                                                                //SE QUARTA RECEBIDA
                                                                else if  (QuartaRecebida == 1) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUARTA-FEIRA");
                                                                  girarMotorAoContrarioQuarta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                            } //else if (QuartaRecebida==1)
                                                    
                                                              
                                                                //SE QUINTA RECEBIDA
                                                                else if (QuintaRecebida == 1 ) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                                  girarMotorAoContrarioQuinta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                              } //else if (QuintaRecebida == 1 )
                                                    
                                                                //SE SEXTA RECEBIDA
                                                                else if (SextaRecebida == 1 ) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                                  girarMotorAoContrarioSexta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                              } //else if (SextaRecebida == 1 )
                                                    
                                                    
                                                                //SE SÁBADO RECEBIDA
                                                                else if (SabadoRecebida == 1 ) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SÁBADO");
                                                                  girarMotorAoContrarioSabado(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                              } //else if (SabadoRecebida == 1 )
                                                    
                                                    
                                                    
                                                                //SE DOMINGO RECEBIDA
                                                                else if (DomingoRecebida == 1 ) {
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                                  girarMotorAoContrarioDomingo(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                                                                  girarMotorSegunda(10);
                                                                  SegundaRecebida = 1;
                                                                                              } //else if (DomingoRecebida == 1 )
              
                                                                        }//3
  
  
      else if (expectingTimeCommand) { //4


        // Check if the received command starts with "time"
        if (received.startsWith("time:")) {//5
          // Extract hour and minute from the command
          int colonIndex = received.indexOf(':');
          if (colonIndex != -1 && received.length() >= colonIndex + 6) {//6
            int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
            int chosenMinute = received.substring(colonIndex + 4).toInt();
  
            // Process the time command as before
            DateTime now = rtc.now();
            int currentHour = now.hour();
            int currentMinute = now.minute();
  
            Serial.print("Chosen time: ");
            Serial.print(chosenHour);
            Serial.print(":");
            Serial.println(chosenMinute);
  
            // Check if current time matches chosen time
            while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//7
              // Keep checking until current time matches chosen time
              now = rtc.now();
              currentHour = now.hour();
              currentMinute = now.minute();
              delay(1000); // Delay to avoid excessive looping
            }//7
  
    
                Serial.print("BOTÃO: SEGUNDA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEGUNDA-FEIRA");
                girarMotorSegunda(10);
                SegundaRecebida = 1;
                
            } //6
            else {//8
              Serial.println("Hora atual não corresponde à hora escolhida.");
            }//8
  
            // Reset the flag since we have processed the time command
            expectingTimeCommand = false;
          }//5
        }//4
        else {//9
          Serial.println("Comando inválido recebido após SEGUNDA.");
          // Reset the flag since we didn't receive the expected time command
          expectingTimeCommand = false;
        }//9







                      
    // BOTÃƒO: TERÃ‡A-FEIRA 
    if (received == "TERCA-FEIRA" && rtc.now().dayOfTheWeek() == 2) {//10
      Serial.println("DIA ESCOLHIDO: TERÃ‡A!");
      TercaRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 
                                                                //SE TERÃ‡A RECEBIDA
                                                                if (SegundaRecebida == 1) {
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                                  girarMotorAoContrarioSegunda(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                  girarMotorTerca(10);
                                                                  TercaRecebida = 1;
                                                                                        } //if (TercaRecebida == 1)
                                                    
                                                    
                                                                //SE QUARTA RECEBIDA
                                                                else if  (QuartaRecebida == 1) {
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUARTA-FEIRA");
                                                                  girarMotorAoContrarioQuarta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                  girarMotorTerca(10);
                                                                  TercaRecebida = 1;
                                                                                            } //else if (QuartaRecebida==1)
                                                    
                                                              
                                                                //SE QUINTA RECEBIDA
                                                                else if (QuintaRecebida == 1 ) {
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                                  girarMotorAoContrarioQuinta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                  girarMotorTerca(10);
                                                                  TercaRecebida = 1;
                                                                                              } //else if (QuintaRecebida == 1 )
                                                    
                                                                //SE SEXTA RECEBIDA
                                                                else if (SextaRecebida == 1 ) {
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                                  girarMotorAoContrarioSexta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                  girarMotorTerca(10);
                                                                  TercaRecebida = 1;
                                                                                              } //else if (SextaRecebida == 1 )
                                                    
                                                    
                                                                //SE SÃBADO RECEBIDA
                                                                else if (SabadoRecebida == 1 ) {
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de SÃBADO");
                                                                  girarMotorAoContrarioSabado(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                  girarMotorTerca(10);
                                                                  TercaRecebida = 1;
                                                                                              } //else if (SabadoRecebida == 1 )
 
 
 
                                                              //SE DOMINGO RECEBIDA
                                                              else if (DomingoRecebida == 1 ) {
                                                                Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                                girarMotorAoContrarioDomingo(10);
                                                                Serial.print("ESPEROU 5 SECUNDOS");
                                                                delay (5000);
                                                                Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
                                                                girarMotorTerca(10);
                                                                TercaRecebida = 1;
                                                                                            } //else if (DomingoRecebida == 1 )
             
    }//10
 
 
    else if (expectingTimeCommand) { //11
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//12
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//13
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//14
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//14
 
   
              Serial.print("BOTÃƒO: TERÃ‡A-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE TERÃ‡A-FEIRA");
              girarMotorTerca(10);
              TercaRecebida = 1;
               //else  
            // Current time matches chosen time: turn on LED
            //digitalWrite(ledPin, HIGH);
            //Serial.println("Hora atual corresponde Ã  hora escolhida: LED ligado");
 
            // Optional: Wait for a few seconds before turning off the LED
          //  delay(5000);
 
            // Turn off the LED
           // digitalWrite(ledPin, LOW);
          //  Serial.println("LED off");
          } //13
          else {//15
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//15
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//12
      }//11
       else {//16
        Serial.println("Comando invÃ¡lido recebido apÃ³s TERÃ‡A.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//16
    
           
                      
                      
                      
                        
                        
    // BOTÃƒO: QUARTA-FEIRA 
    if (received == "QUARTA-FEIRA" && rtc.now().dayOfTheWeek() == 3) {//17
      Serial.println("DIA ESCOLHIDO: QUARTA!");
      QuartaRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 
                                                                  //SE TERÃ‡A RECEBIDA
                                                                  if (SegundaRecebida == 1) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                                    girarMotorAoContrarioSegunda(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                          } //if (TercaRecebida == 1)
                                                      
                                                      
                                                                  //SE TERÃ‡A-RECEBIDA
                                                                  else if  (TercaRecebida == 1) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de TERÃ‡A-FEIRA");
                                                                    girarMotorAoContrarioTerca(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                              } //else if (QuartaRecebida==1)
                                                      
                                                                
                                                                  //SE QUINTA RECEBIDA
                                                                  else if (QuintaRecebida == 1 ) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                                    girarMotorAoContrarioQuinta(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                                } //else if (QuintaRecebida == 1 )
                                                      
                                                                  //SE SEXTA RECEBIDA
                                                                  else if (SextaRecebida == 1 ) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                                    girarMotorAoContrarioSexta(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                                } //else if (SextaRecebida == 1 )
                                                      
                                                      
                                                                  //SE SÃBADO RECEBIDA
                                                                  else if (SabadoRecebida == 1 ) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SÃBADO");
                                                                    girarMotorAoContrarioSabado(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                                } //else if (SabadoRecebida == 1 )
                                                      
                                                      
                                                      
                                                                  //SE DOMINGO RECEBIDA
                                                                  else if (DomingoRecebida == 1 ) {
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                                    girarMotorAoContrarioDomingo(10);
                                                                    Serial.print("ESPEROU 5 SECUNDOS");
                                                                    delay (5000);
                                                                    Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
                                                                    girarMotorQuarta(10);
                                                                    QuartaRecebida = 1;
                                                                                      } //else if (DomingoRecebida == 1 )
                                                                  
    }//17
 
 
    else if (expectingTimeCommand) { // 18
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//19
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//20
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//21
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//21
 
   
              Serial.print("BOTÃƒO: QUARTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUARTA-FEIRA");
              girarMotorQuarta(10);
              QuartaRecebida = 1;
               //else  
           

          }//20
           else {//22
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//22
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//19
      } //18
      else {//23
        Serial.println("Comando invÃ¡lido recebido apÃ³s QUARTA.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//23
    



                        
                        
    // BOTÃƒO: QUINTA-FEIRA 
    if (received == "QUINTA-FEIRA" && rtc.now().dayOfTheWeek() == 4) {//24
      Serial.println("DIA ESCOLHIDO: QUINTA!");
      QuintaRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 

                                                                          //SE SEGUNDA RECEBIDA
                                                                          if (SegundaRecebida == 1) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                                            girarMotorAoContrarioSegunda(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                  } //if (TercaRecebida == 1)
                                                              
                                                              
                                                                          //SE TERÃ‡A-RECEBIDA
                                                                          else if  (TercaRecebida == 1) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de TERÃ‡A-FEIRA");
                                                                            girarMotorAoContrarioTerca(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                      } //else if (QuartaRecebida==1)
                                                              
                                                                        
                                                                          //SE QUINTA RECEBIDA
                                                                          else if (QuartaRecebida == 1 ) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                                            girarMotorAoContrarioQuarta(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                        } //else if (QuintaRecebida == 1 )
                                                              
                                                                          //SE SEXTA RECEBIDA
                                                                          else if (SextaRecebida == 1 ) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                                            girarMotorAoContrarioSexta(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                        } //else if (SextaRecebida == 1 )
                                                              
                                                              
                                                                          //SE SÃBADO RECEBIDA
                                                                          else if (SabadoRecebida == 1 ) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SÃBADO");
                                                                            girarMotorAoContrarioSabado(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                        } //else if (SabadoRecebida == 1 )
                                                              
                                                              
                                                              
                                                                          //SE DOMINGO RECEBIDA
                                                                          else if (DomingoRecebida == 1 ) {
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                                            girarMotorAoContrarioDomingo(10);
                                                                            Serial.print("ESPEROU 5 SECUNDOS");
                                                                            delay (5000);
                                                                            Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                                            girarMotorQuinta(10);
                                                                            QuintaRecebida = 1;
                                                                                                        } //else if (DomingoRecebida == 1 )
             
    }//24
 
 
    else if (expectingTimeCommand) { // 25
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//26
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//27
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//28
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//28
 
   
              Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
              girarMotorQuinta(10);
              QuintaRecebida = 1;
               //else  
            // Current time matches chosen time: turn on LED
            //digitalWrite(ledPin, HIGH);
            //Serial.println("Hora atual corresponde Ã  hora escolhida: LED ligado");
 
            // Optional: Wait for a few seconds before turning off the LED
          //  delay(5000);
 
            // Turn off the LED
           // digitalWrite(ledPin, LOW);
          //  Serial.println("LED off");
          } //27
          else {//29
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//29
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//26
      } //25
      else {//30
        Serial.println("Comando invÃ¡lido recebido apÃ³s QUINTA.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//30
    





    // BOTÃƒO: SEXTA-FEIRA 
    if (received == "SEXTA-FEIRA" && rtc.now().dayOfTheWeek() == 5) {//31
      Serial.println("DIA ESCOLHIDO: SEXTA!");
      SextaRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 

                                                //SE SEGUNDA RECEBIDA
                                                if (SegundaRecebida == 1) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                  girarMotorAoContrarioSegunda(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                        } //if (TercaRecebida == 1)
                                    
                                    
                                                //SE TERÃ‡A-RECEBIDA
                                                else if  (TercaRecebida == 1) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de TERÃ‡A-FEIRA");
                                                  girarMotorAoContrarioTerca(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                            } //else if (QuartaRecebida==1)
                                    
                                              
                                                //SE QUINTA RECEBIDA
                                                else if (QuartaRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                  girarMotorAoContrarioQuarta(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: QUINTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE QUINTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                              } //else if (QuintaRecebida == 1 )
                                    
                                                //SE QUINTA RECEBIDA
                                                else if (QuintaRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                  girarMotorAoContrarioQuinta(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                              } //else if (SextaRecebida == 1 )
                                    
                                    
                                                //SE SÃBADO RECEBIDA
                                                else if (SabadoRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de SÃBADO");
                                                  girarMotorAoContrarioSabado(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                              } //else if (SabadoRecebida == 1 )
                                    
                                    
                                    
                                                //SE DOMINGO RECEBIDA
                                                else if (DomingoRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                  girarMotorAoContrarioDomingo(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
                                                  girarMotorSexta(10);
                                                  SextaRecebida = 1;
                                                                              } //else if (DomingoRecebida == 1 )
             
    }//31
 
 
    else if (expectingTimeCommand) { //32
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//33
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//34
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//35
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//35
 
   
              Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:AGORA VAI O DE SEXTA-FEIRA");
              girarMotorSexta(10);
              SextaRecebida = 1;
               //else  

          } //34
          else {//36
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//36
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//33
      }//32 
      else {//37
        Serial.println("Comando invÃ¡lido recebido apÃ³s SEXTA.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//37
    






    // BOTÃƒO: SÃBADO 
    if (received == "SABADO" && rtc.now().dayOfTheWeek() == 6) {//38
      Serial.println("DIA ESCOLHIDO: SÃBADO!");
      SabadoRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 

                                                //SE SEGUNDA RECEBIDA
                                                if (SegundaRecebida == 1) {
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                  girarMotorAoContrarioSegunda(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO-FEIRA");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                        } //if (TercaRecebida == 1)
                                    
                                    
                                                //SE TERÃ‡A-RECEBIDA
                                                else if  (TercaRecebida == 1) {
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de TERÃ‡A-FEIRA");
                                                  girarMotorAoContrarioTerca(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                            } //else if (QuartaRecebida==1)
                                    
                                              
                                                //SE QUINTA RECEBIDA
                                                else if (QuartaRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de QUARTA-FEIRA");
                                                  girarMotorAoContrarioQuarta(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                              } //else if (QuintaRecebida == 1 )
                                    
                                                //SE QUINTA RECEBIDA
                                                else if (QuintaRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SEXTA-FEIRA:"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                  girarMotorAoContrarioQuinta(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                              } //else if (SextaRecebida == 1 )
                                    
                                    
                                                //SE SÃBADO RECEBIDA
                                                else if (SextaRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                  girarMotorAoContrarioSexta(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                              } //else if (SabadoRecebida == 1 )
                                    
                                    
                                    
                                                //SE DOMINGO RECEBIDA
                                                else if (DomingoRecebida == 1 ) {
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                  girarMotorAoContrarioDomingo(10);
                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                  delay (5000);
                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                  girarMotorSabado(10);
                                                  SabadoRecebida = 1;
                                                                              } //else if (DomingoRecebida == 1 )
             
    }//38
 
    else if (expectingTimeCommand) { // 39
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//40
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//41
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//42
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//42
 
   
              Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
              girarMotorSabado(10);
              SabadoRecebida = 1;
               //else  
            // Current time matches chosen time: turn on LED
            //digitalWrite(ledPin, HIGH);
            //Serial.println("Hora atual corresponde Ã  hora escolhida: LED ligado");
 
            // Optional: Wait for a few seconds before turning off the LED
          //  delay(5000);
 
            // Turn off the LED
           // digitalWrite(ledPin, LOW);
          //  Serial.println("LED off");
          }//41
           else {//43
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//43
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//40
      } //39
      else {//44
        Serial.println("Comando invÃ¡lido recebido apÃ³s SEXTA.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//44
    

                        
                        
                        






         // BOTÃƒO: DOMINGO 
    if (received == "DOMINGO" && rtc.now().dayOfTheWeek() == 0) {//45
      Serial.println("DIA ESCOLHIDO: DOMINGO !");
      DomingoRecebida = 1;
      bluetoothConnected = true;
      expectingTimeCommand = true; // We are now expecting the time command
 

                                                                //SE SEGUNDA RECEBIDA
                                                                if (SegundaRecebida == 1) {
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:Voltou o de SEGUNDA-FEIRA");
                                                                  girarMotorAoContrarioSegunda(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                        } //if (TercaRecebida == 1)
                                                    
                                                    
                                                                //SE TERÃÇA-RECEBIDA
                                                                else if  (TercaRecebida == 1) {
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:Voltou o de TERÃ‡A-FEIRA");
                                                                  girarMotorAoContrarioTerca(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                            } //else if (QuartaRecebida==1)
                                                    
                                                              
                                                                //SE QUARTA RECEBIDA
                                                                else if (QuartaRecebida == 1 ) {
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:Voltou o de QUARTA-FEIRA");
                                                                  girarMotorAoContrarioQuarta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                              } //else if (QuintaRecebida == 1 )
                                                    
                                                                //SE QUINTA RECEBIDA
                                                                else if (QuintaRecebida == 1 ) {
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:Voltou o de QUINTA-FEIRA");
                                                                  girarMotorAoContrarioQuinta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                              } //else if (SextaRecebida == 1 )
                                                    
                                                    
                                                                //SE DOMIGO RECEBIDA
                                                                else if (SextaRecebida == 1 ) {
                                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:Voltou o de SEXTA-FEIRA");
                                                                  girarMotorAoContrarioSexta(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃƒO: SÃBADO:"); Serial.println("Comando recebido:AGORA VAI O DE SÃBADO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                              } //else if (SabadoRecebida == 1 )
                                                    
                                                    
                                                    
                                                                //SE DOMINGO RECEBIDA
                                                                else if (SabadoRecebida == 1 ) {
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:Voltou o de DOMINGO");
                                                                  girarMotorAoContrarioSabado(10);
                                                                  Serial.print("ESPEROU 5 SECUNDOS");
                                                                  delay (5000);
                                                                  Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
                                                                  girarMotorDomingo(10);
                                                                  DomingoRecebida = 1;
                                                                                              } //else if (DomingoRecebida == 1 )
             
    }//45
 
 
    else if (expectingTimeCommand) { // 46
      // Check if the received command starts with "time"
      if (received.startsWith("time:")) {//47
        // Extract hour and minute from the command
        int colonIndex = received.indexOf(':');
        if (colonIndex != -1 && received.length() >= colonIndex + 6) {//48
          int chosenHour = received.substring(colonIndex + 1, colonIndex + 3).toInt();
          int chosenMinute = received.substring(colonIndex + 4).toInt();
 
          // Process the time command as before
          DateTime now = rtc.now();
          int currentHour = now.hour();
          int currentMinute = now.minute();
 
          Serial.print("Chosen time: ");
          Serial.print(chosenHour);
          Serial.print(":");
          Serial.println(chosenMinute);
 
          // Check if current time matches chosen time
          while (!(currentHour == chosenHour && currentMinute == chosenMinute)) {//49
            // Keep checking until current time matches chosen time
            now = rtc.now();
            currentHour = now.hour();
            currentMinute = now.minute();
            delay(1000); // Delay to avoid excessive looping
          }//49
 
   
              Serial.print("BOTÃO:DOMINGO :"); Serial.println("Comando recebido:AGORA VAI O DE DOMINGO");
              girarMotorDomingo(10);
              DomingoRecebida = 1;
               //else  
            // Current time matches chosen time: turn on LED
            //digitalWrite(ledPin, HIGH);
            //Serial.println("Hora atual corresponde Ã  hora escolhida: LED ligado");
 
            // Optional: Wait for a few seconds before turning off the LED
          //  delay(5000);
 
            // Turn off the LED
           // digitalWrite(ledPin, LOW);
          //  Serial.println("LED off");
          }//48 
          else {//50
            Serial.println("Hora atual nÃ£o corresponde Ã  hora escolhida.");
          }//50
 
          // Reset the flag since we have processed the time command
          expectingTimeCommand = false;
        }//47
      } //46
      else {//51
        Serial.println("Comando invÃ¡lido recebido após DOMINGO.");
        // Reset the flag since we didn't receive the expected time command
        expectingTimeCommand = false;
      }//51
  

                        
                         } //2
 
 
 
  // Get current time
  DateTime now = rtc.now();
 
  // Send current time and day of the week over Bluetooth
  String currentTime = String(now.hour()) + ":" + String(now.minute());
 
 
  ESP_BT.print("Time: ");
  ESP_BT.println(currentTime);
 
  delay(1000); // Add a short delay to avoid flooding Bluetooth
 
 
    // Show current time on serial monitor
  //DateTime now = rtc.now();
  Serial.print("Dia da semana:");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(" ");
  Serial.print(" - ");
  Serial.print("Horário:");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  Serial.print(" ");
  Serial.print(" - ");
  Serial.print("Data:");
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" -");
   



             } //1
 



 
void girarMotorSegunda(int passos) {
  while(passoAtual < passosSegunda) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
} 


 
void girarMotorTerca(int passos) {
  while(passoAtual < passosTerca) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}
 
 
 
void girarMotorQuarta(int passos) {
  while(passoAtual < passosQuarta) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}
 
 
 
void girarMotorQuinta(int passos) {
  while(passoAtual < passosQuinta) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}
 

void girarMotorSexta(int passos) {
  while(passoAtual < passosSexta) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}



void girarMotorSabado(int passos) {
  while(passoAtual < passosSabado) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}


void girarMotorDomingo(int passos) {
  while(passoAtual < passosDomingo) {
    for (int i = 0; i < passos; i++) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
     
      passoAtual++;
    }
  }
}

void girarMotorAoContrarioSegunda(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
} //

 
 
void girarMotorAoContrarioTerca(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}
 
 
void girarMotorAoContrarioQuarta(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}
 
 
 
void girarMotorAoContrarioQuinta(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}
 
 
 
void girarMotorAoContrarioSexta(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}
 
 
void girarMotorAoContrarioSabado(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}
 
 
void girarMotorAoContrarioDomingo(int passos) {
   while (passoAtual > 0) {
    for (int i = 0; i < passos; i++) {
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(velocidade);
     
      passoAtual--;
    }
  }
}






