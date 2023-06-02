/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Cristian Estuardo Orellana Dieguez
 * Carnet: 2022030
*/

//Directivas de Preprocesador
#define avanzar 2
#define disminuir 3
#define d 7
#define c 6
#define b 5
#define a 4
#define a1 8
#define b1 9
#define c1 10
#define out(pin) pinMode(pin, OUTPUT)
#define in(pin) pinMode(pin, INPUT);

//Funciones ISR
void funcion_ISR_falling(void);
void funcion_ISR_rising(void);

//funciones
void pines();
void displayy(int dd,int cc, int bb,int aa);
void displayy2(int cc1, int bb1, int aa1);

//Variables
volatile static int unidades = 0;
volatile static int decenas = 0;

void setup() {
  pines();
  attachInterrupt(digitalPinToInterrupt(avanzar),funcion_ISR_rising,RISING);   
  attachInterrupt(digitalPinToInterrupt(disminuir),funcion_ISR_falling,FALLING);
}

void loop() {
  if(unidades > 9){
    unidades = 0;
    decenas++;
    }
  if(unidades == -1){
    unidades = 9;
    decenas--;
    }
  if(decenas < 0){
    decenas = 5;
    unidades =0;
    }
  if(decenas == 5 && unidades > 0){
    decenas = 0;
    unidades = 0;
    }
switch (unidades){
  case 0:
 displayy(0, 0, 0, 0);  
  break;
  
  case 1:
 displayy(0, 0, 0, 1); 
  break;
 
  case 2:
 displayy(0, 0, 1, 0);  
  break;
  
  case 3:
 displayy(0, 0, 1, 1);    
  break;
  
  case 4:
 displayy(0, 1, 0, 0);    
  break;
  
  case 5:
 displayy(0, 1, 0, 1);   
  break;
  
  case 6:
 displayy(0, 1, 1, 0);     
  break;

   case 7:
 displayy(0, 1, 1, 1);  
  break;

  case 8:
 displayy(1, 0, 0, 0);   
  break;
  
  case 9:
 displayy(1, 0, 0, 1);    
  break;  
  }
  
switch (decenas){
  case 0:
 displayy2(0,0, 0);  
  break;
  
  case 1:
 displayy2(0, 0, 1); 
  break;
 
  case 2:
 displayy2(0, 1, 0);  
  break;
  
  case 3:
 displayy2(0, 1, 1);    
  break;
  
  case 4:
 displayy2(1, 0, 0);    
  break;
  
  case 5:
 displayy2(1, 0, 1);   
  break;
 }
}

void pines(){
  out(a);
  out(b);
  out(c);
  out(d);
  out(a1);
  out(c1);
  out(b1);
  in(avanzar);  //pin 2 como entrada
  in(disminuir); //pin 3 como entrada
  }
  
void displayy(int dd,int cc, int bb,int aa){ 
digitalWrite(d, dd);
digitalWrite(c, cc); //funcion para encender los segmentos necesarios
digitalWrite(b, bb);
digitalWrite(a, aa);
 }
 
void displayy2(int cc1, int bb1, int aa1){ 
digitalWrite(c1, cc1); //funcion para encender los segmentos necesarios
digitalWrite(b1, bb1);
digitalWrite(a1, aa1);
 }
 
void funcion_ISR_rising(void){
  unidades++;
  }
  
void funcion_ISR_falling(void){ 
  unidades--; 
  }
