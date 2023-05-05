/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <Wire.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
//directivas de preprocesador
#define out(pin) pinMode(pin,OUTPUT)
#define in(pin) pinMode(pin,INPUT)
#define h(pin) digitalWrite(pin, HIGH)
#define l(pin) digitalWrite(pin, LOW)
#define luz1 A0
#define luz2 A1
#define door A2
#define rele1 3
#define rele2 4
#define servopin 5
#define buz 6
#define red 12
#define green 8
#define blue 9
#define neo 10
#define radar A3

//constructores
OneWire ourWire(2);
DallasTemperature sensorCR7(&ourWire);
LiquidCrystal_I2C LG(0x27, 16, 2);
Servo puerta;
Adafruit_NeoPixel rueda(7,neo, NEO_GRB + NEO_KHZ800);

//enum para los colores del neopixel
enum color{
  rojo, 
  verde,
  azul
  };

//funciones
void pines();
float medicion1();
void lcd_funcion();
void temperatura();
void accion();
void lamparas();
void movimiento_naranja();
void setcolor(int color);
//variables 
float celcius;
int estado=0; 
int estado2=0;
int estadoz=0;
//caracteres

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

byte puerta_cerrada[] = {
  B00000,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00000
};
byte puerta_abierta[] = {
  B00000,
  B01111,
  B01001,
  B01001,
  B01001,
  B01001,
  B01001,
  B00000
};
byte no_persona[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};

byte persona[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};
byte apagado[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B01110,
  B01010,
  B00100
};
byte encendido[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01010,
  B00100
};
void setup() {
  delay(1000);
  sensorCR7.begin();   //Se inicia el sensor   
  Serial.begin(9600); 
  LG.init(); 
  puerta.attach(servopin);
  LG.backlight(); 
  LG.createChar(1, frio);
  LG.createChar(2, templado);
  LG.createChar(3, puerta_abierta);
  LG.createChar(4, puerta_cerrada);
  LG.createChar(5, no_persona);
  LG.createChar(6, persona);   
  LG.createChar(7, apagado);   
  LG.createChar(8, encendido); 
  pines();
  lcd_funcion();
}

void loop() {
 temperatura();
 accion();
 Serial.println(medicion1());
 lamparas();
 movimiento_naranja();

}
void pines(){
  in(luz1);
  in(luz2);
  in(door);
  in(radar);
  out(rele1);
  out(rele2);
  out(servopin);
  out(buz);
  out(red);
  out(green);
  out(blue);
  out(neo);
  }
  
float medicion1(){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºC  
  return temp;
  }
  
void lcd_funcion(){
  LG.setCursor(0,0);
  LG.print("temp:");
  
  LG.setCursor(7,0);
  LG.print("L1:");
  
  LG.setCursor(12,0);
  LG.print("L2:");

  LG.setCursor(0,1);
  LG.print("puerta:");

  LG.setCursor(9,1);
  LG.print("radar:");
}

void temperatura(){
//parte de temperatura en la lcd
  celcius = medicion1();
   if (celcius > 14 && celcius <= 21){
  l(green);
  h(blue);
  h(red);
  LG.setCursor(5,0);
  LG.write(1);
 } 
   if (celcius > 21 && celcius <= 25){
  h(green);
  l(blue);
  l(red);
  LG.setCursor(5,0);
  LG.write(2); 
 } 
   if (celcius > 25 && celcius <= 45){
  l(green);
  l(blue);
  h(red);
  LG.setCursor(5,0);
  LG.write(8);
 }   
}

void accion(){
  if(digitalRead(door) && estadoz == 0){
    puerta.write(90);
    LG.setCursor(7,1);
    LG.write(3);
  delay(500);
  estadoz=1;
  }
if(digitalRead(door) && estadoz == 1){
    puerta.write(0);
    LG.setCursor(7,1);
    LG.write(4);
  delay(500);
  estadoz=0;
  }else if(digitalRead(door)==0 && estadoz == 0){
  puerta.write(0);
  LG.setCursor(7,1);
  LG.write(4);
    }
   }
   
void lamparas(){ 
   
 if( digitalRead(luz1) && estado == 0){
  l(rele1);
  LG.setCursor(10,0);
  LG.write(8); 
  delay(500);
  estado=1;
  }
if(digitalRead(luz1) && estado == 1){
  h(rele1);
  LG.setCursor(10,0);
  LG.write(7); 
  delay(500);
  estado=0;
  }else if(digitalRead(luz1)==0&& estado == 0){
  h(rele1);
  LG.setCursor(10,0);
  LG.write(7);     
    }
 if(digitalRead(luz2) && estado2 == 0){
  l(rele2);
  LG.setCursor(15,0);
  LG.write(8); 
  delay(500);
  estado2=1;
  }
if(digitalRead(luz2) && estado2 == 1){
  h(rele2);
  LG.setCursor(15,0);
  LG.write(7); 
  delay(500);
  estado2=0;
  }else if(digitalRead(luz2) ==0 && estado2 == 0){
  h(rele2);
  LG.setCursor(15,0);
  LG.write(7);    
    }
  }
  
void setcolor(int color){
 switch (color){
  case rojo:{
     for(int i =0; i<8; i++)
        {
          rueda.setPixelColor(i,rueda.Color(255,0,0));
          rueda.show();  //muestro el color en el led
        } 
      break;
    }
  case verde:{
     for(int i =0; i<8; i++)
        {
          rueda.setPixelColor(i,rueda.Color(0,255,0));
          rueda.show();  //muestro el color en el led
        } 
      break;
    } 
  case azul:{
     for(int i =0; i<8; i++)
        {
          rueda.setPixelColor(i,rueda.Color(0,0,255));
          rueda.show();  //muestro el color en el led
        } 
      break;
    }
   } 
  }
   
void movimiento_naranja(){
int accion = digitalRead(radar);

  LG.setCursor(15,1);
  LG.write(5);
  setcolor(verde);   
   
 if(accion==HIGH){
  LG.setCursor(15,1);
  LG.write(6);
  setcolor(azul); 
  tone(buz,250*6,5000);
      delay(100);
      noTone(buz); 
   setcolor(rojo);  
         delay(100);
  } 
  }
