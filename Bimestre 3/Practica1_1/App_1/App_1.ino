#include <OneWire.h>
#include <SoftwareSerial.h>
#include <DallasTemperature.h>
#define RXD 11
#define TXD 10
#define alto(pin) digitalWrite(pin,HIGH)
#define bajo(pin) digitalWrite(pin,LOW)
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define foco 2

OneWire ourWire(8);
DallasTemperature sensors(&ourWire);
SoftwareSerial blu(RXD, TXD);
void setup() {
  Serial.begin(9600);
  blu.flush();
  blu.begin(9600);
  sensors.begin();
  salida(foco);
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.println(tempC);
  delay(500);

  if (blu.available() > 0)
  {
    
    char estado = blu.read();
    if (estado = '1') 
    {
     
    alto(foco); 
    Serial.write(estado);
    }
    if (estado = '2') 
    {
      bajo(foco);
      Serial.write(estado);
    }

}
}
