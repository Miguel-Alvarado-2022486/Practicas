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
Proyecto: Practica 3.1 | CONTROL DE UN LED RGB POR MEDIO DE BOTONES
*/
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW)
#define entrada(pin) pinMode(pin, INPUT)
#define salida(pin) pinMode(pin, OUTPUT)
#define leer(pin) digitalRead(pin)
#define boton0 2
#define boton1 3
#define ledR 4
#define ledG 5
#define ledB 6  
void setup() {
  entrada(boton0);
  entrada(boton1);
  salida(ledR);
  salida(ledG);
  salida(ledB);
}

void loop() {
  bool lectura_boton0 = leer(boton0);
  bool lectura_boton1 = leer(boton1);

  if((lectura_boton0 == false) && (lectura_boton1 == false))// sin botones
  {
      alto(ledR);
      delay(500);
      bajo(ledR);
      delay(0);
      alto(ledG);
      delay(500);
      bajo(ledG);
      delay(0);
      alto(ledB);
      delay(500);
      bajo(ledB);
      delay(0);
  }
  if(lectura_boton0 == true && lectura_boton1 == false) // primer boton
  {
  alto(ledR);
  alto(ledG);
  
  }
  else 
  {
    bajo(ledR);
    bajo(ledG);
    bajo(ledB);
  }

  if(lectura_boton1 == true && lectura_boton0 == false) //segundo boton
  {

  alto(ledG);
  alto(ledB);
  }
  else 
  {
    bajo(ledG);
    bajo(ledB);
    bajo(ledR);
  }
  if(lectura_boton0 == true && lectura_boton1 == true) //dos botones al mismo tiempo
  {
    alto(ledR);
    alto(ledB); 
  }
  else
  {
    bajo(ledR);
    bajo(ledG);
    bajo(ledB);
    
  }
  
}
