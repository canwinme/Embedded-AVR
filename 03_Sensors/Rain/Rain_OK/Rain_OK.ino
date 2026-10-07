const uint8_t RAIN_PIN = A8;
const uint8_t MOTOR_PIN = 7u;
const uint8_t FAN_PIN = 7;

void setup() {
  Serial.begin(115200UL);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  uint16_t rain_value = analogRead(RAIN_PIN);

  Serial.print(F("Rain's value : "));
  Serial.println(rain_value);

  if (rain_value > 680) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  delay(100);
}
