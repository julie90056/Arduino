#include <Servo.h>
#include <Ultrasonic.h>
Servo myservo;

int RedLight=5;
int GreenLight=7;
int buzzerPin=10;

Ultrasonic ultrasonic(12, 13);
byte distance;
int circle=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  if (digitalRead(RedLight) == LOW){
      Serial.print("輸入任一值為開始:\n");
  }
  // 設定SG90
  myservo.attach(9);
  myservo.write(0);
  // 設定蜂鳴器
  pinMode(buzzerPin, OUTPUT);

}
  
    
void loop() {

  // put your main code here, to run repeatedly:
    
      int val=int (Serial.read());
      if (val>0){
        for (byte i=5;i<8;i++) {
        byte buzz= 400; 
        tone(buzzerPin, buzz, 500);
        digitalWrite(i,HIGH);
        delay(1400);
        digitalWrite(i,LOW);
        buzz+=200;
      }
      
        delay(500);
        unsigned long digits=digitalRead(GreenLight);
        if (digits==LOW){
            tone(buzzerPin, 1000, 1500);
            SG90action();
          }
        
  delay(1000);
      }
 }

void SG90action(){

    for(int i = 0; i <= 90; i+=1){
    myservo.write(i); 
    delay(20);
  }
  delay(5000);
  myservo.write(0);
}

 
