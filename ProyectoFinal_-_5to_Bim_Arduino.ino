#include <Wire.h> 
#define VoltajePin A0
#define CorrientePin A1
#define Ohms A2

float sensibilidad = 0.185;  
const float resistenciaBase = 1000.0;
const int promedio = 10;
float sumaDeResistencias = 0.0;

char comunicacion;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if (Serial1.available()) {
    comunicacion = Serial1.read();
    Serial.println(comunicacion);

    switch (comunicacion) {
      case '1':
       float voltaje = (float)25 * analogRead(VoltajePin) / 1023;
      Serial.print("Voltaje medido = ");
      Serial.println(voltaje);
      Serial1.print(voltaje);
      Serial1.print(' ');
      delay(500);
        break;
        
      case'2':
 sumaDeResistencias = 0.0;
  for (int i = 0; i < promedio; i++) {
    int estado = analogRead(Ohms);
    float voltaje = (5.0 / 1023.0) * estado;
    float resistenciaDesconocida = (voltaje * resistenciaBase) / (5.0 - voltaje);
    sumaDeResistencias += resistenciaDesconocida;
    delay(10); // Pequeña pausa entre lecturas para evitar ruido
  }
   float resistenciapromedio = sumaDeResistencias / promedio;
   Serial.println(sumaDeResistencias);
   Serial1.print(sumaDeResistencias,2);
   Serial1.print(' ');
   delay(500);
      break;

      case'3':
   float VoltajeSensor = analogRead(CorrientePin)*(5.0/1023);  // Lee el valor analógico del sensor
   float corriente = (VoltajeSensor - 2.5)/sensibilidad ;    // Convierte el valor en milivoltios
   Serial.print("Corriente: ");
   Serial.print(corriente, 2);  // Imprime la corriente con 2 decimales
   Serial1.print(corriente, 2);
   Serial1.print(' ');
   Serial.println(" A");
   delay(500);  
      break;
      
      case '4':
      Serial.println("off");
      Serial1.print(';');
      break;
    }
  }
}
