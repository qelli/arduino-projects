#include <LiquidCrystal.h>
#include <DHT.h>


#define DHTP A0
#define DHTT DHT11

LiquidCrystal lcd(7,8,9,10,11,12);

DHT dht(DHTP,DHTT);

void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.begin(12,6);
}


void loop(){
  int iTemp=dht.readTemperature();
  int iHum=dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(iTemp);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.print(iHum);
  lcd.print("%");
}

