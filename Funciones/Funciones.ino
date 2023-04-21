/*
Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profesor: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto:Práctica 3.3 | USO DEL TECLADO MATRICIAL EN UN DISPLAY DE 7 SEGMENTOS
*/
#include <Keypad.h>
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW)
#define entrada(pin) pinMode(pin, OUTPUT)
#define salida(pin) pinMode(pin, INPUT)
#define filas_teclado 4
#define columnas_teclado 4
#define f1_teclado 2
#define f2_teclado 3
#define f3_teclado 4
#define f4_teclado 5
#define c1_teclado 6
#define c2_teclado 7
#define c3_teclado 8
#define c4_teclado 9

char keys[filas_teclado][columnas_teclado] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};

Keypad teclado_miguel = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

void config_display(bool estado);

void setup()
{
  pinMode(10, OUTPUT);// a 
  pinMode(11, OUTPUT);// b
  pinMode(12, OUTPUT);// c
  pinMode(A0, OUTPUT);// d
  pinMode(A1, OUTPUT);// e
  pinMode(A2, OUTPUT);// f
  pinMode(A3, OUTPUT);// g
  Serial.begin(9600);
  Serial.println("Prueba del teclado matricial");
}
void loop()
{
  char tecla = teclado_miguel.getKey();
  if (tecla == LOW)
  {
        alto(10);
        alto(11);
        alto(12);
        alto(A0);
        alto(A1);
        alto(A2);
        bajo(A3);
        Serial.println(tecla);
        delay(100);
        
  }

    switch (tecla)
    {
      case('0'):
     {
        alto(10);
        alto(11);
        alto(12);
        alto(A0);
        alto(A1);
        alto(A2);
        bajo(A3);
        Serial.println(tecla);
        delay(1000);
        break; 
     }
     case ('1'):
     {
    bajo(10);
    alto(11);
    alto(12);
    bajo(A0);
    bajo(A1);
    bajo(A2);
    bajo(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

    case ('2'):
    {
    alto(10);
    alto(11);
    bajo(12);
    alto(A0);
    alto(A1);
    bajo(A2);
    alto(A3);
    Serial.println(tecla);
    delay(1000);
    break;
    }

    case ('3'):
     {
    alto(10);
    alto(11);
    alto(12);
    alto(A0);
    bajo(A1);
    bajo(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('4'):
     {
    bajo(10);
    alto(11);
    alto(12);
    bajo(A0);
    bajo(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('5'):
     {
    alto(10);
    bajo(11);
    alto(12);
    alto(A0);
    bajo(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('6'):
     {
    alto(10);
    bajo(11);
    alto(12);
    alto(A0);
    alto(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('7'):
     {
      alto(10);
      alto(11);
      alto(12);
      bajo(A0);
      bajo(A1);
      bajo(A2);
      bajo(A3);    
      Serial.println(tecla);
      delay(1000);
      break;
     }

     case ('8'):
     {
      alto(10);
      alto(11);
      alto(12);
      alto(A0);
      alto(A1);
      alto(A2);
      alto(A3);    
      Serial.println(tecla);
      delay(1000);
      break;
     }

     case ('9'):
     {
      alto(10);
      alto(11);
      alto(12);
      alto(A0);
      bajo(A1);
      alto(A2);
      alto(A3);    
      Serial.println(tecla);
      delay(1000);
      break;
     }


     case ('A'):
     {
      alto(10);
      alto(11);
      alto(12);
      bajo(A0);
      alto(A1);
      alto(A2);
      alto(A3);    
      Serial.println(tecla);
      delay(1000);
      break;
     }

     case ('B'):
     {
    bajo(10);
    bajo(11);
    alto(12);
    alto(A0);
    alto(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }


     case ('C'):
     {
    bajo(10);
    bajo(11);
    bajo(12);
    alto(A0);
    alto(A1);
    bajo(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }


     case ('D'):
     {
    bajo(10);
    alto(11);
    alto(12);
    alto(A0);
    alto(A1);
    bajo(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('*'):
     {
    alto(10);
    bajo(11);
    bajo(12);
    bajo(A0);
    alto(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }

     case ('#'):
     {
    alto(10);
    bajo(11);
    bajo(12);
    alto(A0);
    alto(A1);
    alto(A2);
    alto(A3);    
    Serial.println(tecla);
    delay(1000);
    break;
     }
    }
  
}
