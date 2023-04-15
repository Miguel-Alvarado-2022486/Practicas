/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Practica dos | Expendedora
*/

#define readPin(pin) digitalRead(pin)
#define inPin(pin) pinMode(pin, INPUT)
#define adelante 2
#define atras 3
int paso = 0;
struct productos
{
  String posicion;
  String nombre;
  int cantidad;
  String vencimiento;
}chucheria_uno = {"1.","Oreo", 45, "25/5/23"},chucheria_dos= {"2.","Chicky", 52, "5/6/23"}, chucheria_tres = {"3.","Lays", 25, "15/5/23"}, chucheria_cuatro = {"4.","Tronchis", 38, "3/6/23"};
void setup() {
  inPin(adelante);

}

void loop() {
  Serial.begin(9600);
  bool lector_adelante = readPin(adelante);
  bool lector_atras = readPin(atras);

  if ((lector_adelante == true) & (lector_atras == false))
  {
   delay(200);
   paso++ ;
    if(paso == 1)
    {
      Serial.println("                              BIENVENIDO            ");
      Serial.println("Posicion--Nombre---------------Cantidad---------------Vencimiento");
      Serial.print(chucheria_uno.posicion);
      Serial.print("        ");
      Serial.print(chucheria_uno.nombre);
      Serial.print("                 ");
      Serial.print(chucheria_uno.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_uno.vencimiento);
      paso++;
      delay(50);
    }

    if(paso == 3){
      Serial.print(chucheria_dos.posicion);
      Serial.print("        ");
      Serial.print(chucheria_dos.nombre);
      Serial.print("               ");
      Serial.print(chucheria_dos.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_dos.vencimiento);
      paso++;
      delay(50);
    }

    if(paso == 5){
      Serial.print(chucheria_tres.posicion);
      Serial.print("        ");
      Serial.print(chucheria_tres.nombre);
      Serial.print("                 ");
      Serial.print(chucheria_tres.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_tres.vencimiento);
      paso++;
      delay(50);
    }

    if(paso == 7){
      Serial.print(chucheria_cuatro.posicion);
      Serial.print("        ");
      Serial.print(chucheria_cuatro.nombre);
      Serial.print("             ");
      Serial.print(chucheria_cuatro.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_cuatro.vencimiento);
      paso++;
      delay(50);
    }
    
  }
  if((lector_atras == HIGH) & (lector_adelante == LOW))
  {
    delay(200);
    paso--;
      if(paso == 1){
      Serial.print(chucheria_cuatro.posicion);
      Serial.print("        ");
      Serial.print(chucheria_cuatro.nombre);
      Serial.print("             ");
      Serial.print(chucheria_cuatro.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_cuatro.vencimiento);
        delay(50);
        paso=8;
      }

      if(paso == 3){
      Serial.print(chucheria_uno.posicion);
      Serial.print("        ");
      Serial.print(chucheria_uno.nombre);
      Serial.print("                 ");
      Serial.print(chucheria_uno.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_uno.vencimiento);
        delay(50);
        paso--;
      }

      if(paso == 5){
        Serial.print(chucheria_dos.posicion);
      Serial.print("        ");
      Serial.print(chucheria_dos.nombre);
      Serial.print("               ");
      Serial.print(chucheria_dos.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_dos.vencimiento);
        delay(50);
        paso--;    
      }

      if(paso==7){
      Serial.print(chucheria_tres.posicion);
      Serial.print("        ");
      Serial.print(chucheria_tres.nombre);
      Serial.print("                 ");
      Serial.print(chucheria_tres.cantidad);
      Serial.print("                      ");
      Serial.println(chucheria_tres.vencimiento);
        
        delay(50);
        paso--;
      }

      if(paso<0){
        paso = 7;
      }
      
  }
}
