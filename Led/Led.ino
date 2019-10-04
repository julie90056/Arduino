#include "Led.h"

LED GreenLed(7);
LED YellowLed(6);
LED RedLed(5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println( GreenLed.getPinNum());
  Serial.println( YellowLed.getPinNum());
  Serial.println( RedLed.getPinNum());
  
  RedLed.on();
  }

void loop() {
  // put your main code here, to run repeatedly:
  RedLed.on();
  GreenLed.off();
  YellowLed.off();
  delay(500);
  GreenLed.on();
  YellowLed.on();
  delay(500);
  
}
