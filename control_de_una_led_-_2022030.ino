/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Cristian Estuardo Orellana Dieguez
Carné: 2022030 
*/
#define in(pin) pinMode(pin, INPUT)
#define out(pin) pinMode(pin, OUTPUT)
#define l(pin) digitalWrite(pin, 0)
#define h(pin) digitalWrite(pin, 1) 
#define b1 5
#define b2 6
#define r 2
#define v 3
#define a 4

    
void setup() {
out(r); out(v); out(a);
in(b1); in(b2); 
}

void loop() {

  int bb1; bb1 = digitalRead(b1);
  int bb2; bb2 = digitalRead(b2); 
 
 if(bb1 == 1 && bb2 == 0){
  l(a);   
  h(r);  h(v);
 }
 if(bb2 == 1 && bb1 == 0){
  l(r); 
  h(v);  h(a);
 }else if(bb1 == 1 && bb2 == 1){
  l(v); 
  h(r);  h(a);
 }

else if(bb1 == 0 && bb2 == 0){  
 l(r); l(v); l(a);  
  h(r);  delay(500); l(r);
  h(v);  delay(500); l(v);
  h(a);  delay(500); l(a); }
  
}
