#include "Led.h"
#include "SwitchButton.h"
#define BtnPin 2

LED redLed(8);
LED yellowLed(9);
LED greenLed(10);
SwitchButton btn(2);

void setup() {
  Serial.begin(115200); 
  redLed.off();
  yellowLed.off();
  greenLed.off();
}

void loop() {
 unsigned int stateChangeCount = btn.getStateChangeCount();
    switch (stateChangeCount % 4) {
        case 0:
          redLed.off();
          yellowLed.off();
          greenLed.off();
          break;
        case 2:
          redLed.on();
          yellowLed.on();
          greenLed.on();
          break;
      }
    


  Serial.print("you click:");
  Serial.println(stateChangeCount/2);

}
