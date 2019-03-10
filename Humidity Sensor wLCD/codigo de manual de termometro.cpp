#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
 // Initialize the library with the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
dht.begin();

}
void loop() {  
int h = dht.readHumidity();// Lee la humedad
int t= dht.readTemperature();//Lee la temperatura
//////////////////////////////////////////////////Humedad
lcd.setCursor(0,0);   //columna 0, fila 0
lcd.print("Humedad:  %");   //8 caracteres
lcd.setCursor(8,0);
lcd.print(h);         //Escribe la humedad
//Serial.println(" %");                    
///////////////////////////////////////////////////Temperatura              
lcd.setCursor(0,1);
lcd.print("Temperatura:   C");                  
lcd.setCursor(12,1);
lcd.print(t);//Escribe la temperatura
           
}