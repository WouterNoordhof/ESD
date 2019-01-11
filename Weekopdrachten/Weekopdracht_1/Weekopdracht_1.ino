int nrOfLedPins = 8;
void setup () {
  ledControlSetup(12); //max is 12
}

void loop() {
  ledControlMerge1(nrOfLedPins);
  ledControlMerge2(nrOfLedPins);
  ledControlForth(nrOfLedPins);
  ledControlLeftToRight(nrOfLedPins);
  ledControlRightToLeft(nrOfLedPins);
  ledControlAllLedsOff(nrOfLedPins);
  delay(1000);
}

