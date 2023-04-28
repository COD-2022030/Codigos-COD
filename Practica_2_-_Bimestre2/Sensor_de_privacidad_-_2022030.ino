/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/

#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

#define out(pin) pinMode(pin,OUTPUT)
#define in(pin) pinMode(pin,INPUT)
#define h(pin) digitalWrite(pin, HIGH)
#define l(pin) digitalWrite(pin, LOW)
#define l1 2
#define l2 3
#define l3 4
#define l4 5
#define echo A0
#define trig A1
#define buz A2

LiquidCrystal_I2C LG(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void pines(); // declaracion de funciones
int ultrasonico();
void ejecucion();

int lectura;// donde se guardara la lectura de distancia
void setup()
{
  LG.init();                      // initialize the lcd 
  LG.backlight();
  pines();
}


void loop()
{
  ejecucion();
}

void pines(){
  out(l1);
  out(l2);
  out(l3);
  out(l4);
  out(trig);
  out(buz);
  in(echo);
  }
  
 int ultrasonico(){ //funcion para leer al ultrasonico
  int duracion, distancia;
  h(trig);
  delay(1);
  l(trig);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;
  return distancia;
  }

void ejecucion(){
  lectura = ultrasonico();
  if(lectura > 45){
      LG.setCursor(0,0);
      LG.print("Fuera de        ");
      LG.setCursor(0,1);
      LG.print("Alcance :)      ");
      h(l1);
      l(l2);
      l(l3);
      l(l4);
  }
  
  if(lectura > 29 && lectura <= 45){
      LG.setCursor(0,0);
      LG.print("Persona/Objeto  ");
      LG.setCursor(0,1);
      LG.print("Acercandose :o  ");
      h(l1);
      h(l2);
      l(l3);
      l(l4);
  }
  
  if(lectura > 14 && lectura < 29){
      LG.setCursor(0,0);
      LG.print("Cuidado -_-     ");
      LG.setCursor(0,1);
      LG.print("Espacio Privado ");
      h(l1);
      h(l2);
      h(l3);
      l(l4);
      tone(buz,250*6,5000);
      delay(100);
      noTone(buz);
  }

  if(lectura > 4 && lectura < 14){
      LG.setCursor(0,0);
      LG.print("Invadiendo >:(  ");
      LG.setCursor(0,1);
      LG.print("Espacio Privado ");
      h(l1);
      h(l2);
      h(l3);
      h(l4);
      tone(buz,380*6,10000);
      delay(100);
      noTone(buz);
  }
  }
