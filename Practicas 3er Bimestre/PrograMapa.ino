/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombres: Cristian Estuardo Orellana Dieguez
 * Nombre: Luis Andres Muñiz Godoy1
*/
//Librerias
#include <Wire.h>
#include <SoftwareSerial.h>
#include <PCF8574.h>

//Directivas
#define PHIGH LOW  
#define PLOW HIGH  
#define buzz 2
#define rx 3
#define tx 4
#define altaV 5
#define bajaV 6
#define chimaltenango 7
#define chiquimula 8
#define guatemala 9
#define elprogreso 10
#define escuintla 11
#define huehuetenango 12
#define izabal 13
#define jalapa  A0
#define jutiapa A1
#define peten A2
#define quetzaltenango A3
#define quiche A4
#define retalhuleu A5
#define sacatepequez A6
#define sanmarcos A7
#define santarosa 2
#define solola 3
#define suchitepequez 4
#define totonicapan 5
#define zacapa 6

  #define Do 262
  #define Dosos 277
  #define Re 294
  #define Resos 311
  #define Mi 330
  #define Fa 349
  #define Fasos 370
  #define Sol 392
  #define Solsos 415
  #define La 440
  #define Lasos 466
  #define Si 494
  
//Constructores
SoftwareSerial bt(rx, tx);
PCF8574 expansor(0x27);

//Variables
bool iniciar = false;
String respuesta;
int nrandom;

//Funciones
void fallo();
void quiz();
void pines();
void apagarLed();

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  Wire.begin();
  expansor.begin();
  pines();
  Serial.println("Bienvenido a Guate te enseña.com");  
  Serial.println("Para empezar Escriba (Iniciar) ");   
  Serial.println("Para finalizar Escriba (Fin) ");   
}

void loop() {
  if(Serial.available()>0){
    String empezar = Serial.readStringUntil('\n');
  if ( empezar == String("Iniciar")){
  Serial.println("Primera pregunta");   
  iniciar = true;
    delay(100);
  }
  }
  
  if (iniciar == true){
  nrandom = random(0, 21);
  quiz();
  delay(500);
  Serial.println("Siguiente pregunta");   
  }
  
  if(iniciar == false){
  Serial.println("Escribe (Iniciar) para empezar el Quiz");
 }
}

void quiz(){
   if(nrandom == 0){
    Serial.println("Cabecera departamental de Petén");
      if(respuesta == String("Flores")){    //Respuesta correcta
        apagarLed();        
        digitalWrite(peten, HIGH);   
      }
      else{
       fallo();
       }
      }
           
      if(nrandom == 1){
    Serial.println("Cabecera departamental de Izabal");
      if(respuesta == String("Puerto Barrios")){    //Respuesta correcta
        apagarLed();
        digitalWrite(izabal, LOW);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 2){
    Serial.println("Cabecera departamental de Alta Verapaz");
      if(respuesta == String("Coban")){    //Respuesta correcta
        apagarLed();  
        digitalWrite(altaV, LOW);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 3){
    Serial.println("Cabecera departamental de Quiché");
      if(respuesta == String("Santa Cruz del Quiche")){   //Respuesta correcta
         apagarLed();  
         digitalWrite(quiche, LOW);   
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 4){
    Serial.println("Cabecera departamental de Huehuetenango");
      if(respuesta == String("Huehuetenango")){  //Resuesta Correcta
              apagarLed();  
        digitalWrite(huehuetenango, LOW);
      }
      else{
       fallo();
       }
      }
      
       if(nrandom == 5){
    Serial.println("Cabecera departamental de Escuintla");
      if(respuesta == String("Escuintla")){
              apagarLed();  
        digitalWrite(escuintla, LOW); 
      }
      else{
       fallo();
       }
      }
      
        if(nrandom == 6 ){
    Serial.println("Cabecera departamental de San Marcos");
      if(respuesta == String("San Marcos")){
              apagarLed();  
        digitalWrite(sanmarcos, LOW);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 7 ){
    Serial.println("Cabecera departamental de Jutiapa");
      if(respuesta == String("Jutiapa")){
              apagarLed();  
        digitalWrite(jutiapa, LOW);  
      }
      else{
      fallo();
       }
      }
      
      if(nrandom == 8 ){
    Serial.println("Cabecera departamental de Baja Verapaz");
      if(respuesta == String("Salama")){
             apagarLed();  
        digitalWrite(bajaV, LOW); 
      }
      else{
       fallo();
       }
      }
      
       if(nrandom == 9 ){
    Serial.println("Cabecera departamental de Santa Rosa");
      if(respuesta == String("Cuilapa")){
             apagarLed();  
        expansor.write(santarosa, PLOW);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 10 ){
    Serial.println("Cabecera departamental de Zacapa");
      if(respuesta == String("Zacapa")){
              apagarLed();  
        expansor.write(zacapa, PLOW);         
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 11 ){
    Serial.println("Cabecera departamental de Suchitepéquez");
      if(respuesta == String("Mazatenango")){
              apagarLed();  
        expansor.write(suchitepequez, PLOW);        
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 12 ){
    Serial.println("Cabecera departamental de Chiquimula");
      if(respuesta == String("Chiquimula")){
              apagarLed();  
        digitalWrite(chiquimula, LOW);   
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 13 ){
    Serial.println("Cabecera departamental de Guatemala");
      if(respuesta == String("Guatemala")){
              apagarLed();  
        digitalWrite(guatemala, LOW); 
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 14 ){
    Serial.println("Cabecera departamental de Jalapa");
      if(respuesta == String("Jalapa")){
             apagarLed();  
        digitalWrite(jutiapa, HIGH);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 15 ){
    Serial.println("Cabecera departamental de Chimaltenango");
      if(respuesta == String("Chimaltenango")){
             apagarLed();  
        digitalWrite(chimaltenango, HIGH);  
      }
      else{
        fallo();
       }
      }
      
      if(nrandom == 16 ){
    Serial.println("Cabecera departamental de Quetzaltenango");
      if(respuesta == String("Quetzaltenango")){
             apagarLed();  
        digitalWrite(quetzaltenango, HIGH);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 17 ){
    Serial.println("Cabecera departamental de El progreso");
      if(respuesta == String("Guastatoya")){
             apagarLed();  
        digitalWrite(elprogreso, HIGH);  
      }
      else{
     fallo();
       }
      }
      
      if(nrandom == 18 ){
    Serial.println("Cabecera departamental de Retalhuleu");
      if(respuesta == String("Retalhuleu")){
              apagarLed();  
        digitalWrite(retalhuleu, HIGH);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 19 ){
    Serial.println("Cabecera departamental de Sololá");
      if(respuesta == String("Solola")){
             apagarLed();  
        expansor.write(solola, PLOW);          
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 20 ){
    Serial.println("Cabecera departamental de Totonicapán");
      if(respuesta == String("Totonicapan")){
             apagarLed();  
        expansor.write(totonicapan, PLOW);  
      }
      else{
       fallo();
       }
      }
      
      if(nrandom == 21 ){
    Serial.println("Cabecera departamental de Sacatepéquez");
      if(respuesta == String("La antigua guatemala")){
              apagarLed();  
        digitalWrite(sacatepequez, LOW);  
      }
      else{
       fallo();
       }
      }
      
      if(respuesta == String("Fin")){
       iniciar = false;
       Serial.print("Juego Finalizado");
    }
  }
  
void fallo(){
  }
  
void apagarLed(){
       digitalWrite(peten, LOW); 
       digitalWrite(izabal, LOW);   
       digitalWrite(altaV, LOW); 
       digitalWrite(quiche, LOW); 
       digitalWrite(huehuetenango, LOW); 
       digitalWrite(escuintla, LOW);   
       digitalWrite(sanmarcos, LOW); 
       digitalWrite(jutiapa, LOW);
       digitalWrite(bajaV, LOW); 
       expansor.write(santarosa, PLOW);   
       expansor.write(zacapa, PLOW); 
       expansor.write(suchitepequez, PLOW); 
       digitalWrite(chiquimula, LOW); 
       digitalWrite(guatemala, LOW);   
       digitalWrite(jalapa, LOW); 
       digitalWrite(chimaltenango, LOW);
       digitalWrite(quetzaltenango, LOW); 
       digitalWrite(elprogreso, LOW);   
       digitalWrite(retalhuleu, LOW); 
       expansor.write(solola, PLOW); 
       expansor.write(totonicapan, PLOW); 
       digitalWrite(sacatepequez, LOW);   
  }
  
void pines(){
       pinMode(buzz, OUTPUT); 
       pinMode(peten, OUTPUT); 
       pinMode(izabal, OUTPUT);   
       pinMode(altaV, OUTPUT); 
       pinMode(quiche, OUTPUT); 
       pinMode(huehuetenango, OUTPUT); 
       pinMode(escuintla, OUTPUT);   
       pinMode(sanmarcos, OUTPUT); 
       pinMode(jutiapa, OUTPUT);
       pinMode(bajaV, OUTPUT);   
       pinMode(chiquimula, OUTPUT); 
       pinMode(guatemala, OUTPUT);   
       pinMode(jalapa, OUTPUT); 
       pinMode(chimaltenango, OUTPUT);
       pinMode(quetzaltenango, OUTPUT); 
       pinMode(elprogreso, OUTPUT);   
       pinMode(retalhuleu, OUTPUT); 
       pinMode(sacatepequez, OUTPUT);   
  }
