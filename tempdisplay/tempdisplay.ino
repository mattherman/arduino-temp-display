#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11   // DHT 11
#define DHT_SENSOR_PIN 2

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  float temperature;
  float humidity;
  if (dht_sensor.measure(&temperature, &humidity)) {
    printTemperatureAsF(temperature);
    printHumidity(humidity);
  }
}

void printTemperatureAsF(float celsiusTemp) {
  float fahrTemp = celsiusToFahrenheit(celsiusTemp);
  String fahrTempString = String(fahrTemp);
  lcd.setCursor(0, 0);
  lcd.print("Temp:     " + fahrTempString + "F");
}

void printHumidity(float humidity) {
  String humidityString = String(humidity);
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + humidityString + "%");
}

float celsiusToFahrenheit(float celsius) {
  return ((celsius * 9) / 5) + 32;
}
