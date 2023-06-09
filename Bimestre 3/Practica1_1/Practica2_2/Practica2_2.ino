/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 2_2 | CONTROL DE UNA SECUENCIA DE COLORES RGB 
*/
#define R 3
#define G 5
#define B 6
#define potenciometro A0

unsigned char rango_R = 0;
unsigned char rango_G = 0; 
unsigned char rango_B = 0;

unsigned char rango_potenciometro = 0;
unsigned char velocidad_led= 0 ; 
void setup() {
    Serial.begin(9600);
      pinMode(potenciometro, INPUT);
      pinMode(R, OUTPUT);
      pinMode(G, OUTPUT);
      pinMode(B, OUTPUT);
}
void loop() {
  rango_potenciometro = analogRead(A0);
  int tiempo =  map(rango_potenciometro, 0, 1023, 0, 255);
  analogWrite(R, 174);
  delay(tiempo);
  analogWrite(G, 92);
  delay(tiempo);
  analogWrite(B, 230);
  delay(tiempo);

  analogWrite(R, 255);
  delay(tiempo);
  analogWrite(G, 255);
  delay(tiempo);
  analogWrite(B, 255);
  delay(tiempo);

  analogWrite(R, 0);
  delay(tiempo);
  analogWrite(G, 255);
  delay(tiempo);
  analogWrite(B, 255);
  delay(tiempo);

  analogWrite(R, 189);
  delay(tiempo);
  analogWrite(G, 174);
  delay(tiempo);
  analogWrite(B, 20);
  delay(tiempo);

  analogWrite(R, 225);
  delay(tiempo);
  analogWrite(G, 87);
  delay(tiempo);
  analogWrite(B, 35);
  delay(tiempo);
   }
