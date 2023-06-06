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

//Directivas de preprocesador 
#define salida(pin) pinMode(pin,OUTPUT)
#define entrada(pin) pinMode(pin,INPUT) 
#define alto(pin) digitalWrite(pin,HIGH) 
#define bajo(pin) digitalWrite(pin,LOW)
#define boton_rising 2
#define boton_falling 3

//Variables
unsigned int unidad = 1;
unsigned int decena =1 ;

//Funciones
void boton_rising_ISR(void);
void boton_falling_ISR(void);
void pines_display();

void setup() 
{
  entrada(boton_rising);
  pinMode(boton_falling, INPUT_PULLUP);
  //Interrupciones
  attachInterrupt(digitalPinToInterrupt(boton_falling),boton_falling_ISR,FALLING);        
  attachInterrupt(digitalPinToInterrupt(boton_rising),boton_rising_ISR, RISING);

  //Salidas de decenas
  salida(4);
  salida(5);
  salida(6);
  salida(7);
  //Salidas de unidades
  salida(8);
  salida(9);
  salida(10);
  salida(11);
}

void loop() 
{
  pines_display();
}

//Función en donde se encuentra el funcionamiento del botón que disminuye la cuenta
void boton_falling_ISR(void)
{
  unidad--;  
  if(unidad ==0 && decena == 1) //Límite para volver de el número cero al número cincuenta e ir disminuyendo
  {
    unidad=10;
    decena = 6;
    decena--;
  }
  
  if(unidad ==0 )  
  {
    unidad=10;
    decena--; 
  } 
}

//Función en donde se encuentra el funcionamiento del botón que aumenta la cuenta
void boton_rising_ISR(void)
{
   unidad++;  
}

//Función en donde se encuentra el funcionamiento del contador
void pines_display()
{  
  if(unidad == 1 )  //Número cero
  {
    bajo(4);
    bajo(5);
    bajo(6);
    bajo(7);
  }

  else if (unidad == 2) //Número uno
  {
    alto(4);
    bajo(5);
    bajo(6);
    bajo(7);  
  }
  
  else if (unidad == 3) //Número dos
  {
    bajo(4);
    alto(5);
    bajo(6);
    bajo(7);  
  }

  else if (unidad == 4) //Número tres
  {
    alto(4);
    alto(5);
    bajo(6);
    bajo(7);  
  }

  else if (unidad == 5) //Número cuatro
  {
    bajo(4);
    bajo(5);
    alto(6);
    bajo(7);  
  }

  else if (unidad == 6) //Número cinco
  {
    alto(4);
    bajo(5);
    alto(6);
    bajo(7);  
  }

  else if (unidad == 7) //Número seis
  {
    bajo(4);
    alto(5);
    alto(6);
    bajo(7);  
  }

  else if (unidad == 8) //Número siete
  {
    alto(4);
    alto(5);
    alto(6);
    bajo(7);  
  }

  else if (unidad == 9) //Número ocho
  {
    bajo(4);
    bajo(5);
    bajo(6);
    alto(7);  
  }

  else if (unidad == 10) //Número nueve
  {
    alto(4);
    bajo(5);
    bajo(6);
    alto(7);  
    
  }
  
  if(unidad ==11) //Reinicio a cero
  {
    unidad = 1;
    decena++;
  }

//Código de decenas
  if(decena == 6 && unidad ==2) //Límite para volver de el número cincuenta al número cero e ir aumentando
  {
    unidad = 1;
    decena = 1;
  }   
 
  if (decena == 1) //Número cero
  {
    bajo(8);
    bajo(9);
    bajo(10);
    bajo(11);
  }
  
  else if (decena == 2) //Número uno
  {
    alto(8);
    bajo(9);
    bajo(10);
    bajo(11);
  }
  
  else if (decena == 3) //Número dos
  {
    bajo(8);
    alto(9);
    bajo(10);
    bajo(11);
  }
  
  else if (decena == 4) //Número tres
  {
    alto(8);
    alto(9);
    bajo(10);
    bajo(11);
  }
  
  else if (decena == 5) //Número cuatro
  {
    bajo(8);
    bajo(9);
    alto(10);
    bajo(11);
  }
  
  else if (decena == 6) //Número cinco
  {
    alto(8);
    bajo(9);
    alto(10);
    bajo(11);
  }
}
