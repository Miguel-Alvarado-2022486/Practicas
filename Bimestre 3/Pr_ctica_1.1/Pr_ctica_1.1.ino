/*Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Proyecto: Práctica 1.1 | Uso de interrupciones por hardware
*/
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT) 
#define alto(pin) digitalWrite(pin,HIGH) 
#define bajo(pin) digitalWrite(pin,LOW)
#define boton_rising 2
#define boton_falling 3

void boton_rising_ISR(void);
void boton_falling_ISR(void);
void setup() {
  entrada(boton_rising);
  entrada(boton_falling);
  attachInterrupt(digitalPinToInterrupt(boton_falling),boton_falling_ISR,FALLING);        
  attachInterrupt(digitalPinToInterrupt(boton_rising),boton_rising_ISR, RISING);
}

void loop() {

}
