/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 6.5 | Termometro
*/
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
#define salida(pin) pinMode(pin,OUTPUT)

#define sensor 2
#define rojo  3
#define azul  4
#define amarillo  5
OneWire ourWire(sensor);
DallasTemperature sensors(&ourWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  salida(rojo);
  salida(azul);
  salida(amarillo);
  lcd.init();
  lcd.backlight();
  sensors.begin();
}

void loop()

{
  temper();
}



void temper()
{
  
sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  float tempF = sensors.getTempFByIndex(0);
  if (tempC >= 30.00 && tempC <= 50.00)
  {
    alto(rojo);
    bajo(azul);
    bajo(amarillo);

    lcd.setCursor(0, 0);
    lcd.print("temp. C: ");
    lcd.print(tempC);
    lcd.setCursor(0, 1);
    lcd.print("temp. F: ");
    lcd.print(tempF );
  }
  else if (tempC >= 15 && tempC <= 29)
  {
    bajo(rojo);
    bajo(azul);
    alto(amarillo);
    lcd.setCursor(0, 0);
    lcd.print("Grados en C: ");
    lcd.print(tempC);
    lcd.setCursor(0, 1);
    lcd.print("Grados en F: ");
    lcd.print(tempF );
  }
  else if (tempC >= -5 && tempC <= 14)
  {
    bajo(rojo);
    alto(azul);
    bajo(amarillo);
    lcd.setCursor(0, 0);
    lcd.print("Grados en C: ");
    lcd.print(tempC);
    lcd.setCursor(0, 1);
    lcd.print("Grados en F: ");
    lcd.print(tempF );
  }
  
}
