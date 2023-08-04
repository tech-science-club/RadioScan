#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <DHT.h>
#define DHT11_PIN 2
#define DHTTYPE DHT11

DHT dht(DHT11_PIN, DHTTYPE);

const char* ssid = "Kviknet-5A55";
const char* password = "7HBXLQWCTQ77NT";
const char* SERVER_NAME = "http://radioscan.atwebpages.com/sensordata.php";
String PROJECT_API_KEY = "12345";

unsigned long previousMillis;
unsigned long previousMillis_2;
unsigned long counts;
unsigned long events;

#define LOG_PERIOD 30000
#define LOG_PERIOD_2 1000

//String temperature;
//String coordinates;

void ICACHE_RAM_ATTR impulse() {
  counts++;
  events++;
}

void setup() {
  
  Serial.begin(9600);
  volatile int counts;
  pinMode(4, INPUT);
  attachInterrupt(digitalPinToInterrupt(4), impulse, FALLING);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {


  if (WiFi.status() == WL_CONNECTED) {

    //radiation_to_cloud();
    
    upload_data_to_serial_monitor();
    pass_data_to_cloud();
  }
 
}

//void radiation_to_cloud() {
//  unsigned long rad_currentMillis = millis();
//  if (rad_currentMillis - previousMillis > LOG_PERIOD) {
//    previousMillis = rad_currentMillis;
//    Serial.println("counts: "+ counts);
//    counts = 0;
//  }
//}

void upload_data_to_serial_monitor() {
  
  float t = dht.readTemperature();
  float hic = dht.computeHeatIndex(t, false);

  String temperature = String(t, 2);
  String coordinates = String(random(-50, 50));
  String Radiation = String(events);

  unsigned long rad_currentMillis_2 = millis();
  if (rad_currentMillis_2 - previousMillis_2 > LOG_PERIOD_2) {
    previousMillis_2 = rad_currentMillis_2;
    Serial.print("Temperature: " + temperature + " ");
    Serial.print("Radiation: " + Radiation + " ");
    Serial.println("coordinates: " + coordinates);
    events = 0;
  }
  delay(1000);


}

void pass_data_to_cloud() {
  unsigned long rad_currentMillis = millis();
  if (rad_currentMillis - previousMillis > LOG_PERIOD) {
    previousMillis = rad_currentMillis;
     
    float t = dht.readTemperature();
    float hic = dht.computeHeatIndex(t, false);

    String temperature = String(t, 2);
    String coordinates = String(random(-50, 50));
    String radiation = String(counts);

    String temperature_data = "api_key=" + PROJECT_API_KEY;
    temperature_data += "&temperature=" + temperature;
    temperature_data += "&radiation=" + radiation; // Use the global counts variable
    temperature_data += "&coordinates=" + coordinates;

    WiFiClient client;
    HTTPClient http;

    http.begin(client, SERVER_NAME);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(temperature_data);

    http.end();
    counts = 0;
  }
}
