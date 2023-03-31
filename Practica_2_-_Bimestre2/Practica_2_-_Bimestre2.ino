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

#define adelante 2 
#define atras 3 
bool ad, at;
int i = 1;
int c = 1;

struct dato{ //datos del producto
  char nombre[50];
  float precio;
  int stock;
  char reserva[50];
  };
  
    dato p1 = {"Silla Gamer",1200.50,20,"2 en bodega local"};
    dato p2 = {"Mouse Logi",725.14,11,"10 unidades en bodegas Panfilo"};
    dato p3 = {"Teclado Mecanico",850,3,"12 unidades en almacenes Tropigas"};  
    dato p4 = {"RTX 3090",4500.60,2,"No hay en bodega"};
    
void setup() {
  Serial.begin(9600);
  pinMode(adelante,INPUT);
  pinMode(atras,INPUT);
  Serial.println("Bienvenido a CrispoGaming");
  Serial.println("Tenemos de todo en Dispositivos Electronicos");
  Serial.println("Con los botones puede navegar por nuestras opciones");}

void loop() {
  ad = digitalRead(adelante);
  at = digitalRead(atras);
  if (ad == 1){c = 1;}
  if (at == 1){c = 1;}

if(c == 1){
  if(ad == 1){i++; delay(250);}
  if(i > 4){i = 1; delay(250);}
  if(at == 1){i--; delay(250);}
  if(i< 1){i= 4; delay(250);}
  
  switch(i){
  case (1):
  Serial.println("********");
  Serial.println(p1.nombre);
  Serial.print("El precio unitario es Q"); Serial.println(p1.precio);
  Serial.print("Hay "); Serial.print(p1.stock); Serial.println(" unidades en stock");
  Serial.println(p1.reserva);
  Serial.print("El precio de lote es Q"); Serial.println(p1.precio * p1.stock);
  c++;
 break;

 case (2):
  Serial.println("********");
  Serial.println(p2.nombre);
  Serial.print("El precio unitario es Q");Serial.println(p2.precio);
  Serial.print("Hay "); Serial.print(p2.stock); Serial.println(" unidades en stock");
  Serial.println(p2.reserva);
  Serial.print("El precio de lote es Q");  Serial.println(p2.precio * p2.stock);
  c++;
 break;

 case (3):
  Serial.println("********");
  Serial.println(p3.nombre);
  Serial.print("El precio unitario es Q"); Serial.println(p3.precio);
  Serial.print("Hay ");Serial.print(p3.stock); Serial.println(" unidades en stock");
  Serial.println(p3.reserva);
  Serial.print("El precio de lote es Q");  Serial.println(p3.precio * p3.stock);
  c++;
 break;

 case (4):
  Serial.println("********");
  Serial.println(p4.nombre);
  Serial.print("El precio unitario es Q");  Serial.println(p4.precio);
  Serial.print("Hay ");  Serial.print(p4.stock); Serial.println(" unidades en stock");
  Serial.println(p4.reserva);
  Serial.print("El precio de lote es Q");  Serial.println(p4.precio * p4.stock);
  c++;
 break;
  }}}
