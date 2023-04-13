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
#define l(pin) digitalWrite(pin, LOW)
#define h(pin) digitalWrite(pin, HIGH) 
#define d1 2
#define d2 3
#define d3 4
#define d4 5
#define d5 6
#define d6 7
#define d7 8
#define d8 9
#define d9 10
#define d10 11
int a = 50;
void setup() {
 out(d1);
 out(d2);
 out(d3);
 out(d4);
 out(d5);
 out(d6);
 out(d7);
 out(d8);
 out(d9);
 out(d10);

}

void loop() {
for(int i = 2;i < 11;i++){
  h(i); 
  delay(a);
  l(i);
  }
for(int i = 11;i > 2;i--){
  h(i);
  delay(a);
  l(i);
  }
 h(d1);
 h(d2);
 h(d3);
 h(d4);
 h(d5);
 h(d6);
 h(d7);
 h(d8);
 h(d9);
 h(d10);
 delay(a);
 l(d1);
 l(d2);
 l(d3);
 l(d4);
 l(d5);
 l(d6);
 l(d7);
 l(d8);
 l(d9);
 l(d10);
 delay(a);
 h(d1);
 h(d2);
 h(d3);
 h(d4);
 h(d5);
 h(d6);
 h(d7);
 h(d8);
 h(d9);
 h(d10);
 delay(a);
 l(d1);
 l(d2);
 l(d3);
 l(d4);
 l(d5);
 l(d6);
 l(d7);
 l(d8);
 l(d9);
 l(d10);
 delay(a);
 h(d1);
 h(d2);
 h(d3);
 h(d4);
 h(d5);
 h(d6);
 h(d7);
 h(d8);
 h(d9);
 h(d10);
 delay(a);
 l(d1);
 l(d2);
 l(d3);
 l(d4);
 l(d5);
 l(d6);
 l(d7);
 l(d8);
 l(d9);
 l(d10);
 delay(a);
 h(d1);
 h(d2);
 h(d3);
 h(d4);
 h(d5);
 h(d6);
 h(d7);
 h(d8);
 h(d9);
 h(d10);
 delay(a);
 l(d1);
 l(d2);
 l(d3);
 l(d4);
 l(d5);
 l(d6);
 l(d7);
 l(d8);
 l(d9);
 l(d10);
 delay(a);
}
