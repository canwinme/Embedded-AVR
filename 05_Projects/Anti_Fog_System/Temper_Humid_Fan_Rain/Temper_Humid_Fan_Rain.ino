#include <Wire.h>
#include "SHT2x.h"

SHT2x sht2 = SHT2x();

const uint8_t RAIN_PIN = A8;
const uint8_t LED_PIN1 = 4;
const uint8_t LED_PIN2 = 5;
const uint8_t FAN_PIN = 6;

void setup() {
  Serial.begin(115200UL);
  Wire.begin();

  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  if (sht2.isConnected()) {
    Serial.println("SHT2X Sensor Connected");
    sht2.begin();
  }
}

void loop() {
  uint16_t rain_value = analogRead(RAIN_PIN);

  Serial.print(F("Water Value : "));
  Serial.println(rain_value);

  if (sht2.read()) {
    float temperature = sht2.getTemperature();
    float humidity = sht2.getHumidity();

    Serial.print(F("Temperature : "));
    Serial.print(temperature);
    Serial.println(F(" C"));

    Serial.print(F("Humidity : "));
    Serial.print(humidity);
    Serial.println(F(" %"));
    delay(500);

    if (humidity < 60.0) {
      digitalWrite(LED_PIN1, LOW);
      digitalWrite(LED_PIN2, LOW);
    } else if (humidity < 75.0) {
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, LOW);
    } else {
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, HIGH);
    }

    if (humidity >= 75.0 || rain_value > 680) {
      digitalWrite(FAN_PIN, HIGH);
      Serial.println(F("Condensation Warning"));
      Serial.println(F("FAN ON"));
    } else {
      digitalWrite(FAN_PIN, LOW);
      Serial.println(F("FAN OFF"));
    }
  }

  Serial.println("--------------------");
  delay(500);
}
