/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: Cristian Estuardo Orellana Dieguez
*/

#include <LedControl.h>
#include <Ticker.h>
#define dato 4
#define clk 3
#define cs 2
void lecturaGas(void);
LedControl lucesGod = LedControl(dato,clk,cs,1); 
Ticker isrGas(lecturaGas, 5000);
#define sensorG  A0

const int ancho = 8; 
const int alto = 8; 
int valor;
int prom;

byte fuego1[8] = {
B00010000,
B00101000,
B01001000,
B01000110,
B01000010,
B01000010,
B00111100,
B00000000
};
byte fuego2[8] = {
B10010010,
B10101010,
B01001000,
B01000110,
B01000010,
B01000010,
B00111100,
B00000000
};
byte copo1 [8] = {
B00000000,
B00000000,
B01010100,
B00111000,
B01101100,
B00111000,
B01010100,
B00000000
};

byte copo2 [8] = {
B00000000,
B10010010,
B01010100,
B00111000,
B11101110,
B00111000,
B01010100,
B10010010
};

void setup() {
  lucesGod.shutdown(0, false); 
  lucesGod.setIntensity(0, 15); 
  lucesGod.clearDisplay(0); 
  pinMode(sensorG, INPUT); 
  isrGas.start();
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de gas
 isrGas.update();
  if (prom > 50) {
    alerta_fuego();
  } 
  else {
    for (int i = 0; i < alto; i++) {
    lucesGod.setColumn(0, i, copo1[i]);
  }
    delay(500);
    for (int i = 0; i < alto; i++) {
    lucesGod.setColumn(0, i, copo2[i]);
  }
  }
  delay(1000);
}
void lecturaGas(){
  int suma =0;
  for(int i = 0; i < 5; i++){
  valor = map(analogRead(sensorG),0,1023,0,100);
  suma = suma + valor;
  delay(100);
  }
  prom = suma/5;

 Serial.println(prom);
}

void alerta_fuego() {
  lucesGod.clearDisplay(0);
for(int t = 0; t<5;t++){
  for (int i = alto; i > 0; i--) {
    lucesGod.setColumn(0, i, fuego1[i]);
  }
  delay(500);
  
  for (int i = alto; i > 0; i--) {
    lucesGod.setColumn(0, i, fuego2[i]);
  }
  delay(500);
}
}
