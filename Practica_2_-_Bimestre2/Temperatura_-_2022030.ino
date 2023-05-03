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
float medicion1();
float medicion2();
void lcd_funcion();
void led();
float celcius;
float fahrenheit;

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
byte caliente[] ={ 
B00000, 
B00010, 
B00101, 
B11010, 
B01110, 
B11111, 
B11111, 
B01110 };

byte frio[] = {
B00010, 
B00111, 
B00010, 
B00000, 
B01000, 
B11100, 
B01000, 
B00000 };

byte templado[] = { 
B01100, 
B11110, 
B11110, 
B00000, 
B00110, 
B01111, 
B01111, 
B00000 };
byte termometro[] = { 
B00100, 
B01010, 
B01010, 
B01010, 
B10001, 
B10001, 
B10001, 
B01110 };

void setup() {
delay(1000);
sensorCR7.begin();   //Se inicia el sensor
LG.init(); 
LG.backlight(); 
LG.createChar(1, cel);
LG.createChar(2, far);
LG.createChar(3, caliente);
LG.createChar(4, frio);
LG.createChar(5, templado);
LG.createChar(6, termometro);
pinMode(rojo, OUTPUT);
pinMode(amarillo, OUTPUT);
pinMode(azul, OUTPUT);
}
 
void loop() {
lcd_funcion();
led();
}

float medicion1(){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºC  
  return temp;
  }

float medicion2(){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp1= sensorCR7.getTempFByIndex(0); //Se obtiene la temperatura en ºF 
  return temp1;
  }
  
void lcd_funcion(){
celcius = medicion1();
fahrenheit = medicion2();
LG.setCursor(0,0);
LG.print(" ");
LG.write(6);
LG.print("Temperatura");
LG.write(6);
LG.setCursor(0,1);
LG.print(celcius);
LG.write(1);
LG.setCursor(8,1);
LG.print(fahrenheit);
LG.write(2);
}  
void led(){
  celcius= medicion1();
  if (celcius > 30){
    digitalWrite(rojo, HIGH);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, LOW);
LG.setCursor(15,1);
LG.write(3);
    }
   if (celcius > 15 && celcius <= 30){
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    digitalWrite(azul, LOW);
LG.setCursor(15,1);
LG.write(5);
    }
   if (celcius <= 15){
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(azul, HIGH);
LG.setCursor(15,1);
LG.write(4);
    }
  }
