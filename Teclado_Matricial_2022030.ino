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

#include <Keypad.h>
#define out(pin) pinMode(pin,OUTPUT)
#define in(pin) pinMode(pin,INPUT)
#define h(pin) digitalWrite(pin, HIGH)
#define l(pin) digitalWrite(pin, LOW)
#define f1 2
#define f2 3
#define f3 4
#define f4 5
#define c1 6
#define c2 7
#define c3 8
#define c4 9
#define a 10
#define b 11
#define c 12
#define d 13
#define e A0
#define f A1
#define g A2
const byte filas = 4; //four rows
const byte columnas = 4; //four columns

char matriz[filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinfil[filas] = {f1, f2, f3, f4}; //connect to the row pinouts of the keypad
byte pincol[columnas] = {c1, c2, c3, c4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad teclado = Keypad( makeKeymap(matriz), pinfil, pincol, filas, columnas); 

void setup(){
  out(a);
  out(b);
  out(c);
  out(d);
  out(e);
  out(f);
  out(g);
}
  
void loop(){
  char tecla = teclado.getKey();
  int i = 1000;
  h(a);
  h(b);
  h(c);
  h(d);
  h(e);
  h(f);
  l(g);
switch(tecla){
    case '0':
  h(a);
  h(b);
  h(c);
  h(d);
  h(e);
  h(f);
  l(g);
    delay(i);
    break;
    
    case '1':
  l(a);
  h(b);
  h(c);
  l(d);
  l(e);
  l(f);
  l(g);
     delay(i);
    break;
    
    case '2':
  h(a);
  h(b);
  l(c);
  h(d);
  h(e);
  l(f);
  h(g);
     delay(i);
    break;
    
    case '3':
  h(a);
  h(b);
  h(c);
  h(d);
  l(e);
  l(f);
  h(g);
     delay(i);
    break;
    
    case '4':
  l(a);
  h(b);
  h(c);
  l(d);
  l(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case '5':
  h(a);
  l(b);
  h(c);
  h(d);
  l(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case '6':
  h(a);
  l(b);
  h(c);
  h(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case '7':
  h(a);
  h(b);
  h(c);
  l(d);
  l(e);
  l(f);
  l(g);
     delay(i);
    break;
    
    case '8':
  h(a);
  h(b);
  h(c);
  h(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case '9':
  h(a);
  h(b);
  h(c);
  h(d);
  l(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case 'A':
  h(a);
  h(b);
  h(c);
  l(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case 'B':
  l(a);
  l(b);
  h(c);
  h(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case 'C':
  l(a);
  l(b);
  l(c);
  h(d);
  h(e);
  l(f);
  h(g);
     delay(i);
    break;
    
    case 'D':
  l(a);
  h(b);
  h(c);
  h(d);
  h(e);
  l(f);
  h(g);
     delay(i);
    break;
    
  case '*':
  h(a);
  l(b);
  l(c);
  h(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
     case '#':
  h(a);
  l(b);
  l(c);
  l(d);
  h(e);
  h(f);
  h(g);
     delay(i);
    break;
    
    case 0: 
  h(a);
  h(b);
  h(c);
  h(d);
  h(e);
  h(f);
  l(g);
  delay(i);
    break;
  }
}
