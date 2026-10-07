const uint8_t MOTOR_N_PIN {6U};
const uint8_t MOTOR_P_PIN {7U};

void setup() {
  Serial.begin(115200ul);
  pinMode(MOTOR_N_PIN, OUTPUT);
  pinMode(MOTOR_P_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    const int input_number {Serial.parseInt()};
    Serial.println(String(input_number));

    if (input_number == 1) {
      digitalWrite(MOTOR_N_PIN, LOW);
      digitalWrite(MOTOR_P_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (input_number == 2) {
      digitalWrite(MOTOR_N_PIN, LOW);
      digitalWrite(MOTOR_P_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    } else if (input_number == 3) {
      digitalWrite(MOTOR_N_PIN, HIGH);
      digitalWrite(MOTOR_P_PIN, LOW);
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

  delay(100UL);
}
