#include <LiquidCrystal_I2C.h>
#define voltaje A0
//constructor
LiquidCrystal_I2C samsung(0x27,16,2);
float ecuacion();

void setup() {
  samsung.init(); 
  samsung.backlight();
  pinMode(voltaje, INPUT);
}

void loop() {
 float mostrar = ecuacion();
 samsung.setCursor(1,0);
 samsung.print(" Su Resistencia ");
 samsung.setCursor(2,1); 
 samsung.print(mostrar);
 samsung.print(" Ohms"); 
}

float ecuacion(){
  float  vout, resultado = 0, arriba=0, abajo=0;
  float vr = analogRead(voltaje);
  vout = (vr*5)/1023;
  arriba = (-vout)*(10000);
  abajo= vout-5;
  resultado = arriba/abajo;
  return resultado; 
  }
