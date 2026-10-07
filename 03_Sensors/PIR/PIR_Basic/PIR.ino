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
  bool sw_state1 = digitalRead(SW_PIN1);
  bool sw_state2 = digitalRead(SW_PIN2);
  bool pir_state = digitalRead(PIR_PIN);

  if (sw_state1) {
    sw1_state = true;
    sw2_state = false;
  }

  if (sw_state2) {
    sw1_state = false;
    sw2_state = true;
  }

  if (sw1_state) {
    pir_state = pir_state ^ false;

    if (pir_state) {
      Serial.print(F("Somebody comes in my room\n"));
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, HIGH);
      delay(500);
    } else {
      digitalWrite(LED_PIN1, LOW);
      digitalWrite(LED_PIN2, LOW);
      delay(500);
    }
  }

  if (sw2_state) {
  }
}
