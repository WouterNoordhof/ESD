const int AUTOINTERVAL = 5000;
const int AUTORECHTSINTERVAL = 250;
const int AUTOLINKSINTERVAL = 250;
const int ORANJEINTERVAL = 1000;
boolean aan = false;

void checkAuto(int richting) {
  unsigned long currentMillis = millis();
  if (richting == LINKS) {
    if (autoLinks == false && autoLinksKnop() != autoLinks) {
      autoLinks = true;
    }
    if (currentMillis - previousMillisAutoLinks >= AUTOINTERVAL && verkeersState == AUTOLINKSSTATE) {
      previousMillisAutoLinks = currentMillis;
      autoLinks = false;
    }
  } else if (richting == RECHTS) {
    if (autoRechts == false && autoRechtsKnop() != autoRechts) {
      autoRechts = true;
    }
    if (currentMillis - previousMillisAutoRechts >= AUTOINTERVAL && verkeersState == AUTORECHTSSTATE) {
      previousMillisAutoRechts = currentMillis;
      autoRechts = false;
    }
  }
}

void autolinks_exit() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisOranjeLinks <= ORANJEINTERVAL) {
    previousMillisOranjeLinks = currentMillis;
    setVerkeerslicht(linksOranjeRechtsRood);
  } else {
    setVerkeerslicht(beideOpRood);
  }
}

void autorechts_exit() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisOranjeRechts <= ORANJEINTERVAL) {
    previousMillisOranjeRechts = currentMillis;
    setVerkeerslicht(rechtsOranjeLinksRood);
  } else {
    setVerkeerslicht(beideOpRood);
  }
}

