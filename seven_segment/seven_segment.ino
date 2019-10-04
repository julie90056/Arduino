#include "SwitchButton.h"
#define BtnPin 13

// define the LED digit patters, from 0 - 9
// 1 = LED on, 0 = LED off, in this order:
//                    Arduino pin: 2,3,4,5,6,7,8 (Mapping a,b,c,d,e,f,g of Seven-Segment LED)
byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // = 0
  { 0, 1, 1, 0, 0, 0, 0 }, // = 1
  { 1, 1, 0, 1, 1, 0, 1 }, // = 2
  { 1, 1, 1, 1, 0, 0, 1 }, // = 3
  { 0, 1, 1, 0, 0, 1, 1 }, // = 4
  { 1, 0, 1, 1, 0, 1, 1 }, // = 5
  { 1, 0, 1, 1, 1, 1, 1 }, // = 6
  { 1, 1, 1, 0, 0, 0, 0 }, // = 7
  { 1, 1, 1, 1, 1, 1, 1 }, // = 8
  { 1, 1, 1, 0, 0, 1, 1 } // = 9
};
// 設定pin腳
byte mapArdiuinoPin[] = {2, 3, 4, 5, 6, 7, 8};
//計數
SwitchButton button(13);


void setup() {
  Serial.begin(115200);
  for (byte i = 0; i < 7; i++) {
    pinMode(mapArdiuinoPin[i], OUTPUT);
  }
}

// 在七段顯示器上顯示指定的一個數字

void loop() {
  unsigned long clickcount = button.getStateChangeCount();
  Serial.print("you click:");
  Serial.println(clickcount);
  unsigned long pressNum = (clickcount % 20) / 2; //有十段, click兩次算一次
  displayDigit(pressNum);//function
}

//定義function
void displayDigit(unsigned long pressNum) {
  int displayIndex = pressNum;
  //取二微陣列的方式
  for (int i = 0; i < 7 ; i++) {
    bool onePinState = digits[displayIndex][i];
    byte pinNum = mapArdiuinoPin[i];
    digitalWrite(pinNum, onePinState);
  }
}
