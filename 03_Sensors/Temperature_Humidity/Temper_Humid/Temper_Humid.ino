#include "SHT2x.h"

class SHT2x sht2 = SHT2x();

const uint8_t SHT_PIN = A8;
const uint8_t FAN_PIN = 7;

void setup() {
  Serial.begin(115200UL);
  Wire.begin();
  pinMode(FAN_PIN, OUTPUT);

  if (sht2.isConnected()) {
    Serial.println("SHT2X Sensor Connected");
    sht2.begin();
  }
}

void loop() {
  if (sht2.read()) {
    float temperature = sht2.getTemperature();

    Serial.print(F("Temperature : "));
    Serial.println(String(temperature) + " C");

    float humidity = sht2.getHumidity();

    Serial.print(F("Humidity : "));
    Serial.println(String(humidity) + " %");

    if (static_cast<int>(temperature) > 22) {
      digitalWrite(FAN_PIN, HIGH);
    } else {
      digitalWrite(FAN_PIN, LOW);
    }
  }

  delay(500);
}
