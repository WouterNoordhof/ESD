int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
int maxLeds = 12;
void ledControlSetup (int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void ledControlSetLedOn(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void ledControlSetLedOff(int nrOfLeds) {
  for (int i = nrOfLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

void ledControlAllLedsOn (int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(100);
}

void ledControlSetLedOnTwo(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
    digitalWrite(ledPins[i], HIGH);
  }
}

void ledControlSetLedOffTwo(int nrOfLeds) {
  for (int i = nrOfLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
    digitalWrite(ledPins[i], HIGH);
  }
}

void ledControlAllLedsOff (int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(100);
}
