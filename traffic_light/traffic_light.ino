#include "Led.h"

LED GreenLed(7);
LED YellowLed(6);
LED RedLed(5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  RedLed.on();
  }

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("輸入1為開始:");
  char startChar = Serial.read();
  if (startChar=='1'){
    delay(100);
    
    RedLed.off();
    delay(500);
    YellowLed.on();
    delay(500);
    YellowLed.off();
    delay(100);
    GreenLed.on(); 
    delay(1000);
  }else{
      RedLed.on();
      GreenLed.off();
      YellowLed.off();
  }
}
