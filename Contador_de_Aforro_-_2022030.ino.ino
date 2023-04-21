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
#define a 2 // pines del Display
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define trig 9 //pines del ultrasonico
#define echo 10
#define rele 12 // pin rele
//variables globales
int duracion;
int distancia;
int conteo = 0;

void displayy(int a1, int b1, int c1, int d1, int e1, int f1, int g1); // declaracion de funciones
void ultrasonico(); 
void  mostrar_Display();
void relefuncion();  
void pines();

void setup() {
pines();
}

void loop() {
 ultrasonico();
 mostrar_Display();
 relefucion();
}
 
void ultrasonico(){ //funcion para leer al ultrasonico
  h(trig);
  delay(1);
  l(trig);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;
  }

void  mostrar_Display(){ //funcion para escribir numeros en el display
  if(distancia > 5 && distancia < 11){
    conteo = conteo + 1;
    delay(300);
  }
 switch (conteo){
  case (0):
 displayy(1, 1, 1,1, 1, 1, 0);  
  break;
  
  case (1):
 displayy(0, 1, 1, 0, 0, 0, 0);  
  break;
 
    
  case 2:
 displayy(1, 1, 0, 1, 1, 0, 1);  
  break;
  
  case 3:
 displayy(1, 1, 1, 1, 0, 0, 1);   
  break;
  
  case 4:
 displayy(0, 1, 1, 0, 0, 1, 1);   
  break;
  
  case 5:
 displayy(1, 0, 1, 1, 0, 1, 1);   
  break;
  
  case 6:
 displayy(1, 0, 1, 1, 1, 1, 1);   
  break;

   case 7:
 displayy(1, 1, 1, 0, 0, 0, 0);   
  break;

  case 8:
 displayy(1, 1, 1, 1, 1, 1, 1);   
  break;
  
  case 9:
 displayy(1, 1, 1, 1, 0, 1, 1);  
  break;
  }
}

void relefucion(){ //activar y desactivar rele
 if(conteo == 9){
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
  
  void pines(){
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
