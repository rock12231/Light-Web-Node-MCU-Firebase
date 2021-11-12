#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "light-web-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "tmYp0qOFElT0wfeRfwjMeDrV92TK27OwoImNzleX"
#define WIFI_SSID "Avi"
#define WIFI_PASSWORD "7071955977@"
#define LED1 D2
#define LED2 D3
void setup() {
  
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
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

  int val1 = Firebase.getInt("LED1");
  int val2 = Firebase.getInt("LED2");
  Serial.print("LED1 : ");
  Serial.print(val1);
  Serial.print("LED2 : ");
  Serial.println(val2);
  
  if(val1 == 1){
  digitalWrite(LED1, HIGH);  
  }
  if(val1 == 0) {
  digitalWrite(LED1, LOW);    
  }
   if(val2 == 1){
  digitalWrite(LED2, HIGH);  
  }
  if(val2 == 0) {
  digitalWrite(LED2, LOW);     
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
