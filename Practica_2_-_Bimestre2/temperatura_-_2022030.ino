/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/

//Librerias
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h> 
#define rojo 3
#define amarillo 4
#define azul 5
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensorCR7(&ourWire); //Se declara una objeto para nuestro sensor
LiquidCrystal_I2C LG(0x27, 16, 2);
int medicion1();
int medicion2();
void lcd_funcion();
void led();
int celcius;
int fahrenheit;

byte cel[] = {
  B01000,
  B10100,
  B01000,
  B00011,
  B00100,
  B00100,
  B00100,
  B00011
};

byte far[] = {
  B01000,
  B10100,
  B01000,
  B00111,
  B00100,
  B00111,
  B00100,
  B00100
};
void setup() {
delay(1000);
sensorCR7.begin();   //Se inicia el sensor
LG.init(); 
LG.backlight(); 
LG.createChar(1, cel);
LG.createChar(1, far);
}
 
void loop() {
lcd_funcion();
led();
}

int medicion1(){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºC  
  return temp;
  }

int medicion2(){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp1= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºF 
  return temp1;
  }
  
void lcd_funcion(){
celcius = medicion1();
fahrenheit = medicion2();
LG.setCursor(0,0);
LG.print("Temp= ");
LG.print(celcius);
LG.write(1);
LG.setCursor(0,1);
LG.print("Temp= ");
LG.print(fahrenheit);
LG.write(2);
}  
void led(){
  celcius= medicion1();
  if (celcius > 30){
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
    }
   if (celcius > 15 && celcius <= 30){
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, LOW);
    }
   if (celcius <= 15){
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, HIGH);
    }
  }
