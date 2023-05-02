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
  
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensors(&ourWire); //Se declara una objeto para nuestro sensor
LiquidCrystal_I2C LG(0x27, 16, 2);
int medicion1();
int medicion2();
void lcd_funcion();
int celcius;
int fahrenheit;

void setup() {
delay(1000);
sensors.begin();   //Se inicia el sensor
LG.init(); 
LG.backlight(); 
}
 
void loop() {
lcd_funcion();
}

int medicion1(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC  
  return temp;
  }

int medicion2(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp1= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºF 
  return temp1;
  }
  
void lcd_funcion(){
celcius = medicion1();
fahrenheit = medicion2();
LG.setCursor(0,0);
LG.print("Temp= ");
LG.print(celcius);
LG.print(" C");
LG.setCursor(0,1);
LG.print("Temp= ");
LG.print(fahrenheit);
LG.print(" F");
}  
