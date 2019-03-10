#include <pitches.h>
#include <Keypad.h>
#include <LiquidCrystal.h>



const byte numRows=4;
const byte numCols=4;
char keyMap[numRows][numCols]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[numRows]={9,8,7,6};
byte colPins[numCols]={5,4,3,2};

Keypad keypad=Keypad(makeKeymap(keyMap),rowPins,colPins,numRows,numCols);

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

int buzzPin=10;

void setup(){
 lcd.begin(16,2);
  pinMode(buzzPin,OUTPUT);
  randomSeed(analogRead(7));
}


void loop(){
  lcd.clear();
  lcd.setCursor(0,1);
  
  int num1=random(2,11);
  int num2=random(2,11);
  int result=num1*num2;
  
  String mult=String(num1)+"x"+String(num2)+"=";
  lcd.print(mult);
  
  int hit=readVal().toInt();
  lcd.setCursor(0,1);
  
  if(result==hit){
   lcd.print(":-)");
   playHappy();
  }else{
   lcd.print(":-("+String(result));
    playAlarm();
  }
  
  hit=readVal().toInt();
  
}


String readVal(){
 String s="";
  char keyPressed=keypad.getKey();
  while(keyPressed!='#'){
   keyPressed=keypad.getKey(); 
    if((keyPressed!=NO_KEY) && (keyPressed!='#')){
     s.concat(keyPressed);
     lcd.print(keyPressed);
     playTone(); 
    }
  }
  return(s);
}


void playHappy(){
  int melody[]={NC4,NC4,ND4,NC4,NF4,NE4,
                NC4,NC4,ND4,NC4,NG4,ND4,
                NC4,NC4,NC5,NA4,NF4,NE4,ND4,
                NAS4,NAS4,NA4,NF4,NG4,NF4}; 
  int noteDurations[]={6,12,4,4,4,2,
                      6,12,4,4,4,2,
                      6,12,4,4,4,4,2,
                       6,12,4,4,4,2};
  
  for(int thisNote=0; thisNote<12; thisNote++){
   int noteDuration=1000/noteDurations[thisNote];
    tone(buzzPin,melody[thisNote],noteDuration);
    int pauseBetweenNotes=noteDuration*1.30;
    delay(pauseBetweenNotes);
    noTone(buzzPin);
  }
}



void playAlarm(){
  
  for(int thisNote=150; thisNote<1000; thisNote+=1){
   tone(buzzPin,thisNote,10);
    delay(1);
  }

  for(int thisNote=1000;thisNote>150; thisNote-=1){
   tone(buzzPin,thisNote,10);
    delay(1);
  }
  
}






void playTone(){
 
  tone(buzzPin,150,10);
  
}
