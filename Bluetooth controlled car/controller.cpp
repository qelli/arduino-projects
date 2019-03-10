const int joyLR = 2;     //Declaramos el puerto analogico en el que conectaremos la señal del potenciometro "L/R" del Joystick  
const int joyUD = 4;    //Declaramos el puerto analogico en el que conectaremos la señal del potenciometro "U/D" del Joystick
int movservo;          //Variable en la que se guardara la lectura del Joystick L/R
int movservo2;        //Variable en la que se guardara la lectura del Joystick U/D
int t=100;           //Variable para delay

void setup() {
  Serial.begin(9600);      //Inicializamos el monitor serial
}

void loop(){

    movservo = analogRead(joyLR); // Se asigna el valor que se lea en el pin analogico "joyLR" a "movservo"
    movservo2 =analogRead(joyUD); // Se asigna el valor que se lea en el pin analogico "joyUD" a "movservo2"  

    // El rango de lectura de cada potenciometro del joystick es [0,1023], la media es aproximadamende de 500
          
   if((movservo < 10)&(movservo >= 0))  //Condiciones respecto a la lectura del joystick "Left/Right"
      {
        Serial.write('1'); //IZQUIERDA  (Se envia un "1" mediante la transmicion serial por el modulo bluetooth "Maestro" al modulo "Esclavo")
        delay(t);
      }
    else if((movservo > 900)&(movservo <= 1024))
      {
        Serial.write('2'); //DERECHA
        delay(t);
      }
  
    else if((movservo2 > 900)&(movservo2 <= 1023))  //Condiciones respecto a la lectura del joystick "Up/Down"
      {
        Serial.write('3'); //AVANZA
        delay(t);
      }
    else if((movservo2 < 10)&(movservo2 >= 0))
      {
        Serial.write('4'); //RETROCEDE
        delay(t);
      }
 
    else
    {
      Serial.write('5'); //DETENTE
      delay(t);
    }                                              
}