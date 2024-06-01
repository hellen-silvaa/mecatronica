int Vd1 = 11;
int Am1 = 12; 
int Vm1 = 13;
int Vd2 = 8;
int Am2 = 9;
int Vm2 = 10;
int PVm1 = 7; 
int PVd1 = 6;
int PVm2 = 5; 
int PVd2 = 4;
int Botao1 = 3;
int Botao2 = 2; 
 
void setup () 
{ 
  pinMode (Vd1, OUTPUT);
  pinMode (Am1, OUTPUT); 
  pinMode (Vm1, OUTPUT); 
  pinMode (Vd2, OUTPUT);
  pinMode (Am2, OUTPUT);
  pinMode (Vm2, OUTPUT); 
  pinMode (PVm1, OUTPUT);
  pinMode (PVd1, OUTPUT); 
  pinMode (PVm2, OUTPUT);
  pinMode (PVd2, OUTPUT);
  pinMode (Botao1, INPUT); 
  pinMode (Botao2, INPUT); 
} 
 
 	void loop () 
{ 
 digitalWrite (5, HIGH);
 digitalWrite (7, HIGH); 
 digitalWrite (5, HIGH); 
 digitalWrite (10, HIGH);
 digitalWrite (11, HIGH);
 delay (2000);
 digitalWrite (11, LOW);
 digitalWrite (12, HIGH);
 delay (2000);
 digitalWrite (12, LOW);
 digitalWrite (13, HIGH);
 delay (2000);
 digitalWrite (10, LOW);
 digitalWrite (8, HIGH);
 delay (2000);
 digitalWrite (8, LOW);
 digitalWrite (9, HIGH);
 delay (2000);
 digitalWrite (9, LOW);
 digitalWrite (10, HIGH);
 delay (2000);
 digitalWrite (13, LOW);
 delay (2000); 
  }
 
void espera ()
{ 
for (int x=0; x<500; x++) 
  { 
  delay (1); 
    
if(digitalRead(2)==HIGH||(digitalRead(3)==HIGH)) 
       {           
  digitalWrite (13, LOW);
  digitalWrite (11, HIGH); 
  digitalWrite (11, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (12, LOW); 
  digitalWrite (13, HIGH);
  digitalWrite (10, LOW); 
  digitalWrite (8, HIGH); 
  digitalWrite (8, LOW);  
  digitalWrite (9, HIGH); 
  digitalWrite (9, LOW);  
  digitalWrite (10, HIGH);
  digitalWrite (5, LOW); 
  digitalWrite (7, LOW); 
  digitalWrite (6, HIGH);
  digitalWrite (4, HIGH); 
  delay (3000);  
  digitalWrite (6, LOW);
  digitalWrite (4, LOW); 
  digitalWrite (5, HIGH);
  digitalWrite (7, HIGH); 
      } 
  } 
} 
  void fecha_1() 
{ 
  digitalWrite (13, LOW);
    digitalWrite (11, HIGH); 
    delay (1000); 
    digitalWrite (11, LOW); 
    digitalWrite (12, HIGH);
    delay (1000); 
    digitalWrite (12, LOW); 
    digitalWrite (13, HIGH);
    espera (); 
}            
     void fecha_2() 
{ 
  digitalWrite (10, LOW); 
    digitalWrite (8, HIGH); 
    delay (1000);
    digitalWrite (8, LOW); 
    digitalWrite (9, HIGH); 
    delay (1000); 
    digitalWrite (9, LOW);   
    digitalWrite (10, HIGH);  
    delay (1000);     
} 
 
 
  void abre_p ()
{
 
  digitalWrite (5, LOW); 
    digitalWrite (7, LOW); 
    digitalWrite (6, HIGH);
    digitalWrite (4, HIGH);
    delay (1000);
} 
     
  void fecha_p() 
{ 
  digitalWrite (6, LOW); 
  digitalWrite (4, LOW);
  digitalWrite (5, HIGH);
  digitalWrite (7, HIGH);
  delay (1000); 
}   
