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
unsigned long delay_universal=50; //delay nieve

void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  ihumo.start();
}

void loop() {
  ihumo.update();
  
  //Serial.println(adc);
}

void funcionamiento_humo()
{
  pinMode(A0, INPUT);
  adc = analogRead(A0); // Cantidad de voltaje en el pin 
  conver = map(adc, 0, 1024, 0, 100);
  if(conver > 50) // valor de voltaje procesado por map
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
  
  for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama[pos_fuego]);
    delay(delay_universal);
  }
for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama_2[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego ,llama_3[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego  =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama_4[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama_5[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =0; pos_fuego < 8; pos_fuego++){
    lc.setRow(0,pos_fuego,llama_6[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =7; pos_fuego >=0;pos_fuego--){
    lc.setRow(0,pos_fuego,llama_5[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =7; pos_fuego >=0;pos_fuego--){
    lc.setRow(0,pos_fuego,llama_4[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =7;pos_fuego >=0; pos_fuego--){
    lc.setRow(0,pos_fuego,llama_3[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =7; pos_fuego >=0; pos_fuego--){
    lc.setRow(0,pos_fuego,llama_2[pos_fuego]);
    delay(delay_universal);
  }
  for(int pos_fuego =7; pos_fuego >=0; pos_fuego--){
    lc.setRow(0,pos_fuego,llama[pos_fuego]);
    delay(delay_universal);
  }
  
}

void animacion_nieve(){
  byte nieve[8]={B11000011,B11000011,B00100100,B00011111,B11111000,B00100100,B11000011,B11000011};
  byte nieve_2[8]={B11000011,B11000011,B00100100,B01011101,B10111010,B00100100,B11000011,B11000011};
  byte nieve_3[8]={B11000011,B11000011,B00100100,B11011100,B00111011,B00100100,B11000011,B11000011};
  byte nieve_4[8]={B11000011,B11000011,B10100100,B01011100,B00111010,B00100101,B11000011,B11000011};
  lc.setRow(0,0,nieve[0]);
 
  for(int pos_nieve =1; pos_nieve < 8; pos_nieve++){
    lc.setRow(0,pos_nieve, nieve[pos_nieve]);
    delay(delay_universal);
  }
  for(int pos_nieve =1; pos_nieve < 8; pos_nieve++){
    lc.setRow(0,pos_nieve,nieve_2[pos_nieve]);
    delay(delay_universal);
  }
  for(int pos_nieve =1; pos_nieve < 8; pos_nieve++){
    lc.setRow(0,pos_nieve,nieve_3[pos_nieve]);
    delay(delay_universal);
  }
  for(int pos_nieve =1; pos_nieve < 8; pos_nieve++){
    lc.setRow(0,pos_nieve,nieve_4[pos_nieve]);
    delay(delay_universal);
  }
  for(int pos_nieve =7; pos_nieve >=0; pos_nieve--){
    lc.setRow(0,pos_nieve,nieve_3[pos_nieve]);
    delay(delay_universal);
  }
  for(int pos_nieve =7; pos_nieve >= 0; pos_nieve--){
    lc.setRow(0,pos_nieve,nieve_2[pos_nieve]);
    delay(delay_universal);
  }
}
