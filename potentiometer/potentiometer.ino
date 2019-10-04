#define RedPin 6
#define potPin A0

unsigned long noteTime= millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RedPin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  function();
}

void function(){
  unsigned long currentTime = millis();
  if((currentTime - noteTime) >= 100){
    noteTime = currentTime;

    int potValue = analogRead(potPin);
    int valueOf8bit = (float)potValue / 1023 * 255; 
    Serial.println(valueOf8bit);
    analogWrite(RedPin, valueOf8bit);
  }
 
}
