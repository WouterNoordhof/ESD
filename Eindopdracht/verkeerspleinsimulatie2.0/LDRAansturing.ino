const int NACHTAFTELLENINTERVAL = 7000;

boolean nachtmodusCheck() {
  if (analogRead(LDRPIN) <= 450) {
    return true;
  } else {
    return false;
  }
  return false;
}

void nachtstandSlagboomOmlaag_exit() {
  verkeersState = VOETGANGERSTATE;
}

void nachtstandSlagboomOmhoog_exit() {
  verkeersState = NACHTSTATE;
}

void nacht_exit() {
  setDisplay(stoppen);
  setVerkeerslicht(beideOpOranje);
  langzaamTikken();
}

