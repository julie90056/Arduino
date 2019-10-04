void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}
  
    
void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("輸入1為開始:");
  start(pressNum);
  Serial.print("是否繼續? (y/n)");
  char enterChar= Serial.read();
  if (enterChar=='y'){
    start(pressNum);
  }
  
 }
 //定義function
void start(unsigned long pressNum){
  int start=pressNum;
  boolean pressNum = Serial.read();
    if (pressNum){
      for (byte i=5;i<8;i++) {
      digitalWrite(i,HIGH);
      delay(500);
      digitalWrite(i,LOW);
    }
    }else{
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
    }
}

 
