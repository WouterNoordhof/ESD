const int SERVOMIN = 0;
const int SERVOMAX = 90;
const int BEWEEGTIJD = 3000;
const int SERVOSPEED = (int)((BEWEEGTIJD) / (SERVOMAX - SERVOMIN));

int slagboomOmhoogIndex = SERVOMIN;
int slagboomOmlaagIndex = SERVOMAX;

void setupSlagboom() {
  servo.write(SERVOMAX);
}

void slagboomOmhoog() {
  unsigned long currentMillis = millis();
  if (!slagboomOpen) {
    if (currentMillis - previousMillisSlagboom >= SERVOSPEED) {
      servo.write(slagboomOmhoogIndex);
      previousMillisSlagboom = currentMillis;
      slagboomOmhoogIndex++;
      if (slagboomOmhoogIndex > SERVOMAX) {
        slagboomOmhoogIndex = SERVOMIN;
        slagboomOpen = true;
      }
    }
  }
}

void slagboomOmlaag() {
  unsigned long currentMillis = millis();
  if (slagboomOpen) {
    if (currentMillis - previousMillisSlagboom >= SERVOSPEED) {
      servo.write(slagboomOmlaagIndex);
      previousMillisSlagboom = currentMillis;
      slagboomOmlaagIndex--;
      if (slagboomOmlaagIndex < SERVOMIN) {
        slagboomOmlaagIndex = SERVOMAX;
        slagboomOpen = false;
      }
    }
  }
}

boolean isSlagboomOpen() {
  return slagboomOpen;
}

