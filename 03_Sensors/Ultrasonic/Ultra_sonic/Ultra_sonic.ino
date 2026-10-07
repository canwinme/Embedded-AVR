#include "HCSR04.h"

const uint8_t TRIGGER_PIN = 4U;
const uint8_t ECHO_PIN = 5U;
const uint8_t LED_PIN1 = 8U;
const uint8_t LED_PIN2 = 9U;

class UltraSonicDistanceSensor ultrasonic = UltraSonicDistanceSensor(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200UL);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  float distance = ultrasonic.measureDistanceCm(27.5);

  Serial.println("Distance : " + String(distance) + " Cm.");
  delay(100);

  if (distance < 10) {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
  } else if (distance < 20) {
    digitalWrite(LED_PIN1, HIGH);
    delay(10u);
    digitalWrite(LED_PIN2, HIGH);
    digitalWrite(LED_PIN1, LOW);
    delay(10u);
    digitalWrite(LED_PIN2, LOW);
  } else {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
}
