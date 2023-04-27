/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Contador 0 a 8 con display
*/
#define salida(pin) pinMode(pin, HIGH)
#define entrada(pin) pinMode(pin, INPUT)
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW)
#define A 5
#define B 6 
#define C 7
#define D 8
#define E 9 
#define F 10
#define G 11
#define trigg 4
#define echo 3
#define led 2
#define led_rojo 12
int paso = 0;
int duracion;
int distancia;  

void setup() 
{
  salida(trigg);
  entrada(echo);
  salida(led); 
  salida(led_rojo); 
  salida(A);
  salida(B);
  salida(C);
  salida(D);
  salida(E);
  salida(F);
  salida(G);
  Serial.begin(9600);
}

void loop() 
{
  bajo(trigg);
  delay(10);
  alto(trigg);
  delay(2);
  bajo(trigg);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion*0.034 / 2;
  Serial.print("distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(200);
  casos_display();
}

  void casos_display(void)
  { 
    if(distancia!=0 && distancia <11)
    {
      delay(200);
      paso++;
      Serial.println(paso);
      if(distancia !=0 && distancia <11 && paso == 1) // 1
      {
        bajo(A);
        alto(B);    
        alto(C); 
        bajo(D); 
        bajo(E); 
        bajo(F);
        bajo(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      } 

      if(distancia !=0 && distancia <11 && paso == 3) //2
      {
        alto(A);
        alto(B);    
        bajo(C); 
        alto(D); 
        alto(E); 
        bajo(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }
      if(distancia !=0 && distancia <11 && paso == 5) // 3
      {
        alto(A);
        alto(B);    
        alto(C); 
        alto(D); 
        bajo(E); 
        bajo(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }

      if(distancia !=0 && distancia <11 && paso == 7) // 4
      {
        bajo(A);
        alto(B);    
        alto(C); 
        bajo(D); 
        bajo(E); 
        alto(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }

      if(distancia !=0 && distancia <11 && paso == 9) // 5
      {
        alto(A);
        bajo(B);    
        alto(C); 
        alto(D); 
        bajo(E); 
        alto(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }

      if(distancia !=0 && distancia <11 && paso == 11) // 6
      {
        alto(A);
        bajo(B);    
        alto(C); 
        alto(D); 
        alto(E); 
        alto(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }

      if(distancia !=0 && distancia <11 && paso == 13) //7
      {
        alto(A);
        alto(B);    
        alto(C); 
        bajo(D); 
        bajo(E); 
        bajo(F);
        bajo(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }
      
      if(distancia !=0 && distancia <11 && paso == 15) // 8
      {
        alto(A);
        alto(B);    
        alto(C); 
        alto(D); 
        alto(E); 
        alto(F);
        alto(G);
        alto(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);      
      }

      if(distancia !=0 && distancia <11 && paso == 17) // 9 y lleno
      {
        alto(A);
        alto(B);    
        alto(C); 
        alto(D); 
        bajo(E); 
        alto(F);
        alto(G);
        bajo(led);
        bajo(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);
      }

      if(distancia !=0 && distancia <11 && paso == 19) // led rojo prohibicion
      {
        bajo(A);
        bajo(B);    
        bajo(C); 
        bajo(D); 
        bajo(E); 
        bajo(F);
        alto(G);
        alto(led);
        alto(led_rojo);
        paso++;
        Serial.println(paso);
        delay(1000);      
      }
    }
   
      if(distancia!=0 && distancia <11 && paso>19)
      {
        bajo(A);
        bajo(B);    
        bajo(C); 
        bajo(D); 
        bajo(E); 
        bajo(F);
        alto(G);
        paso++;
        delay(1000);
        paso=0; 
      }
  }
