/*
Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Practica 3.2 | SECUENCIA DE LUCES AUTOMATICAS
*/
#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW) 
void setup() 
{
  for(int led = 11; led >=2; led--) // Modificar las salidas
  {
    salida(led);
  }
}

void loop()
{
  for(int led = 11; led>=2; led--) 
  {
    alto(led);
    delay(80);
    bajo(led);
  }

  for(int led = 3; led<=10; led++)
  {
    alto(led);
    delay(80);
    bajo(led);
  }
  
}
