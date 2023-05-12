/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 6.4 | Sensor de parqueo
*/
int distancia;
int duracion;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT)
#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
LiquidCrystal_I2C lcd(0x27,16,2);
void ultrasonico(int trigg, int echo);
byte cuadro[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup()
{
  lcd.init();    
  lcd.backlight();
  lcd.createChar(1, cuadro);
}

void loop()
{
  ultrasonico(11,10);  
  sensor();
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

void sensor()
{
  if(distancia >= 45 && distancia <= 50)
  {   
   lcd.setCursor(7,0);
   lcd.print("50");
   lcd.setCursor(5,1);
   lcd.print("Libre     ");
   lcd.setCursor(0,0);
   lcd.write(1); 
   lcd.setCursor(1,0);
   lcd.write(1);
   lcd.setCursor(2,0);
   lcd.write(1);
   lcd.setCursor(13,0);
   lcd.write(1); 
   lcd.setCursor(14,0);
   lcd.write(1);
   lcd.setCursor(15,0);
   lcd.write(1);  
  }
  if(distancia >= 30 && distancia <= 35)
  {
   lcd.setCursor(7,0);
   lcd.print("30"); 
   lcd.setCursor(5,1);
   lcd.print("Cuidado   ");
   lcd.setCursor(0,0);
   lcd.write(1); 
   lcd.setCursor(1,0);
   lcd.write(1);
   lcd.setCursor(2,0);
   lcd.write(1);
   lcd.setCursor(3,0);
   lcd.write(1);
   lcd.setCursor(4,0);
   lcd.write(1);
   lcd.setCursor(11,0);
   lcd.write(1); 
   lcd.setCursor(12,0);
   lcd.write(1); 
   lcd.setCursor(13,0);
   lcd.write(1); 
   lcd.setCursor(14,0);
   lcd.write(1);
   lcd.setCursor(15,0);
   lcd.write(1);  
  }

  if(distancia >= 10 && distancia <= 15)
  {
   lcd.setCursor(7, 0);
   lcd.print("10"); 
   lcd.setCursor(5, 1);
   lcd.print("Alto      "); 
   lcd.setCursor(0,0);
   lcd.write(1); 
   lcd.setCursor(1,0);
   lcd.write(1);
   lcd.setCursor(2,0);
   lcd.write(1);
   lcd.setCursor(3,0);
   lcd.write(1);
   lcd.setCursor(4,0);
   lcd.write(1);
   lcd.setCursor(5,0);
   lcd.write(1);
   lcd.setCursor(6,0);
   lcd.write(1);
   lcd.setCursor(9,0);
   lcd.write(1);
   lcd.setCursor(10,0);
   lcd.write(1);
   lcd.setCursor(11,0);
   lcd.write(1); 
   lcd.setCursor(12,0);
   lcd.write(1); 
   lcd.setCursor(13,0);
   lcd.write(1); 
   lcd.setCursor(14,0);
   lcd.write(1);
   lcd.setCursor(15,0);
   lcd.write(1); 
  }
}
