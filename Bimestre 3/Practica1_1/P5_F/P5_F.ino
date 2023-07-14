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
  if(conver > 60) // cambiar valor actual a valor real que es >73 o por ahí
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
  byte llama_7[8]={B00000000,B01100010,B11111100,B11110000,B11110000,B11110000,B01100000,B00000000}; // 5
  byte llama_8[8]={B00000000,B01100000,B11111101,B11111000,B11110000,B11110000,B01100000,B00000000}; // 4
  byte llama_9[8]={B00000000,B01100000,B11111000,B11111101,B11110000,B11110000,B01100000,B00000000}; // 3
  byte llama_10[8]={B00000000,B01100000,B11110000,B11111100,B11111001,B11110000,B01100000,B00000000}; // 2
  byte llama_11[8]={B00000000,B01100000,B11110000,B11111100,B11111000,B11110010,B01100000,B00000000}; // 1

   for(int i =0; i < 8; i++){
    lc.setRow(0,i,llama[i]);
    delay(delaytime_fuego);
  }
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

  for(int b =0; b < 8; b++){
    lc.setRow(0,b,nieve[b]);
    delay(delaytime_fuego);
  }
  
}
