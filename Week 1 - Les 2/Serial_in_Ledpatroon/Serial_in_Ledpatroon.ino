void setup () {
  ledControlSetup(12); //max is 12
}

void loop() {
  ledControlSetLedOn(12);
  ledControlSetLedOff(12);
  ledControlAllLedsOn(12);
  ledControlSetLedOnTwo(12);
  ledControlSetLedOffTwo(12);
  ledControlAllLedsOff(12);
}

