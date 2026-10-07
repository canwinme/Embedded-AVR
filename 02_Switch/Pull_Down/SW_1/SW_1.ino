const uint8_t LED_PIN1 = 13u;
const uint8_t LED_PIN2 = 12u;
const uint8_t SW_PIN1 = 8u;
const uint8_t SW_PIN2 = 9u;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(SW_PIN1, INPUT);
  pinMode(SW_PIN2, INPUT);
  Serial.begin(115200ul);
}

void loop() {
  bool sw_state1 = digitalRead(SW_PIN1);

  if (sw_state1) {
    delay(10u);
    digitalWrite(LED_PIN1, HIGH);
    Serial.println("SWITCH ON");
  } else {
    delay(10u);
    digitalWrite(LED_PIN1, LOW);
    Serial.println("SWITCH OFF");
  }

  bool sw_state2 = digitalRead(SW_PIN2);

  if (sw_state2) {
    delay(10u);
    digitalWrite(LED_PIN2, HIGH);
    Serial.println("SWITCH ON");
  } else {
    delay(10u);
    digitalWrite(LED_PIN2, LOW);
    Serial.println("SWITCH OFF");
  }
}
