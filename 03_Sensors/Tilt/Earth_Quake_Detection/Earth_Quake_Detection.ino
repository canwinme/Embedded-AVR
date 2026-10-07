const uint8_t LED_BUILTIN1 = 8U;
const uint8_t LED_BUILTIN2 = 9U;
const uint8_t TILT_SW_PIN = 10U;

int count = 0;
bool tilt_sw_state = false;

void setup() {
  Serial.begin(115200UL);
  pinMode(TILT_SW_PIN, INPUT);
  pinMode(LED_BUILTIN1, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
}

void loop() {
  bool earth_quake = digitalRead(TILT_SW_PIN);
  tilt_sw_state = earth_quake ^ true;

  if (tilt_sw_state == true) {
    if (count % 5 == 0) {
      Serial.println("Earth quake!!");
      digitalWrite(LED_BUILTIN1, HIGH);
      digitalWrite(LED_BUILTIN2, HIGH);
      count = 0;
      delay(1000UL);
    } else {
      ++count;
    }
  }

  digitalWrite(LED_BUILTIN1, LOW);
  digitalWrite(LED_BUILTIN2, LOW);
  delay(100);
}
