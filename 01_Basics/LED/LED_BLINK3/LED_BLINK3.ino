void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200u);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED OFF");
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED ON");
  delay(1000);
}
