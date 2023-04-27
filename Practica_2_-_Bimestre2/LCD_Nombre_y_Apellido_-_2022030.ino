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
#include <LiquidCrystal.h>
#define RS  2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

LiquidCrystal LCD_samsung(RS, E, D4, D5, D6, D7);

void setup() {
 LCD_samsung.begin(16,2); 
 LCD_samsung.print("Cristian");
 LCD_samsung.setCursor(0,1);
 LCD_samsung.print("2022030");

}

void loop() {


}
