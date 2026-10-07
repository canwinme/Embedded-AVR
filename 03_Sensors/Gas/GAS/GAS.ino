const uint8_t GAS_PIN = A0;
const uint8_t LED_PIN1 = 8U;
const uint8_t LED_PIN2 = 9U;

void setup() {
  Serial.begin(115200UL);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(GAS_PIN, INPUT);
}

void loop() {
  const uint16_t gas_level = analogRead(GAS_PIN);

  if (gas_level > 300) {
    Serial.println("GAS!! GAS!!");
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    delay(1000UL);
  } else {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    delay(500UL);
  }
}
