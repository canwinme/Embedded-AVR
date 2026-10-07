const uint8_t SOUND_PIN = A0;
const uint8_t LED_PIN1 = 8u;
const uint8_t LED_PIN2 = 9u;

bool microphone_state = false;

void setup() {
  Serial.begin(115200UL);
  pinMode(SOUND_PIN, INPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  int sound_level = analogRead(SOUND_PIN);

  if (sound_level > 400) {
    microphone_state = microphone_state ^ true;

    if (microphone_state) {
      Serial.println(String(sound_level) + " Whop! Turn on!");
      digitalWrite(LED_PIN1, HIGH);
      digitalWrite(LED_PIN2, HIGH);
    } else {
      Serial.println(String(sound_level) + " Whop! Turn off!");
      digitalWrite(LED_PIN1, LOW);
      digitalWrite(LED_PIN2, LOW);
    }
  }

  delay(50ul);
}
