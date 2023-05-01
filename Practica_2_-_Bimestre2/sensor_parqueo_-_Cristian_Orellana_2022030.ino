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
#define echo 2
#define trig 3

//Constructor
LiquidCrystal_I2C LG(0x27, 16, 2);

int ultrasonico();
void pines();
void lcd();

int lectura; //variable para guardar el valor de distancia del ultrasonico

byte cubo[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup()
{
  LG.init(); 
  LG.backlight(); 
  LG.createChar(1, cubo);
  pines();
}


void loop()
{
  lcd(); 
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

void pines(){
  out(trig);
  in(echo);
  }

void lcd(){
  lectura = ultrasonico();
  if(lectura == 50){
    LG.setCursor(0,0);
    LG.write(1); 
    LG.write(1); 
    LG.write(1);  //3 Caracteres a la izquierda
    LG.print("    ");    
    LG.print("50");
    LG.print("    ");    
    LG.write(1);  
    LG.write(1); 
    LG.write(1);  //3 Caracteres a la Derecha     
    LG.setCursor(0,1);
    LG.print("     Libre      ");
    }
  else if(lectura == 30){
    LG.setCursor(0,0);
    LG.write(1); 
    LG.write(1); 
    LG.write(1);  
    LG.write(1); 
    LG.write(1);  //5 Caracteres a la izquierda
    LG.print("  ");
    LG.print("30");
    LG.print("  ");
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1);  
    LG.write(1); //5 Caracteres a la Derecha   
    LG.setCursor(0,1);
    LG.print("     Cuidado    ");
    }  
  else if(lectura == 10){
    LG.setCursor(0,0);
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); //7 Caracteres a la izquierda
    LG.print("10");
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1); 
    LG.write(1);  //7 Caracteres a la Derecha
    LG.setCursor(0,1);
    LG.print("      Alto      ");
    }
  else if(lectura > 50){
    LG.setCursor(0,0);
    LG.print("                ");   
    LG.setCursor(0,1);
    LG.print("                ");   
    }
  }
