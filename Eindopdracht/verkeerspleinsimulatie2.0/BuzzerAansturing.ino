const int SNELINTERVAL = 100;
const int LANGZAAMINTERVAL = 500;
const int DRIEKEERINTERVAL = 100;
const int RUSTINTERVAL = 300;
boolean tikkendLangzaam = false;
boolean tikkendSnel = false;
boolean tikkendDrieKeer = false;
int tiks = 0;

void drieKeerTikken() {
  unsigned long currentMillis = millis();

  if (tiks <= 3) {
    if (currentMillis - previousMillisDrieKeer >= DRIEKEERINTERVAL) {
      previousMillisDrieKeer = currentMillis;
      if (tikkendDrieKeer) {
        tiks++;
        tone(BUZZERPIN, 1000);
        tikkendDrieKeer = false;
      } else {
        noTone(BUZZERPIN);
        tikkendDrieKeer = true;
      }
    }
  } else {
    noTone(BUZZERPIN);
    if (currentMillis - previousMillisDrieKeer >= RUSTINTERVAL) {
      tiks = 0;
    }
  }
}

void langzaamTikken() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisLangzaam >= LANGZAAMINTERVAL) {
    previousMillisLangzaam = currentMillis;
    if (tikkendLangzaam) {
      tone(BUZZERPIN, 1000);
      tikkendLangzaam = false;
    } else {
      noTone(BUZZERPIN);
      tikkendLangzaam = true;
    }
  }
}

void snelTikken() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisSnel >= SNELINTERVAL) {
    previousMillisSnel = currentMillis;
    if (tikkendSnel) {
      tone(BUZZERPIN, 1000);
      tikkendSnel = false;
    } else {
      noTone(BUZZERPIN);
      tikkendSnel = true;
    }
  }
}









