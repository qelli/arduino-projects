#include <Servo.h>    //Incluimos la biblioteca Servo.h a nuestro codigo
       
Servo izq; // Definimos un objeto tipo Servo, llamado "izq" que usaremos para poder controlar la rueda izquierda del robot
Servo der;  // Definimos un objeto tipo Servo, llamado "der" que usaremos para poder controlar la rueda derecha del robot
int dato=0;  //Variable que albergara el dato que nos envíe el programa "Maestro" pormedio del bluetooth

void setup() {
  izq.attach(3);  //vinculamos el puerto digital "3" al objeto "izq" que será donde estará conectado el motor izquierdo del robot
  der.attach(10); 
  Serial.begin(9600);   //Inicializamos el monitor serial a 9600 baudios
  pinMode(4,OUTPUT);     //Pines digitales para la conexion de LED 
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop(){

  if( Serial.available())   //Preguntamos si la recepcion de datos por el monitor serial esta disponible
  {
    dato = Serial.read();    //Se lee el valor recibido en el monitor serial y se le asigna el mismo a la variable "dato"
  }
    if(dato == '1')         // Si ese valor, es igual a "1"...
    {
      Serial.println(dato);    //Se imprime el dato
      digitalWrite(4,HIGH);    //se alimenta el led colocado a la izquierda de la conexion que indica el giro a la izquierda
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      izquierda();              //mandamos a llamar a la funcion "izquierda" que ejecuta las instrucciones para que el robot gire a la izquierda
    } 
    if(dato == '2')
    {
      Serial.println(dato);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      derecha();
    } 
    if(dato == '3')
    {
      Serial.println(dato);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      avanza();
    } 
    if(dato == '4')
    {
      Serial.println(dato);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      retrocede();
    } 
    if(dato == '5')
    {
      Serial.println(dato);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      detente();
    } 
                                               
}

    //Funciones creadas como apoyo y mejor estructura de nuestro codigo

void izquierda(){

    izq.write(90);
    der.write(180);
  }
void derecha(){

    izq.write(0);
    der.write(90);
  }
void avanza(){

    izq.write(0);
    der.write(180);
  }
void retrocede(){

    izq.write(180);
    der.write(0);
  }
void detente(){

    izq.write(90);
    der.write(90);
  }