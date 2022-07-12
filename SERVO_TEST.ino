#include<Servo.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define WIFI_SSID "devanshi"
#define WIFI_PASSWORD "sahil123"
#define API_KEY "cn1x5S0lDCTkBJrzga1F7kB8PJxUpfBcSxGsbP1X"
#define DATABASE_URL "a-new-era-ded0c-default-rtdb.asia-southeast1.firebasedatabase.app"

FirebaseData SK;

Servo Myservo;
Servo Myservo2;
int pos=0;
bool gate;
void setup()
{

Serial.begin(115200);
  delay(2000);
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

  Firebase.begin(DATABASE_URL, API_KEY);

Myservo.attach(1); //Tx
Myservo2.attach(3);//Rx
}

void loop()
{
 Serial.println(gate);
 if(gate==1){
  
  
for(;pos<=180;pos++){
Myservo.write(pos);
Myservo2.write(pos);
delay(1);
}
 delay(100);
     
for(pos=180;pos>=0;pos--){
Myservo.write(pos);
Myservo2.write(pos);
delay(1);
}
}
 
 if(Firebase.ready()){
  Firebase.getBool(SK,"/Gate",&gate);
 }
}
