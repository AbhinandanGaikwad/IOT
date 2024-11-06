#include <DHT.h>
#define LED 13
#define DHTPIN A4
#define DHTTYPE DHT22

DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(2000);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if(temperature > 26.0) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
