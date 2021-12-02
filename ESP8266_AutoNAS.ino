#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* WIFI_SSID = "YOUR WIFI SSID";
const char* WIFI_PASS = "YOUS WIFI PASSWORD";
const char* NIM = "arsana";
const char* PASS = "ambon123";

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.println("Connecting...");
  }
  HTTPClient http;
  http.begin("http://nas.ub.ac.id/ac_portal/login.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  String kirim = "opr=pwdLogin&userName=";
  kirim += NIM;
  kirim += "&pwd=";
  kirim += PASS;
  kirim += "&rememberPwd=1";
  int httpCode = http.POST(kirim);
  if(httpCode > 0){
    Serial.println(http.getString());   
  }
}

void loop() {

}
