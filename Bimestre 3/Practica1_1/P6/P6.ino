/*
Fundación Kinal
Centro educativo técnico laboral Kinal
Perito en electrónica
Quinto perito
Sección: A
Curso: Taller de electrónica digital y reparación de computadoras I
Alumno: Miguel Angel Alvarado González
Alumno: Franco Longo
Profe: Luis Alejandro Lopez Navas
Carné: 2022486
Carné: 2022357
Proyecto: Práctica 6 | Nivel 
*/

#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>
ADXL345 acelerometro = ADXL345();
LedControl matrix = LedControl(12, 11, 10);

int x;
int y;  
int z;

byte C[8] = {
  B11111111,  
  B11111111,
  B11111111,
  B11100111,
  B11100111,
  B11111111,
  B11111111,
  B11111111
};
byte R1[8] = {
  B11111111,
  B11111111,
  B11111111,
  B11110011,
  B11110011,
  B11111111,
  B11111111,
  B11111111
};

byte R2[8] = {
  B11111111,
  B11111111,
  B11111111,
  B11111001,
  B11111001,
  B11111111,
  B11111111,
  B11111111
};
byte R3[8] = {
  B11111111,
  B11111111,
  B11111111,
  B11111100,
  B11111100,
  B11111111,
  B11111111,
  B11111111
};
byte L1[8] = {
  B11111111,
  B11111111,
  B11111111,
  B11001111,
  B11001111,
  B11111111,
  B11111111,
  B11111111
};

byte L2[8] = {
  B11111111,
  B11111111,
  B11111111,
  B10011111,
  B10011111,
  B11111111,
  B11111111,
  B11111111
};
byte L3[8] = {
  B11111111,
  B11111111,
  B11111111,
  B00111111,
  B00111111,
  B11111111,
  B11111111,
  B11111111
};
void setup ()
{
  Serial.begin(9600);
  acelerometro.powerOn();
  matrix.shutdown(0, false);
  matrix.setIntensity(0, 10);
  matrix.clearDisplay(0);
  acelerometro.setRangeSetting(16);
}

void loop ()
{
  acelero();
  derecha();
  izquierda();
}


void acelero()
{
  acelerometro.readAccel(&x, &y, &z);
}

void derecha()
{
  if (x < 4 && x >= 0)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, C[i]);
    }
  } else if (x > 4 && x < 8)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, R1[i]);
    }
  } else if (x > 8 && x < 12)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, R2[i]);
    }
  } else if (x > 12) {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, R3[i]);
    }
  }
}

void izquierda()
{
  if (x < 0 && x > -4)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, C[i]);
    }
  }

  if (x < -4 && x > -8)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, L1[i]);
    }
  }

  if (x < -8 && x > -12)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, L2[i]);
    }
  }
  if (x < -12)
  {
    for (int i = 0; i < 9; i++)
    {
      matrix.setRow(0, i, L3[i]);
    }
  }
}
