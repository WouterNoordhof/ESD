boolean autoLinksKnop() {
  if (digitalRead(CARLEFTPIN) == true) {
    return false;
  } else {
    return true;
  }
}

boolean voetgangerKnop() {
  if (digitalRead(PEDESTRIANPIN) == true) {
    return false;
  } else {
    return true;
  }
}

boolean autoRechtsKnop() {
  if (digitalRead(CARRIGHTPIN) == true) {
    return false;
  } else {
    return true;
  }
}

void veranderState() {
  checkVoorInput();
  if (autoLinks == true) {
    stateVeranderen = true;
    verkeersState = AUTOLINKSSTATE;
  }
  if (voetganger == true) {
    stateVeranderen = true;
    verkeersState = VOETGANGERSTATE;
  }
  if (autoRechts == true) {
    stateVeranderen = true;
    verkeersState = AUTORECHTSSTATE;
  }
  if (nachtmodusCheck() == true) {
    stateVeranderen = true;
    verkeersState = NACHTSTATE;
  }
  if (!autoLinks && !voetganger && !autoRechts && !nachtmodusCheck()) {
    stateVeranderen = false;
    verkeersState = VOETGANGERSTATE;
  }
}

void checkVoorInput() {
  checkAuto(LINKS);
  checkAuto(RECHTS);
  checkVoetganger();
}

