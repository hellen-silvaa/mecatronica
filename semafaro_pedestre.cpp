// Declarando as variáveis
int vermelho1= 10;
int amarelo1= 9;
int verde1= 8;
int vermelho2= 7;
int amarelo2= 6;
int verde2= 5;
int pvermelho3=12;
int pverde3=11;
int pvermelho4=1;
int pverde4=0;
int botao1=3;
int botao2=2;

void setup() {
  //Informações dos pino utilizado no arduino
 //saída (OUTPUT) ou entrada (INPUT)
  pinMode(vermelho1, OUTPUT);
  pinMode(amarelo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  
  pinMode(vermelho2, OUTPUT);
  pinMode(amarelo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  
  pinMode(pvermelho3, OUTPUT);
  pinMode(pverde3, OUTPUT);
  
  pinMode(pvermelho4, OUTPUT);
  pinMode(pverde4, OUTPUT);
  
  pinMode(botao1, INPUT); 
  pinMode(botao2, INPUT);
}

void loop(){
 
  digitalWrite(verde1, HIGH); // Inicia com led verde1 carro  acesso
  digitalWrite(verde2, HIGH); // Inicia com led verde2 carro  acesso
  digitalWrite(pvermelho3, HIGH);  // Inicia com led vermelho do pedestre acesso 
  digitalWrite(pvermelho4, HIGH);  // Inicia com led vermelho do pedestre acesso
  digitalWrite(amarelo1, LOW);     //Inicia com led amarelo1 carro  apagado
  digitalWrite(amarelo2, LOW);     //Inicia com led amarelo2 carro  apagado
  delay (2000);


void espera () 
 
for (int cnt=0; cnt<500; cnt++);
    {
   delay (1);
if ((DigitalRead (2))||((DigitalRead (3)))
     {
   if 
   digitalWrite(vermhlo1, LOW);
   digitalWrite(vermelho2, LOW);
   digitalWrite(pverde3, HIGH);
   digitalWrite(pverde4, HIGH);
   delay (3000);
   digitalWrite(pverde3, LOW);
   digitalWrite(pverde4, LOW);
break;
   
     }        
  }
    
 
  	
    digitalWrite(verde1, LOW);       // Desligue verde1
    digitalWrite(verde2, LOW);       // Desligue verde2
  	digitalWrite(vermelho1, LOW);       // Desligue vermelho1
    digitalWrite(vermelho2, LOW);       // Desligue vermelho2
    
    digitalWrite(amarelo1, HIGH);    //Acenda o amarelo1
    digitalWrite(amarelo2, HIGH);    //Acenda o amarelo2
  	delay(1000);                         // por 1 segundo
  	digitalWrite(amarelo1, LOW);     //depois apaga
    digitalWrite(amarelo2, LOW);     //depois apaga
  	      
    digitalWrite(vermelho1, HIGH);   //Liga o vermelho1 carro
    digitalWrite(vermelho2, HIGH);   //Liga o vermelho2 carro
    
    digitalWrite(pverde3, HIGH);   //Liga o verde3 pedestre
    digitalWrite(pverde4, HIGH);   //Liga o verde4 pedestre
    
    digitalWrite(amarelo1, HIGH);    //Acenda o amarelo1
    digitalWrite(amarelo2, HIGH);    //Acenda o amarelo2
    delay(1000); 
    digitalWrite(pverde3, LOW);   //Desliga o verde3 pedestre
    digitalWrite(pverde4, LOW);   //Desliga o verde4 pedestre
    
    
    delay(2000);                         //Tempo de 2 segundos para acender o do pedestre
    
    // Iremos fazer um FOR até 3, cada rodada vai demorar 1 segundo, no total de 3 segundos
    for(int y=0; y<5; y++){         
      digitalWrite(pvermelho3, LOW);
      digitalWrite(pvermelho4, LOW);
      digitalWrite(amarelo1, LOW);     //depois apaga
      digitalWrite(amarelo2, LOW);     //depois apaga
   	  digitalWrite;(pverde3, HIGH);
      digitalWrite;(pverde4, HIGH);
      delay(3000);
    }
    
    // Iremos fazer um FOR até 5, cada rodada vai demorar 1 segundo, no total de 5 segundos
    for(int x=0; x<5; x++){
      digitalWrite;(pverde3, HIGH);
      digitalWrite(pvermelho3, HIGH);
      delay(500);
      digitalWrite(pvermelho3,LOW);

      digitalWrite;(pverde4, HIGH);
      digitalWrite(pvermelho4, HIGH);
      delay(500);
      digitalWrite(pvermelho4, LOW);
      delay(500);
     
    
    digitalWrite(pvermelho3, HIGH);
    digitalWrite(pvermelho4, HIGH);
   	}
    delay(3000); // Tempo entre o desligamento do sinal do pedestre para o ligamento do sinal dos carros
    
    digitalWrite(vermelho1, LOW);
    digitalWrite(vermelho2, LOW);
  	digitalWrite(verde1, HIGH);       // Desligue verde1
    digitalWrite(verde2, HIGH);       // Desligue verde1
    
    delay(5000); // Tempo que o botão vai ficar inativo até que outro pedestre acione
  }
    }

  
