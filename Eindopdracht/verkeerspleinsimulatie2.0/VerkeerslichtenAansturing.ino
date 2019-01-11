const int KNIPPERINTERVAL = 500;
boolean ledAan = false;

void setVerkeerslicht(int patroon[]) {
  digitalWrite(LEDSSTOREPIN, LOW);
  for (int i; i < 6; i++) {
    digitalWrite(LEDSSHIFTPIN, LOW);
    digitalWrite(LEDSDATAPIN, patroon[i]);
    digitalWrite(LEDSSHIFTPIN, HIGH);
  }
  digitalWrite(LEDSSTOREPIN, HIGH);
}

void knipperVerkeerslicht() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisKnipperen >= KNIPPERINTERVAL) {
    previousMillisKnipperen = currentMillis;
    if (ledAan) {
      setVerkeerslicht(beideOpOranje);
      ledAan = false;
    } else {
      setVerkeerslicht(beideUit);
      ledAan = true;
    }
  }
}

