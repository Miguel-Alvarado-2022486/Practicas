/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: PRACTICA 5 | Piano con Buzzer 
*/

#define salida(pin) pinMode(pin, HIGH)
#define entrada(pin) pinMode(pin, INPUT)
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW)

  int distancia = 0; 
  int duracion;
  


void ultrasonico(int trigg, int echo);
void piano(int buzz, long c,long d,long  e,long f, long g,long a,long b);



void setup() 
{ 
Serial.begin(9600);
}

void loop() 
{
  ultrasonico(4,3);

  piano( 2, 261.63, 293.67, 329.63, 349.23, 392.00, 440.00 , 493.88 );
  
}


void piano(int buzz, long c,long d,long  e,long f, long g,long a,long b)
{
  
  if(distancia>=0 && distancia <= 5)
  {
    tone(buzz, c,500);
    delay(700);
    noTone(buzz);
  }
  
 if(distancia>5 && distancia <= 10)
  {
    tone(buzz, d,500);
    delay(700);
    noTone(buzz);
  }

 if(distancia>10 && distancia <= 15)
  {
    tone(buzz, e,500);
    delay(700);
    noTone(buzz);    
  }

  if(distancia>15 && distancia <=20)
  {
    tone(buzz, f,500);
    delay(700);
    noTone(buzz);
  }

 if(distancia>20 && distancia <= 25)
  {
    tone(buzz, g,500);
    delay(700); 
    noTone(buzz);
  }

 if(distancia>25 && distancia <= 30)
  {
    tone(buzz, a,500);
    delay(700);
    noTone(buzz);
  }

  if(distancia>30 && distancia <= 35)
  {
    tone(buzz, b,500);
    delay(700);
    noTone(buzz);
  }
}
void ultrasonico(int trigg, int echo)
{
  
  salida(trigg);
  entrada(echo);
  bajo(trigg);
  delay(10);
  alto(trigg);
  delay(2);
  bajo(trigg);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion*0.034 / 2;
  Serial.println(distancia);
  delay(150);
}
