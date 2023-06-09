/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/

#define LED 3 
#define POT A0
 
void setup() {
 pinMode(LED,OUTPUT);
 pinMode(POT,INPUT);
}
 
void loop() {
  int intensidad; 
 intensidad = map(analogRead(POT), 0, 1023, 0, 255);
  analogWrite(LED,intensidad); 
}
