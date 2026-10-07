const uint8_t LED_PIN1 = 13u;
const uint8_t LED_PIN2 = 12u;
const uint8_t SW_PULLUP = 7u;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(SW_PULLUP, INPUT_PULLUP);
  Serial.begin(115200ul);
}

void loop() {
  bool sw_pullup = digitalRead(SW_PULLUP);
  Serial.println(sw_pullup);
  delay(50);

  if (sw_pullup) {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
  } else {
    digitalWrite(LED_PIN1, HIGH);
    delay(10u);
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, HIGH);
    delay(10u);
    digitalWrite(LED_PIN2, LOW);
  }
}
