void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char switchChar = Serial.read();
    Serial.print("receive (0為關, 1為開):");
    Serial.println(switchChar);
    if(switchChar == '1'){
      digitalWrite(13,HIGH);
    }else{
      digitalWrite(13,LOW);
    }
  }
}
