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
  
  while (stateVeranderen == true) {
    Serial.println("YEAHHHH");
    checkVoorInput();
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisVoetganger_Exit < VOETGANGERSAFTELLENINTERVAL) {
      tikDrieKeer();
      setDisplayAftellen();
    } 
    
    if(currentMillis - previousMillisVoetganger_Exit >= VOETGANGERSAFTELLENINTERVAL) {
      slagboomOmlaag();
      setDisplay(stoppen);
    }
    if (slagboomOpen == false) {
      stateVeranderen = false;
    }
  }
  tikLangzaam();
  setDisplay(stoppen);
  
  previousMillisVoetganger = millis();
  previousMillisAutoLinks = millis();
  previousMillisAutoRechts = millis();
}

