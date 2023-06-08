/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/
#define r 3
#define g 5
#define b 6
#define pot A0

int color(int rr, int gg, int bb);
void setup() {
pinMode(r, OUTPUT);
pinMode(g, OUTPUT);
pinMode(b, OUTPUT);
pinMode(pot, INPUT);
}

void loop() {
int tiempo;
tiempo = map(analogRead(pot),0,1023,100,1000);  
color(174,92,230);
delay(tiempo);
color(255,255,255);
delay(tiempo);
color(0,255,255);
delay(tiempo);
color(189,174,20);
delay(tiempo);
color(255,87,35);
delay(tiempo);
}

int color(int rr, int gg, int bb){
 analogWrite(r, rr);
 analogWrite(g, gg);
 analogWrite(b, bb);
  }
