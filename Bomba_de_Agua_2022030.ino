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
#define out(pin) pinMode(pin,OUTPUT)
#define in(pin) pinMode(pin,INPUT)
#define h(pin) digitalWrite(pin, HIGH)
#define l(pin) digitalWrite(pin, LOW)
#define ledR 2
#define ledA 3
#define transistor 4
#define rele 5
void setup() {
  out(ledR);
  out(ledA);
  out(rele);
  in(transistor);
}

void loop() {
  bool activacion = digitalRead(transistor);
  if(activacion == HIGH){
    l(ledR);
    h(ledA);
    h(rele);
  }

  if(activacion == LOW){
    l(ledA);
    h(ledR);
    l(rele);
  }
}
