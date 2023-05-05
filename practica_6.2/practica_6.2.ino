/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: PRACTICA 6.2 | CONTADOR DE AFORO CON ANIMACION
*/
#include <LiquidCrystal.h>
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT)
#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
  int distancia = 0; 
  int duracion;
  int paso;

void ultrasonico(int trigg, int echo);
void alarma(int buzz);

LiquidCrystal lcd_migul(5,4,6,7,8,9);
byte cuadro[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00111,
  B00111,
  B00111
};

byte cuadro1[] = {
  B00000,
  B00000,
  B11100,
  B11100,
  B11100,
  B00000,
  B00000,
  B00000
};

byte flecha[] = {
  B00000,
  B01100,
  B00010,
  B00111,
  B11111,
  B00111,
  B00010,
  B01100
};

void setup() 
{ 
  
  lcd_migul.begin(16,2);
  lcd_migul.createChar(1,flecha);  
  lcd_migul.createChar(2,cuadro); 
  lcd_migul.createChar(3,cuadro1); 
}


void loop() 
{
  ultrasonico(11,10);
  ultrasonico(11,10);
  alarma(12);
}



void alarma(int buzz)
{
  lcd_migul.begin(16,2); 

  // Aforo sin personas
  if(distancia >=6 && paso ==0)
  {
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 0");
   }

    // Inicio de bucle de aforo
  if(distancia>=6 && distancia <=10)
  {
    delay(150);
    paso++;
   

    // Persona 1
  if(distancia>=6 && distancia <= 10 && paso == 1)
  {
    noTone(buzz);    
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 1");
    delay(150);
    paso++;
    
  }
   // Persona 2
 if(distancia>=6 && distancia <= 10 && paso == 3)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 2");
    delay(150);
    paso++;
  }

  // Persona 3
 if(distancia>=6 && distancia <= 10 && paso == 5)
  {
     noTone(buzz); 
     lcd_migul.clear();
     lcd_migul.setCursor(2,0);
     lcd_migul.write("Personas: 3");
     delay(150);
     paso++;
  }

  // Persona 4
  if(distancia>=6 && distancia <= 10 && paso == 7)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 4");
    delay(150);
    paso++;
  }
  // Persona 5
 if(distancia>=6 && distancia <= 10 && paso == 9)
  { 
     noTone(buzz);
     lcd_migul.clear();
     lcd_migul.setCursor(2,0);
     lcd_migul.write("Personas: 5");
     delay(150);
     paso++;
  }

  // Persona 6
  if(distancia>=6 && distancia <= 10 && paso == 11)

  {
     noTone(buzz);
     lcd_migul.clear();
     lcd_migul.setCursor(2,0);
     lcd_migul.write("Personas: 6");
     delay(150);
     paso++;
  }

  // Persona 7
  if(distancia>=6 && distancia <= 10 && paso == 13)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 7");
    delay(150);
    paso++;
  }

  // Persona 8
  if(distancia>=6 && distancia <= 10 && paso == 15)
  {  
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 8");
    delay(150);
    paso++;
  }
  
  // Persona 9
  if(distancia>=6 && distancia <= 10 && paso == 17)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 9");
    delay(150);
    paso++;
  }

  // Persona 10
  if(distancia>=6 && distancia <= 10 && paso == 19)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 10");
    delay(150);
    paso++;
  }

  // Persona 11
  if(distancia>=6 && distancia <= 10 && paso == 21)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 11");
    delay(150);
    paso++;
  }

  // Persona 12
  if(distancia>=6 && distancia <= 10 && paso == 23)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 12");
    delay(150);
    paso++;
  }

  // Persona 13
  if(distancia>=6 && distancia <= 10 && paso == 25)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 13");
    delay(150);
    paso++;
  }

  // Persona 14
  if(distancia>=6 && distancia <= 10 && paso == 27)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 14");
    delay(150);
    paso++;
  }

  // Persona 15
  if(distancia>=6 && distancia <= 10 && paso == 29)
  {
    noTone(buzz);
    lcd_migul.clear();
    lcd_migul.setCursor(2,0);
    lcd_migul.write("Personas: 15");
    delay(150);
    paso++;
  }

  // Persona 16
  if(distancia>=6 && distancia <= 10 && paso == 31)
  {
    // Oops | + x
    tone(buzz, 1244.51, 400); // D#
    lcd_migul.setCursor(2,0);  
    lcd_migul.print("Aforo lleno");
    delay(500);
    tone(buzz, 1396.91, 400); // F
    lcd_migul.setCursor(0,1);  
    lcd_migul.write(1);
    delay(500);
    
    lcd_migul.setCursor(1,1);
    lcd_migul.write(1);
    delay(500);

    tone(buzz, 1108.73, 400); // C#
    lcd_migul.setCursor(2,1);  
    lcd_migul.write(1);
    delay(500);
    
    tone(buzz, 1479.98, 400); // F#
    lcd_migul.setCursor(3,1);
    lcd_migul.write(1);
    delay(500);

   
    tone(buzz,  1661.22, 400); // G#
    delay(250);
    lcd_migul.setCursor(4,1);  
    lcd_migul.write(1);
    tone(buzz, 1864.66, 400); // A#
    delay(250);
    
    tone(buzz,  1661.22, 400); // G#
    delay(250);
    lcd_migul.setCursor(5,1);
    lcd_migul.write(1);
    tone(buzz, 1479.98, 400); // F#
    delay(250);

    tone(buzz, 1244.51, 400); // D#
    lcd_migul.setCursor(6,1);  
    lcd_migul.write(1);
    delay(250);

    tone(buzz, 2217.46, 400); // C#
    lcd_migul.setCursor(7,1);
    lcd_migul.write(1);
    delay(500);

    tone(buzz, 1864.66, 1000); // A#
    lcd_migul.setCursor(8,1);  
    lcd_migul.write(1);   
    delay(1000);

    tone(buzz, 1244.51, 400); // D#
    lcd_migul.setCursor(9,1);
    lcd_migul.write(1);
    delay(500);

    tone(buzz,  1661.22, 400); // G#
    lcd_migul.setCursor(10,1);  
    lcd_migul.write(1);
    delay(500);

    tone(buzz,  1661.22, 400); // G#
    lcd_migul.setCursor(11,1);
    lcd_migul.write(1);
    delay(250);

    tone(buzz, 1864.66, 400); // A#
    delay(250);
    tone(buzz,  1661.22, 400); // G#
    lcd_migul.setCursor(12,1);  
    lcd_migul.write(1);
    delay(250);

    tone(buzz, 1479.98, 400); // F#
    delay(250);
    tone(buzz, 1244.51, 400); // D#
    lcd_migul.setCursor(13,1);
    lcd_migul.write(1);
    delay(250);

    tone(buzz, 2217.46, 400); // C#
    lcd_migul.setCursor(14,1);  
    lcd_migul.write(1);
    delay(500);

    tone(buzz, 1864.66, 1000); // A#
    lcd_migul.setCursor(15,1);
    lcd_migul.write(1);
    delay(1000);
    paso++;
    
    
  }
  if(distancia>=6 && distancia <= 10 && paso > 32)
  {
    lcd_migul.clear();
    paso = 0;
    lcd_migul.setCursor(5,0);  
    lcd_migul.print("Nulo");

    tone(buzz, 1479.98, 500); // F#
    lcd_migul.setCursor(15,1);
    lcd_migul.write(2);
    delay(500);

    tone(buzz, 1661.22, 500); // G#
    lcd_migul.setCursor(14,1);
    lcd_migul.write(3);
    delay(500);

    tone(buzz, 1479.98, 500); // F#
    lcd_migul.setCursor(13,1);
    lcd_migul.write(2);
    delay(500);

    tone(buzz, 1396.91, 500); // F
    lcd_migul.setCursor(12,1);
    lcd_migul.write(3);
    delay(500);

    tone(buzz, 1479.98, 1000); // F#
    lcd_migul.setCursor(11,1);
    lcd_migul.write(2);
    delay(1000);

    tone(buzz, 1244.51, 2000); // D#
    lcd_migul.setCursor(10,1);
    lcd_migul.write(3);
    delay(2000);

    tone(buzz, 1108.73, 400); // C#
    lcd_migul.setCursor(9,1);
    lcd_migul.write(2);
    delay(250);

    tone(buzz, 1046.50, 2000); // C
    lcd_migul.setCursor(8,1);
    lcd_migul.write(3);
    delay(2000);
    
  tone(buzz, 311.13, 400); // D#
    lcd_migul.setCursor(7,1);
    lcd_migul.write(2);
    delay(250);

    tone(buzz, 554.37, 400); // C#
    lcd_migul.setCursor(6,1);
    lcd_migul.write(3);
    delay(250);

    tone(buzz, 622.25, 500); // D#
    lcd_migul.setCursor(5,1);
    lcd_migul.write(2);
    delay(500);

    tone(buzz, 698.46, 2000); // F
    lcd_migul.setCursor(4,1);
    lcd_migul.write(3);
    delay(2000);
  } 
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
  delay(500);
}
