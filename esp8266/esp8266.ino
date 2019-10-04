#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

FirebaseData firebaseData;
void setup()
{
  //連線WIFI
  Serial.begin(115200);
  Serial.println();
  WiFi.begin("tel0421", "0936694067");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  //連線firebase, 到database "資料"查詢firebase id, 到設定/ 專案查詢/ 服務帳戶查詢憑證
  Firebase.begin("iotjuliehuang.firebaseio.com", "nfSkUcnjZ9bDpTib5Oa7KJPLTiNXYrWBn7nBtATz");
  //Firebase.reconnectWiFi(true);
  //Firebase.setMaxRetry(firebaseData, 3);
  //Firebase.setMaxErrorQueue(firebaseData, 30);
}
void letRead(){
    if (Firebase.getString(firebaseData, "hello")) {
    if (firebaseData.dataType() == "string") {
      Serial.println(firebaseData.stringData());
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }
}
void loop() {
//  if (Firebase.getBool(firebaseData, "/iot_0624/LED")) {
//    if (firebaseData.dataType() == "boolean") {
//      Serial.println(firebaseData.boolData());
//    }
//
//  } else {
//    Serial.println(firebaseData.errorReason());
//  }
  letRead();
  delay(500);
}
