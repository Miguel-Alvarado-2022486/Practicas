/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 6.3 | Alarma de distancia
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT)
#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
int buzz = 12;
LiquidCrystal_I2C lcd(0x27,16,2);

int duracion ;
int distancia;

void luces(int led2, int led3,  int led4,  int led5, int led6,  int led7,
           int led8,  int led9, int ledA0,  int ledA1);
void alarma_de_distancia(int buzz);
void ultrasonico(int trigg, int echo);

void setup()
{
  lcd.init();    
  lcd.backlight();
}

void loop()
{
  
  luces(2, 3, 4, 5, 6, 7, 8, 9, A0, A1);
  alarma_de_distancia(12);
  ultrasonico(11,10);  
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
  delay(0);
}

////////////////////


void alarma_de_distancia(int buzz)
{  
 float i;
  if (distancia >= 45 )
  { 
    noTone(buzz);
    lcd.setCursor(0,0);
    lcd.print("Fuera de alcance");
  }
  
  
  if (distancia >=30 && distancia <43)
  { 
    noTone(buzz);
    lcd.setCursor(0,0);
    lcd.print("Acercandose");
  }

  if (distancia >= 20 && distancia < 28)
  { 
    lcd.setCursor(0,0);
    lcd.print("Cuidado, peligro");
    for(i=1046.50;i<1300;i+=150) {
    tone(buzz,i, 50);
    delay(50);
    }
  }

  if(distancia >= 1 && distancia <10 )
  {       
    lcd.setCursor(0,0);
    lcd.print("Violando espacio");
    for(i=1046.50;i<1300;i+=180) {
    tone(buzz,i, 50);
    delay(50);
  }
}   
}


///////

void luces(int led2, int led3,  int led4,  int led5, int led6,  int led7,
           int led8,  int led9, int ledA0,  int ledA1){
    if(distancia >= 51)
    {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=45 && distancia <=50){
      alto(led9);
      delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }
    if(distancia >=40 && distancia <=44){
      alto(led9);
      alto(led8);
      delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=35 && distancia <=39){
      alto(led9);
      alto(led8);
      alto(led7);
      delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=30 && distancia <=34){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
     delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=25 && distancia <=29){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=20 && distancia <=24){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      alto(led4);
      delay(150);
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=15 && distancia <=19){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      alto(led4);
      alto(led3);
      delay(150); 
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=10 && distancia <=14){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      alto(led4);
      alto(led3);
      alto(led2);
      delay(150); 
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }

    if(distancia >=5 && distancia <=9 && distancia != 0){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      alto(led4);
      alto(led3);
      alto(led2);
      alto(ledA0);
      delay(150); 
      }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0); 
      delay(0);
    }

    if(distancia >=1 && distancia <=4 && distancia != 0){
      alto(led9);
      alto(led8);
      alto(led7);
      alto(led6);
      alto(led5);
      alto(led4);
      alto(led3);
      alto(led2);
      alto(ledA0);
      alto(ledA1);
      delay(150); 
    }
    else {
      bajo(led2);    
      bajo(led3);    
      bajo(led4);    
      bajo(led5);    
      bajo(led6);    
      bajo(led7);
      bajo(led8);    
      bajo(led9);    
      bajo(ledA0);    
      bajo(ledA1);
      delay(0);
    }
    
  }
