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
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define trig 9
#define echo 10
#define rele 12
int duracion;
int distancia;
int conteo = 0;

void displayy(int a1, int b1, int c1, int d1, int e1, int f1, int g1);
void ultrasonico(); 
void  mostrar_Display();
void relefuncion();  
void setup() {
  Serial.begin(9600);
  out(a);
  out(b);
  out(c);
  out(d);
  out(e);
  out(f);
  out(g);
  out(trig);
  in(echo);
  out(rele);
}

void loop() {
 ultrasonico();
 mostrar_Display();
 relefucion();
}
 
void ultrasonico(){
  h(trig);
  delay(1);
  l(trig);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;

  }

void  mostrar_Display(){
  int r = 250;
  if(distancia > 5 && distancia < 11){
    conteo = conteo + 1;
    delay(500);
  }
 switch (conteo){
  case (0):
 displayy(1, 1, 1,1, 1, 1, 0);
 delay(r);  
  break;
  case (1):
 displayy(0, 1, 1, 0, 0, 0, 0);  
  break;
  delay(r);   
  case 2:
 displayy(1, 1, 0, 1, 1, 0, 1); 
  delay(r);  
  break;
  case 3:
 displayy(1, 1, 1, 1, 0, 0, 1); 
  delay(r);  
  break;
  case 4:
 displayy(0, 1, 1, 0, 0, 1, 1); 
  delay(r);  
  break;
  case 5:
 displayy(1, 0, 1, 1, 0, 1, 1); 
  delay(r);  
  break;
  case 6:
 displayy(1, 0, 1, 1, 1, 1, 1); 
  delay(r);  
  break;

   case 7:
 displayy(1, 1, 1, 0, 0, 0, 0); 
  delay(r);  
  break;

  case 8:
 displayy(1, 1, 1, 1, 1, 1, 1); 
  delay(r);  
  break;
  
  case 9:
 displayy(1, 1, 1, 1, 0, 1, 1);
  delay(r);  
  break;
  }
}

void relefucion(){
 if(conteo > 8 && conteo < 10){
h(rele); 
   }else if(conteo < 9){
    l(rele);
    }
  }


void displayy(int a1, int b1, int c1, int d1, int e1, int f1, int g1){ 
digitalWrite(a, a1); //funcion para encender los segmentos necesarios
digitalWrite(b, b1);
digitalWrite(c, c1);
digitalWrite(d, d1);
digitalWrite(e, e1);
digitalWrite(f, f1);
digitalWrite(g, g1);
  }
