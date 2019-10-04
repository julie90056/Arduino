#include "Led.h"
#define BtnPin 2

boolean BtnState;
unsigned int count=0;
unsigned int clickcount=0;
LED redLed (13);
LED greenLed (12);
LED yellowLed (11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BtnPin,INPUT_PULLUP);
  BtnState= digitalRead(BtnPin);
  redLed.off();
  greenLed.off();
  yellowLed.off();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  boolean nowState = digitalRead(BtnPin);
  if(BtnState != nowState){
    delay(10);
    if (nowState==digitalRead(BtnPin)){
    BtnState = nowState;
    count++;
    switch(count%4){
      case 0:
         redLed.off();
         greenLed.off();
         yellowLed.off();       
          break;
      case 2:
          redLed.on();
          delay(500);
          greenLed.on();
          delay(500);
          yellowLed.on();
          break;
    }
  }
  
  }
  Serial.print("you click:");
  Serial.println(clickcount);
}
