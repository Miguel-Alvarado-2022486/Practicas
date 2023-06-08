#include <DallasTemperature.h>
#include <OneWire.h> 
#include <Ticker.h>
#define boton 2


OneWire ourWire(10);
DallasTemperature sensors(&ourWire);
void interrupcion_sensor(void);
void interrupcion_boton(void);
volatile static bool estado_boton;
Ticker constructor_boton(interrupcion_boton, 6000);
Ticker constructor_sensor(interrupcion_sensor, 3500);
 
void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(boton, INPUT);
  constructor_boton.start();
  constructor_sensor.start();
}

void loop() {
  constructor_boton.update();
  constructor_sensor.update();
}

void interrupcion_boton()
{
  estado_boton = digitalRead(boton);
  if(estado_boton == 1){
    Serial.println("Sensor digital encendido");
  }
  else if(estado_boton ==0){
    Serial.println("Sensor digital apagado");
  }
}

void interrupcion_sensor(void)
{
  float C = sensors.getTempCByIndex(0);
  sensors.requestTemperatures();
  Serial.println(C);
}
