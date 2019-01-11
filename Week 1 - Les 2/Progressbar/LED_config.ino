int ledPins[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
int maxLeds = 12;
void ledControlSetup (int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

//H: Heen
void ledControlForth(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

//S: Samenvoegen waarbij de ledjes tussendoor uit gaan
void ledControlMerge1(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[nrOfLeds - 1 - i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[nrOfLeds - 1 - i], LOW);
  }
}

//S: Samenvoegen waarbij de ledjes tussendoor niet uit gaan
void ledControlMerge2(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[nrOfLeds - 1 - i], HIGH);
    delay(100);
  }
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(100);
}

//R: Gesloten strook naar rechts
void ledControlLeftToRight(int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(100);
}

//L: Gesloten strook naar links
void ledControlRightToLeft(int nrOfLeds) {
  for (int i = nrOfLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(100);
}

//E: Stoppen
void ledControlAllLedsOff (int nrOfLeds) {
  for (int i = 0; i < nrOfLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}



