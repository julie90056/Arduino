#define BtnPin 2
#define LedPin 6


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BtnPin, INPUT);
  pinMode(LedPin, OUTPUT);

}

void loop() {
  Serial.println(digitalRead(BtnPin));
  delay(10);
  if (digitalRead(BtnPin)==1){
    digitalWrite(6,HIGH);
  }else{
    digitalWrite(6,LOW);
  }
  
}
