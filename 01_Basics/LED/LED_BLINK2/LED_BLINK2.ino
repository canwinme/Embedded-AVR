const uint8_t LED_PIN1 = 13u;
const uint8_t LED_PIN2 = 8u;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  Serial.begin(115200u);
}

void loop() {
  digitalWrite(LED_PIN1, HIGH);
  Serial.println("LED1 ON");
  delay(250);

  digitalWrite(LED_PIN1, LOW);
  Serial.println("LED1 OFF");
  delay(250);

  digitalWrite(LED_PIN2, HIGH);
  Serial.println("LED2 ON");
  delay(250);

  digitalWrite(LED_PIN2, LOW);
  Serial.println("LED2 OFF");
  delay(250);
}
