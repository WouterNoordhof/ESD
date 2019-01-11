boolean nachtmodusCheck() {
  if(analogRead(LDRPIN) <= 450) {
    return true;
  } else {
    return false;
  }
}

void nacht_exit() {
  setDisplay(stoppen);
  setVerkeerslicht(beideOpOranje);
  tikLangzaam();
  
  slagboomOmlaag();
}

