#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "light-web-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "tmYp0qOFElT0wfeRfwjMeDrV92TK27OwoImNzleX"
#define WIFI_SSID "Avi"
#define WIFI_PASSWORD "7071955977@"

FirebaseData fbdo;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  fbdo.setBSSLBufferSize(1024, 1024);
  fbdo.setResponseSize(1024);

  Serial.println("Set Timestamp test...");
}

void loop()
{
  //Also can use Firebase.set instead of Firebase.setDouble
  Firebase.setDouble(fbdo,"currentWeather/humidity", 100);
  Firebase.setInt(fbdo,"currentWeather/temperature", 23);
  Firebase.setFloat(fbdo,"currentWeather/fahrenheit", 2323);
  Firebase.setTimestamp(fbdo,"currentWeather/date");
//  Serial.println(Firebase.getInt(fbdo,"currentWeather/fahrenheit"));
  String getData = Firebase.getString(fbdo,"LEDStat/Stat");
   Serial.println(getData);
  delay(1000);

}
