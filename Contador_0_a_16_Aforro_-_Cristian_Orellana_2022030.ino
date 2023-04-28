#include <Wire.h>
#include <LiquidCrystal.h>

#define out(pin) pinMode(pin,OUTPUT)
#define in(pin) pinMode(pin,INPUT)
#define h(pin) digitalWrite(pin, HIGH)
#define l(pin) digitalWrite(pin, LOW)
#define RS  2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define trig 8
#define echo 9
#define buzz 10

int distancia;
int conteo = 0;
int duracion;

LiquidCrystal LCD_samsung(RS, E, D4, D5, D6, D7);
void ultrasonico();
void  mostrar_LCD();

byte personaEstatica[] = {
B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};

byte personaSaltando[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

void setup() {
LCD_samsung.createChar(1,personaEstatica);
LCD_samsung.createChar(2,personaSaltando);
LCD_samsung.begin(16,2);
out(trig);
out(buzz);
in(echo);
}

void loop() {
ultrasonico();
mostrar_LCD();
}

void ultrasonico(){ //funcion para leer al ultrasonico

  h(trig);
  delay(1);
  l(trig);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 58.2;
  }
  
void  mostrar_LCD(){ //funcion para escribir numeros en el display
  if(distancia > 5 && distancia < 11 && conteo < 16){
    conteo = conteo + 1;
    delay(300);
  }
 switch (conteo){
  case 0:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 0 ");
  break;
  
  case 1:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 1 ");
  LCD_samsung.setCursor(0,1);
  LCD_samsung.write(1);
  break;
 
  case 2:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 2 "); 
  LCD_samsung.setCursor(1,1);
  LCD_samsung.write(1);
  break;
  
  case 3:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 3 "); 
  LCD_samsung.setCursor(2,1);
  LCD_samsung.write(1); 
  break;
  
  case 4:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 4 "); 
  LCD_samsung.setCursor(3,1);
  LCD_samsung.write(1); 
  break;
  
  case 5:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 5 ");   
  LCD_samsung.setCursor(4,1);
  LCD_samsung.write(1);  
  break;
  
  case 6:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 6 "); 
  LCD_samsung.setCursor(5,1);
  LCD_samsung.write(1);  
  break;

   case 7:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 7 ");
  LCD_samsung.setCursor(6,1);
  LCD_samsung.write(1);   
  break;

  case 8:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 8 "); 
  LCD_samsung.setCursor(7,1);
  LCD_samsung.write(1); 
  break;
  
  case 9:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 9 ");
  LCD_samsung.setCursor(8,1);
  LCD_samsung.write(1); 
  break;
  
 case 10:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 10 "); 
  LCD_samsung.setCursor(9,1);
  LCD_samsung.write(1); 
  break;
  
 case 11:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 11 "); 
  LCD_samsung.setCursor(10,1);
  LCD_samsung.write(1); 
  break;
  
 case 12:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 12 "); 
  LCD_samsung.setCursor(11,1);
  LCD_samsung.write(1); 
  break;
  
 case 13:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 13 ");
  LCD_samsung.setCursor(12,1);
  LCD_samsung.write(1); 
  break;
  
 case 14:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 14 ");
  LCD_samsung.setCursor(13,1);
  LCD_samsung.write(1);  
  break;
  
 case 15:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 15 "); 
  LCD_samsung.setCursor(14,1);
  LCD_samsung.write(1); 
  break;
  
 case 16:
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("Personas: 16 ");
  tone(buzz, 261*2);
  
  for(int xd = 0; xd < 17; xd++){
  LCD_samsung.setCursor(xd,1);
  LCD_samsung.write(1); 
    } delay(350); 
    
  LCD_samsung.setCursor(0,0);    
  LCD_samsung.write("      FULL      ");
  tone(buzz, 0);
  
  for(int xd = 0; xd < 17; xd++){
  LCD_samsung.setCursor(xd,1);
  LCD_samsung.write(2); 
    } delay(350);  
  break;
  }
}
