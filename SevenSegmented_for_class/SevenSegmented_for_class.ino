#include "SevenSegmented_for_class.h"

byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};
SevenSegmented sl_01(mapArdiuinoPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 9; i >= 0; i--) {
    sl_01.displaySingleNumber(i);
    delay(500);
}
}
