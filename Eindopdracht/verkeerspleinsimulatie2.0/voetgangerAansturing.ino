const int VOETGANGERINTERVAL = 3000;
const int VOETGANGERSAFTELLENINTERVAL = 7000;

void checkVoetganger() {
  unsigned long currentMillis = millis();
  if (voetganger == false && voetgangerKnop() != voetganger) {
    voetganger = true;
  }
  if (currentMillis - previousMillisVoetganger >= VOETGANGERINTERVAL && verkeersState == VOETGANGERSTATE) {
    voetganger = false;
    previousMillisVoetganger = currentMillis;
  }
}

void voetganger_exit() {
  resetAftellenIndex();
  previousMillisVoetganger_Exit = millis();
  while (stateVeranderen == true) {
    checkVoorInput();
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisVoetganger_Exit <= VOETGANGERSAFTELLENINTERVAL) {
      drieKeerTikken();
      setDisplayAftellen();
    }

    if (currentMillis - previousMillisVoetganger_Exit >= VOETGANGERSAFTELLENINTERVAL) {
      slagboomOmlaag();
      setDisplay(stoppen);
    }
    if (slagboomOpen == false) {
      stateVeranderen = false;
    }
  }
  langzaamTikken();
  setDisplay(stoppen);

  previousMillisVoetganger = millis();
  previousMillisAutoLinks = millis();
  previousMillisAutoRechts = millis();
}

void voetgangerSlagboomOmlaag_exit() {
  
}

void voetgangerSlagboomOmhoog_exit() {
  
}

