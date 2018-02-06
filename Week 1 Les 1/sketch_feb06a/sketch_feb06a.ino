int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  blink(2000, 100);
  blink(1000, 200);

}


void blink (int timer, int period) {
  int counter = 0;
  while (counter < timer) {
    digitalWrite(LED, HIGH);
    delay(period / 2);
    digitalWrite(LED, LOW);
    delay(period / 2);
    counter = counter + period;
  }
}
