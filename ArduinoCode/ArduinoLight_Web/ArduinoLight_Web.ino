#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "light-web-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "tmYp0qOFElT0wfeRfwjMeDrV92TK27OwoImNzleX"
#define WIFI_SSID "Avi"
#define WIFI_PASSWORD "7071955977@"
#define LED D2

void setup() {
  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {

  int val = Firebase.getInt("LED");
  Serial.print("LED : ");
  Serial.print(val);
  if(val == 1){
  digitalWrite(LED, HIGH);  
  delay(1000);
  }
  if(val == 0) {
  digitalWrite(LED, LOW);    
  delay(1000); 
  }
//  
//  // set value
//  Firebase.setFloat("number", 42.0);
//  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /number failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);
//
//  // get value 
//  Serial.print("number: ");
//  Serial.println(Firebase.getFloat("number"));
//  delay(1000);
//  
//  // set bool value
//  Firebase.setBool("truth", false);
//  // handle error
//  if (Firebase.failed()) {
//      Serial.print("setting /truth failed:");
//      Serial.println(Firebase.error());  
//      return;
//  }
//  delay(1000);
}
