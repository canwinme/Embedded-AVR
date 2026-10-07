const uint8_t CDS_PIN = A0;
const uint8_t LED_PIN1 = 8;
const uint8_t LED_PIN2 = 9;

void setup() {
  Serial.begin(115200ul);
  pinMode(CDS_PIN, INPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  uint16_t cds_value = analogRead(CDS_PIN);

  Serial.println(F("light value = "));
  Serial.println(cds_value);
  delay(500);

  if (cds_value < 100) {
    digitalWrite(LED_PIN1, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    Serial.println("LED ON");
  } else {
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
    Serial.println("LED OFF");
  }

  delay(250);
}
