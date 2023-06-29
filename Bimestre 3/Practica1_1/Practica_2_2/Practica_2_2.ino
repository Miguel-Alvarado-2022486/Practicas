/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 2.2 | Ohmimetro
*/

//Librerias
#include <LiquidCrystal.h>

//Pines
#define v1 A2

//Constructor de LCD
LiquidCrystal pantalla(2,3,4,5,6,7);

void setup()
{
  pantalla.begin(16,2);
  Serial.begin(9600);
  pinMode(v1, INPUT);
}

void loop()
{
  //Operaciones para ohmimetro
  float lectura_v1 = analogRead(v1);
  float rango_v1 = map(lectura_v1, 0, 1023, 0, 1023);
  float voltaje_caida = ((rango_v1)*(5))/(1023);
  float valor1 = (voltaje_caida*10000);
  float valor2 = 50000-valor1;
  float valor3 = valor2 / voltaje_caida;

  Serial.println(voltaje_caida);
  Serial.println(rango_v1);
  Serial.println(valor2);
  Serial.println(valor3);
  pantalla.setCursor(0,0);
  pantalla.print("Resistencia: ");
  pantalla.setCursor(0,1);
  pantalla.print(valor3);
  delay(500);
}
