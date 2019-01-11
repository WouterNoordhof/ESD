const int AUTOINTERVAL = 20000;
const int AUTORECHTSINTERVAL = 250;
const int AUTOLINKSINTERVAL = 250;
const int ORANJEINTERVAL = 250;
boolean aan = false;

void checkAuto(int richting) {
  unsigned long currentMillis = millis();
  if (richting == LINKS) {
    if (autoLinks == false && autoLinksKnop() != autoLinks) {
      autoLinks = true;
    }
    if (currentMillis - previousMillisAutoLinks >= AUTOINTERVAL && verkeersState == AUTOLINKSSTATE) {
      autoLinks = false;
      previousMillisAutoLinks = currentMillis;
    }
  } else if (richting == RECHTS) {
    if (autoRechts == false && autoRechtsKnop() != autoRechts) {
      autoRechts = true;
    }
    if (currentMillis - previousMillisAutoRechts >= AUTOINTERVAL && verkeersState == AUTORECHTSSTATE) {
      autoRechts = false;
      previousMillisAutoRechts = currentMillis;
    }
  }
}

void autolinks_exit() {
  unsigned long currentMillis = millis();
  if (previousMillisOranjeLinks - currentMillis <= ORANJEINTERVAL) {
    previousMillisOranjeLinks = currentMillis;
    setVerkeerslicht(linksOranjeRechtsRood);
  } else {
    setVerkeerslicht(beideOpRood);
  }
}

void autorechts_exit() {
  unsigned long currentMillis = millis();
  if (previousMillisOranjeRechts - currentMillis >= AUTORECHTSINTERVAL) {
    previousMillisOranjeRechts = currentMillis;
    setVerkeerslicht(rechtsOranjeLinksRood);
  } else {
    setVerkeerslicht(beideOpRood);
  }
}

