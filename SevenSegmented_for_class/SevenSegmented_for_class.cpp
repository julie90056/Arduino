#include "SevenSegmented_for_class.h"

// ::表示是class SevenSegmented的功能變數
SevenSegmented::SevenSegmented(byte* pins){
  _mapArdiuinoPin = pins;
  for (byte i = 0; i < 7; i++) {
    pinMode(_mapArdiuinoPin[i], OUTPUT);
  }
}
//顯示數字
void SevenSegmented::displaySingleNumber(byte n){
    for(int i=0; i<7 ; i++){
    bool onePinState = _digits[n][i];
    byte pinNum = _mapArdiuinoPin[i];
    digitalWrite(pinNum, onePinState);
  }
 }
