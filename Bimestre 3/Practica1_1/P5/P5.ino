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
Proyecto: Práctica 5 | Sensor de humo con aviso
*/

#include <Ticker.h>
#include <LedControl.h>

void funcionamiento_humo();

Ticker ihumo(funcionamiento_humo, 2000);
LedControl lc=LedControl(7,5,6,1);

int adc, conver;
unsigned long delaytime=250;
unsigned long delaytime_fuego=450;

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  ihumo.start();
}

void loop() {
  ihumo.update();
  
  
  
}

void funcionamiento_humo()
{
  pinMode(A0, INPUT);
  adc = analogRead(A0); // Cantidad de voltaje en el pin 
  conver = map(adc, 0, 1024, 0, 100);
  if(conver > 68) // cambiar valor actual a valor real que es >73 o por ahí
  {
    animacion_fuego();
  }
  else
  {
    animacion_nieve();
  }
  Serial.print("Cantidad de humo: ");
  Serial.print(conver);
  Serial.println(" sobre 100");
}

void animacion_fuego(){
  byte llama[8]={B00000000,B01100000,B11110000,B11111100,B11111000,B11110010,B01100000,B00000000};
  byte llama_2[8]={B00000000,B01100000,B11110000,B11111100,B11111001,B11110000,B01100000,B00000000};
  byte llama_3[8]={B00000000,B01100000,B11111000,B11111101,B11110000,B11110000,B01100000,B00000000};
  byte llama_4[8]={B00000000,B01100000,B11111101,B11111000,B11110000,B11110000,B01100000,B00000000};
  byte llama_5[8]={B00000000,B01100010,B11111100,B11110000,B11110000,B11110000,B01100000,B00000000};
  byte llama_6[8]={B00000010,B01100100,B11111000,B11110000,B11110000,B11110000,B01100000,B00000000};
  //Regreso
  byte llama_7[8]={B00000000,B01100010,B11111100,B11110000,B11110000,B11110000,B01100000,B00000000}; // 5
  byte llama_8[8]={B00000000,B01100000,B11111101,B11111000,B11110000,B11110000,B01100000,B00000000}; // 4
  byte llama_9[8]={B00000000,B01100000,B11111000,B11111101,B11110000,B11110000,B01100000,B00000000}; // 3
  byte llama_10[8]={B00000000,B01100000,B11110000,B11111100,B11111001,B11110000,B01100000,B00000000}; // 2
  byte llama_11[8]={B00000000,B01100000,B11110000,B11111100,B11111000,B11110010,B01100000,B00000000}; // 1

  lc.setRow(0,0,llama[0]);
  lc.setRow(0,1,llama[1]);
  lc.setRow(0,2,llama[2]);
  lc.setRow(0,3,llama[3]);
  lc.setRow(0,4,llama[4]);
  lc.setRow(0,5,llama[5]);
  lc.setRow(0,6,llama[6]);
  lc.setRow(0,7,llama[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_2[0]);
  lc.setRow(0,1,llama_2[1]);
  lc.setRow(0,2,llama_2[2]);
  lc.setRow(0,3,llama_2[3]);
  lc.setRow(0,4,llama_2[4]);
  lc.setRow(0,5,llama_2[5]);
  lc.setRow(0,6,llama_2[6]);
  lc.setRow(0,7,llama_2[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_3[0]);
  lc.setRow(0,1,llama_3[1]);
  lc.setRow(0,2,llama_3[2]);
  lc.setRow(0,3,llama_3[3]);
  lc.setRow(0,4,llama_3[4]);
  lc.setRow(0,5,llama_3[5]);
  lc.setRow(0,6,llama_3[6]);
  lc.setRow(0,7,llama_3[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_4[0]);
  lc.setRow(0,1,llama_4[1]);
  lc.setRow(0,2,llama_4[2]);
  lc.setRow(0,3,llama_4[3]);
  lc.setRow(0,4,llama_4[4]);
  lc.setRow(0,5,llama_4[5]);
  lc.setRow(0,6,llama_4[6]);
  lc.setRow(0,7,llama_4[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_5[0]);
  lc.setRow(0,1,llama_5[1]);
  lc.setRow(0,2,llama_5[2]);
  lc.setRow(0,3,llama_5[3]);
  lc.setRow(0,4,llama_5[4]);
  lc.setRow(0,5,llama_5[5]);
  lc.setRow(0,6,llama_5[6]);
  lc.setRow(0,7,llama_5[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_6[0]);
  lc.setRow(0,1,llama_6[1]);
  lc.setRow(0,2,llama_6[2]);
  lc.setRow(0,3,llama_6[3]);
  lc.setRow(0,4,llama_6[4]);
  lc.setRow(0,5,llama_6[5]);
  lc.setRow(0,6,llama_6[6]);
  lc.setRow(0,7,llama_6[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_7[0]);
  lc.setRow(0,1,llama_7[1]);
  lc.setRow(0,2,llama_7[2]);
  lc.setRow(0,3,llama_7[3]);
  lc.setRow(0,4,llama_7[4]);
  lc.setRow(0,5,llama_7[5]);
  lc.setRow(0,6,llama_7[6]);
  lc.setRow(0,7,llama_7[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_8[0]);
  lc.setRow(0,1,llama_8[1]);
  lc.setRow(0,2,llama_8[2]);
  lc.setRow(0,3,llama_8[3]);
  lc.setRow(0,4,llama_8[4]);
  lc.setRow(0,5,llama_8[5]);
  lc.setRow(0,6,llama_8[6]);
  lc.setRow(0,7,llama_8[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_9[0]);
  lc.setRow(0,1,llama_9[1]);
  lc.setRow(0,2,llama_9[2]);
  lc.setRow(0,3,llama_9[3]);
  lc.setRow(0,4,llama_9[4]);
  lc.setRow(0,5,llama_9[5]);
  lc.setRow(0,6,llama_9[6]);
  lc.setRow(0,7,llama_9[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_10[0]);
  lc.setRow(0,1,llama_10[1]);
  lc.setRow(0,2,llama_10[2]);
  lc.setRow(0,3,llama_10[3]);
  lc.setRow(0,4,llama_10[4]);
  lc.setRow(0,5,llama_10[5]);
  lc.setRow(0,6,llama_10[6]);
  lc.setRow(0,7,llama_10[7]);
  delay(delaytime_fuego);
  lc.setRow(0,0,llama_11[0]);
  lc.setRow(0,1,llama_11[1]);
  lc.setRow(0,2,llama_11[2]);
  lc.setRow(0,3,llama_11[3]);
  lc.setRow(0,4,llama_11[4]);
  lc.setRow(0,5,llama_11[5]);
  lc.setRow(0,6,llama_11[6]);
  lc.setRow(0,7,llama_11[7]);
  delay(delaytime_fuego);
}

//ANIMACIÓN NIEVE

void animacion_nieve(){
  byte nieve[8]={B11000011,B11000011,B00100100,B00011111,B11111000,B00100100,B11000011,B11000011};
  byte nieve_2[8]={B11000011,B11000011,B00100100,B01011101,B10111010,B00100100,B11000011,B11000011};
  byte nieve_3[8]={B11000011,B11000011,B00100100,B11011100,B00111011,B00100100,B11000011,B11000011};
  byte nieve_4[8]={B11000011,B11000011,B10100100,B01011100,B00111010,B00100101,B11000011,B11000011};
  //Regreso
  byte nieve_5[8]={B11000011,B11000011,B00100100,B11011100,B00111011,B00100100,B11000011,B11000011}; // 3
  byte nieve_6[8]={B11000011,B11000011,B00100100,B01011101,B10111010,B00100100,B11000011,B11000011}; // 2
  byte nieve_7[8]={B11000011,B11000011,B00100100,B00011111,B11111000,B00100100,B11000011,B11000011}; // 1
  //Regreso
  byte nieve_8[8]={B11000011,B11000011,B00100100,B01011101,B10111010,B00100100,B11000011,B11000011}; // 2
  byte nieve_9[8]={B11000011,B11000011,B00100100,B11011100,B00111011,B00100100,B11000011,B11000011}; // 3
  byte nieve_10[8]={B11000011,B11000011,B10100100,B01011100,B00111010,B00100101,B11000011,B11000011}; // 4
  byte nieve_11[8]={B11000011,B11000011,B00100100,B11011100,B00111011,B00100100,B11000011,B11000011}; // 1
 
  lc.setRow(0,0,nieve[0]);
  lc.setRow(0,1,nieve[1]);
  lc.setRow(0,2,nieve[2]);
  lc.setRow(0,3,nieve[3]);
  lc.setRow(0,4,nieve[4]);
  lc.setRow(0,5,nieve[5]);
  lc.setRow(0,6,nieve[6]);
  lc.setRow(0,7,nieve[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_2[0]);
  lc.setRow(0,1,nieve_2[1]);
  lc.setRow(0,2,nieve_2[2]);
  lc.setRow(0,3,nieve_2[3]);
  lc.setRow(0,4,nieve_2[4]);
  lc.setRow(0,5,nieve_2[5]);
  lc.setRow(0,6,nieve_2[6]);
  lc.setRow(0,7,nieve_2[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_3[0]);
  lc.setRow(0,1,nieve_3[1]);
  lc.setRow(0,2,nieve_3[2]);
  lc.setRow(0,3,nieve_3[3]);
  lc.setRow(0,4,nieve_3[4]);
  lc.setRow(0,5,nieve_3[5]);
  lc.setRow(0,6,nieve_3[6]);
  lc.setRow(0,7,nieve_3[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_4[0]);
  lc.setRow(0,1,nieve_4[1]);
  lc.setRow(0,2,nieve_4[2]);
  lc.setRow(0,3,nieve_4[3]);
  lc.setRow(0,4,nieve_4[4]);
  lc.setRow(0,5,nieve_4[5]);
  lc.setRow(0,6,nieve_4[6]);
  lc.setRow(0,7,nieve_4[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_5[0]);
  lc.setRow(0,1,nieve_5[1]);
  lc.setRow(0,2,nieve_5[2]);
  lc.setRow(0,3,nieve_5[3]);
  lc.setRow(0,4,nieve_5[4]);
  lc.setRow(0,5,nieve_5[5]);
  lc.setRow(0,6,nieve_5[6]);
  lc.setRow(0,7,nieve_5[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_6[0]);
  lc.setRow(0,1,nieve_6[1]);
  lc.setRow(0,2,nieve_6[2]);
  lc.setRow(0,3,nieve_6[3]);
  lc.setRow(0,4,nieve_6[4]);
  lc.setRow(0,5,nieve_6[5]);
  lc.setRow(0,6,nieve_6[6]);
  lc.setRow(0,7,nieve_6[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_7[0]);
  lc.setRow(0,1,nieve_7[1]);
  lc.setRow(0,2,nieve_7[2]);
  lc.setRow(0,3,nieve_7[3]);
  lc.setRow(0,4,nieve_7[4]);
  lc.setRow(0,5,nieve_7[5]);
  lc.setRow(0,6,nieve_7[6]);
  lc.setRow(0,7,nieve_7[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_8[0]);
  lc.setRow(0,1,nieve_8[1]);
  lc.setRow(0,2,nieve_8[2]);
  lc.setRow(0,3,nieve_8[3]);
  lc.setRow(0,4,nieve_8[4]);
  lc.setRow(0,5,nieve_8[5]);
  lc.setRow(0,6,nieve_8[6]);
  lc.setRow(0,7,nieve_8[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_9[0]);
  lc.setRow(0,1,nieve_9[1]);
  lc.setRow(0,2,nieve_9[2]);
  lc.setRow(0,3,nieve_9[3]);
  lc.setRow(0,4,nieve_9[4]);
  lc.setRow(0,5,nieve_9[5]);
  lc.setRow(0,6,nieve_9[6]);
  lc.setRow(0,7,nieve_9[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_10[0]);
  lc.setRow(0,1,nieve_10[1]);
  lc.setRow(0,2,nieve_10[2]);
  lc.setRow(0,3,nieve_10[3]);
  lc.setRow(0,4,nieve_10[4]);
  lc.setRow(0,5,nieve_10[5]);
  lc.setRow(0,6,nieve_10[6]);
  lc.setRow(0,7,nieve_10[7]);
  delay(delaytime);
  lc.setRow(0,0,nieve_11[0]);
  lc.setRow(0,1,nieve_11[1]);
  lc.setRow(0,2,nieve_11[2]);
  lc.setRow(0,3,nieve_11[3]);
  lc.setRow(0,4,nieve_11[4]);
  lc.setRow(0,5,nieve_11[5]);
  lc.setRow(0,6,nieve_11[6]);
  lc.setRow(0,7,nieve_11[7]);
  delay(delaytime);
}
