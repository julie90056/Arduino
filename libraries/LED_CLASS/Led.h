#include <arduino.h>
class LED{
  private:
    byte _pinNum;
    
  public:
    LED(byte pin);

    //列出功能公式
     byte getPinNum();
     void on();//燈亮
     void off();//燈暗
};
