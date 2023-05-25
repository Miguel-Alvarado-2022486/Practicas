/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 7 | Uso de sensores y sus aplicaciones 
*/

#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h> 

#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define rcw 8
#define boton 2

OneWire ourWire(12);
DallasTemperature sensors(&ourWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void sen_presencia(int presencia, int buzz);
void temperatura(int R, int G, int B);

Servo servo;
int buzz = 11;
int posicion = 90;

void setup() {  
  entrada(boton);
  lcd.init();
  lcd.backlight();
  sensors.begin();
  servo.attach(9);
}

void loop() { 
  temperatura(11,10,8);
  sen_presencia(3,4);
  bool lectura_boton = digitalRead(boton); 
  delay(100);
  if (lectura_boton == true)
  {
    servo.write(270);  
    lcd.setCursor(8,0);
    lcd.print("ON ");  
    delay(100);
  }
  else if(lectura_boton == false )
  {
    servo.write(90);
    lcd.setCursor(8,0);
    lcd.print("OFF");
    delay(100);
  }
  
}
  

void temperatura(int R, int G, int B)
{
  delay(50);
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
    lcd.setCursor(0, 0);
    lcd.print("C:");
    lcd.print(tempC);
    lcd.setCursor(7, 0);
    lcd.print("|");
    salida(R);
    salida(G);
    salida(B);
  
  if (tempC >= 15.00 && tempC <= 21.00)
  {
    alto(R);
    bajo(G);
    alto(B);

    lcd.setCursor(0, 0);
    lcd.print("C:");
    lcd.print(tempC);
    lcd.setCursor(7, 0);
    lcd.print("|");
  }
  else if (tempC >= 22 && tempC <= 25)
  {
    bajo(R);
    alto(G);
    bajo(B);
    
    lcd.setCursor(0, 0);
    lcd.print("C:");
    lcd.print(tempC);
    lcd.setCursor(7, 0);
    lcd.print("|");
  }
  else if (tempC > 25 && tempC <= 45)
  {
    alto(R);
    bajo(G);
    bajo(B);
    
    lcd.setCursor(0, 0);
    lcd.print("C:");
    lcd.print(tempC);
    lcd.setCursor(7, 0);
    lcd.print("|");
  }
}


void sen_presencia(int presencia, int buzz)
{
  int ledd = 3;
  entrada(ledd);
  salida(buzz);
  entrada(presencia);
  bool lectura_ledd = digitalRead(ledd);
  if (ledd == HIGH)
  {
    tone(buzz, 523.25, 500);
    delay(500); 
    lcd.setCursor(0,1);
    lcd.print("Correct");
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Failed ");
    noTone(buzz);
  }
}
