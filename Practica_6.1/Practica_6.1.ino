/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: PRACTICA 6.1 | LCD
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd_miguel(5,4,6,7,8,9); 
void setup()
{
  lcd_miguel.begin(16,2);
  lcd_miguel.setCursor(0,0);
  lcd_miguel.write("Miguel");
  lcd_miguel.setCursor(0,1);
  lcd_miguel.write("2022486");
}
void loop()
{
}
