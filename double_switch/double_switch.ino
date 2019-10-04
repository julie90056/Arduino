#include "SwitchButton.h"
#include "Led.h"
SwitchButton LeftSW (4);
SwitchButton RightSW (2);
LED redLed(8);
LED yellowLed(9);
LED greenLed(10);
LED Led1(11);
LED Led2(12);
LED Led3(13);


void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  redLed.off();
  yellowLed.off();
  greenLed.off();
  Led1.off();
  Led2.off();
  Led3.off();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long LeftCounts= LeftSW.getStateChangeCount();
  Serial.print("Left Switch Click:");
  Serial.println(LeftCounts);
  unsigned long RightCounts= RightSW.getStateChangeCount();
  Serial.print("Right Switch Click:");
  Serial.println(RightCounts);
  
  //製作left2段式
  if (LeftCounts!=0){
   
    switch (LeftCounts%4){
    //click一次時
    case 2:
      Serial.println("left1");
      redLed.on();
      yellowLed.on();
      greenLed.off();
      break;
    case 0:
      //click2次時
      Serial.println("left2");
      redLed.off();
      yellowLed.on();
      greenLed.on();
      break;     
    }
 
   switch (RightCounts % 6){
     case 2:
      //click一次時
      Serial.println("right1");
      Led1.on();
      delay(100);
      AlertLed.off();
      break;
    case 4:
      //click兩次時
      Serial.println("right2");
      AlertLed.on();
      delay(100);
      AlertLed.off();
      break;
    case 0:
      //click2次時
       Serial.println("right2");
      AlertLed.off();
      break;     
  }
    delay(100);
  }
}
