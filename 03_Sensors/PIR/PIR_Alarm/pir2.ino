const uint8_t PIR_PIN = 10u;
const uint8_t SW_PIN1 = 6u;
const uint8_t SW_PIN2 = 7u;
const uint8_t LED_PIN1 = 8u;
const uint8_t LED_PIN2 = 9u;

bool pir_state = false;
bool sw1_state = false;
bool sw2_state = false;

void setup() {
  Serial.begin(115200UL);
  pinMode(PIR_PIN, INPUT);
  pinMode(SW_PIN1, INPUT);
  pinMode(SW_PIN2, INPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  if (digitalRead(SW_PIN1)) {
    sw1_state = true;
    sw2_state = false;
  }

  if (digitalRead(SW_PIN2)) {
    sw1_state = false;
    sw2_state = true;
  }

  if (sw1_state) {
    bool pir_value = digitalRead(PIR_PIN);

    if (pir_value) {
      pir_state = pir_state ^ true;
      delay(200);

      if (pir_state) {
        Serial.print(F("Detected\n"));
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, HIGH);
        delay(500);
      }

      Serial.println("Alarm On");
    }

    delay(200);
  }

  if (sw2_state) {
    Serial.println(F("Alarm off"));
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    delay(100);
  }
}
