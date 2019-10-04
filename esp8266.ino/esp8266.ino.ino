#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
/*
   Ultrasonic Simple
   Prints the distance read by an ultrasonic sensor in
   centimeters. They are supported to four pins ultrasound
   sensors (liek HC-SC04) and three pins (like PING)))
   and Seeed Studio sensors).

   The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
     three pins), attached to digital pins as follows:
   ---------------------    --------------------
   | HC-SC04 | Arduino |    | 3 pins | Arduino |
   ---------------------    --------------------
   |   Vcc   |   5V    |    |   Vcc  |   5V    |
   |   Trig  |  12/D3  | OR |   SIG  |   13    |
   |   Echo  |  13/D4  |    |   Gnd  |   GND   |
   |   Gnd   |   GND   |    --------------------
   ---------------------
   Note: You do not obligatorily need to use the pins defined above

   By default, the distance returned by the read()
   method is in centimeters. To get the distance in inches,
   pass INC as a parameter.
   Example: ultrasonic.read(INC)
*/
#include <Ultrasonic.h>
//使用firebaseData建立firebaseData
FirebaseData firebaseData;

//D8紅燈.D7綠燈.D5黃燈

//pinMode(D5, OUTPUT);

/*
   Pass as a parameter the trigger and echo pin, respectively,
   or only the signal pin (for sensors 3 pins), like:
   Ultrasonic ultrasonic(13/D4);
*/
Ultrasonic ultrasonic(D3, D4);
int distance;

void setup() {
  //連線WIFI
  Serial.begin(115200);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  Serial.println();
  WiFi.begin("tel0421", "0936694067");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  //連線firebase
  Firebase.begin("iotulea-c69b5.firebaseio.com", "ycTejU9UAnfSGLNX51eT3VYw1GutiBwBlS8NPasd");
  Firebase.reconnectWiFi(true);
  Firebase.setMaxRetry(firebaseData, 3);
  Firebase.setMaxErrorQueue(firebaseData, 30);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  Firebase.setInt(firebaseData, "/iot_lea/temperature", distance);
  if (distance <= 10) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
  } else {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
  }
  delay(100);
}
