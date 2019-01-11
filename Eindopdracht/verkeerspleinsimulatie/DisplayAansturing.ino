const int AFTELLENINTERVAL = 1000;
int aftellenIndex = 0;
const int AFTELLENARRAYSIZE = 7;

int displayAftellen[7][7] = {
  {1, 1, 1, 1, 1, 0, 1}, //Zes
  {1, 1, 0, 1, 1, 0, 1}, //Vijf
  {1, 1, 0, 0, 1, 1, 0}, //Vier
  {1, 0, 0, 1, 1, 1, 1}, //Drie
  {1, 0, 1, 1, 0, 1, 1}, //Twee
  {0, 0, 0, 0, 1, 1, 0}, //Een
  {0, 1, 1, 1, 1, 1, 1}  //Nul
};

void setDisplay(int patroon[]) {
  digitalWrite(DISPLAYSTOREPIN, LOW);
  for (int i = 0; i < 7; i++) {
    digitalWrite(DISPLAYSHIFTPIN, LOW);
    digitalWrite(DISPLAYDATAPIN, patroon[i]);
    digitalWrite(DISPLAYSHIFTPIN, HIGH);
  }
  digitalWrite(DISPLAYSTOREPIN, HIGH);
}

void setDisplayAftellen() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisAftellen >= AFTELLENINTERVAL) {
    previousMillisAftellen = currentMillis;
    setDisplay(displayAftellen[aftellenIndex]);
    aftellenIndex++;
    if(aftellenIndex > AFTELLENARRAYSIZE - 1) {
      aftellenIndex = 0;
    }
  }
}

void resetAftellenIndex() {
  aftellenIndex = 0;
}



