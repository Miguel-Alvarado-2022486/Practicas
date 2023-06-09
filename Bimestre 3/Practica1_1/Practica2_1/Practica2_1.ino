/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 2_1 | Control de brillo de un led 
*/
#define potenciometro A0   
#define led 3  

//Variables
unsigned int raw_potenciometro = 0;
unsigned char speedServo =0;


void setup() {
  
 Serial.begin(9600); 
 pinMode(potenciometro, INPUT); 
 pinMode(led, OUTPUT);  
}

void loop() {
  raw_potenciometro = analogRead(potenciometro); 
  speedServo = map(raw_potenciometro, 0, 1023, 0, 255);
  analogWrite(led, speedServo);
  delay(100);
}
