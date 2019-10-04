#ifndef _SEVENSEGMENTED_
#define _SEVENSEGMENTED_

#include <arduino.h>

class SevenSegmented {

  private:
    byte _digits[10][7] = {
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
    byte* _mapArdiuinoPin;

    public:
    SevenSegmented(byte* pins);
    void displaySingleNumber(byte n);

};
#endif
