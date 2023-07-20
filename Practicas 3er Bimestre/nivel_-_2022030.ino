/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/

#include <SparkFun_ADXL345.h>
#include<Wire.h>
#include<LedControl.h>

#define dato 4
#define clk 2
#define cs 3

ADXL345 nivel = ADXL345();
LedControl matriz = LedControl(dato,clk,cs,1);

//izquierda
  byte centrado[8]= {
B11111111,
B11111111,
B00000000,
B00011000,
B00011000,
B00000000,
B11111111,
B11111111
  };

  byte izquierda1[8]= {
B11111111,
B11111111,
B00000000,
B00110000,
B00110000,
B00000000,
B11111111,
B11111111
  };

  byte izquierda2[8]= {
B11111111,
B11111111,
B00000000,
B01100000,
B01100000,
B00000000,
B11111111,
B11111111};

  byte vertical[8]= {
B11111111,
B11111111,
B00000000,
B11000000,
B11000000,
B00000000,
B11111111,
B11111111};

  //derecha
  byte derecha1[8]= {
B11111111,
B11111111,
B00000000,
B00001100,
B00001100,
B00000000,
B11111111,
B11111111};

  byte derecha2[8]= {
B11111111,
B11111111,
B00000000,
B00000110,
B00000110,
B00000000,
B11111111,
B11111111};


  byte vertical1[8]= {
B11111111,
B11111111,
B00000000,
B00000011,
B00000011,
B00000000,
B11111111,
B11111111};


void setup() {
  Serial.begin(9600);
  nivel.powerOn();
  nivel.setRangeSetting(8); 
  matriz.shutdown(0,false);
  matriz.setIntensity(0,5);
  matriz.clearDisplay(0);
}

void loop() {
  int x, y, z;
  nivel.readAccel(&x, &y, &z);
  Serial.print("x: ");
  Serial.println(x);

  if (x<=3 && x>=0){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,centrado[i]);
    }
  }
  if (x<=-1 && x>=-25){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,derecha1[i]);
    }
  }
  if (x<=-26 && x>=-50){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,derecha2[i]);
    }
  }
  if (x<=-51 && x>=-70){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,vertical1[i]);
    }
  }

  //derecha
  if (x>=4 && x<=25){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,izquierda1[i]);
    }
  }
  if (x>=26 && x<=50){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,izquierda2[i]);
    }
  }
  if (x>=51 && x<=70){
    for(int i=0; i<8; i++){
      matriz.setRow(0,i,vertical[i]);
    }
  }
}
