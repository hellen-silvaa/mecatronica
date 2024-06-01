int Bo1= 3;
int Bo2= 2;
int Motor=9;  
bool E_B1= 0;
bool E_B2= 0;  
int Ton=100;
int Toff= 0;

void setup ()
{

  pinMode (Bo1, INPUT);
  pinMode (Bo2, INPUT);
  Serial.begin (9600);

}

void loop ()
 {

  E_B1 = digitalRead (Bo1);
  if(digitalRead(2)==1);
 { 

   Ton +1;
   Toff-1;
   if (Ton >=100)
 {

   Ton= 100;
   Toff=0;
  }

    

  {

    E_B1 = digitalRead (Bo1);
  }


  }

    E_B2 = digitalRead (Bo2);
    if(digitalRead(3)==1);
 {

   Ton --;
   Toff++;
   if (Ton <= 100)
 {

   Ton= 50;
   Toff=0;

  }

  }
  Serial.println (Ton);

digitalWrite (0, HIGH);
_delay_us (Ton);
digitalWrite (9, LOW);
_delay_us (Toff);
}
