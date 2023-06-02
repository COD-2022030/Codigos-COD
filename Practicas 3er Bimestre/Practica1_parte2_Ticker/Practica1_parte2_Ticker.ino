/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM 
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Cristian Estuardo Orellana Dieguez
*/
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Ticker.h>

//directivas de preprocesador
#define boton 4
//Variables
volatile static bool estado;
  
//Funciones
void isrTemp(void);
void isrBoton(void);

//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensorCR7(&ourWire); //Se declara una objeto para nuestro sensor
Ticker accionTemp(isrTemp, 3000);
Ticker accionBoton(isrBoton, 6000);

void setup() {
  Serial.begin(19200);
  pinMode(boton, INPUT);
  sensorCR7.begin();
  accionTemp.start();
  accionBoton.start();
  Serial.println("Inicia la interactividad");
}

void loop() {
accionTemp.update();
accionBoton.update();
}

void isrTemp(void){
  sensorCR7.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensorCR7.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print("**** ");  
  Serial.print("La temperatura es: ");  
  Serial.print(temp);
  Serial.print(" C");  
  Serial.println(" ****");
  }
  
void isrBoton(void){
  estado = digitalRead(boton);
  if(estado == HIGH){
    Serial.println("//// Boton Activado ////");

    }
  if(estado == LOW){
    Serial.println("//// Boton Desactivado ////");
    }
  }
