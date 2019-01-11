#include <Servo.h>;
Servo servo;

//De pinconfiguratie
const int DISPLAYSHIFTPIN = 12;
const int LEDSSHIFTPIN = 11;
const int LEDSDATAPIN = 10;
const int LEDSSTOREPIN = 9;
const int DISPLAYDATAPIN = 4;
const int DISPLAYSTOREPIN = 2;
const int BUZZERPIN = 8;
const int CARLEFTPIN = 7;
const int PEDESTRIANPIN = 6;
const int CARRIGHTPIN = 5;
const int SERVOPIN = 3;
const int LDRPIN = A0;

const int PINARRAY[] = {DISPLAYSHIFTPIN, LEDSSHIFTPIN, DISPLAYDATAPIN, DISPLAYSTOREPIN, LEDSDATAPIN, LEDSSTOREPIN, BUZZERPIN, SERVOPIN};
const int PINARRAYSIZE = 8;

//constante variabelen
const int RECHTS = 7;
const int LINKS = 6;
const int DODETIJD = 2000;

//state triggers
boolean autoLinks = false;
boolean voetganger = false;
boolean autoRechts = false;
boolean nachtmodus = false;

//states
boolean slagboomOpen = true;

boolean stateVeranderen = false;
int verkeersState;

const int AUTOLINKSSTATE = 0;
const int VOETGANGERSTATE = 1;
const int AUTORECHTSSTATE = 2;
const int NACHTSTATE = 3;
const int SLAGBOOMOMHOOG = 4;
const int SLAGBOOMOMLAAG = 5;

//timer variabelen
unsigned long previousMillisMain;
unsigned long previousMillisVoetganger;
unsigned long previousMillisVoetganger_Exit;
unsigned long previousMillisAutoLinks;
unsigned long previousMillisAutoLinksExit;
unsigned long previousMillisAutoRechts;
unsigned long previousMillisAutoRechtsExit;
unsigned long previousMillisSlagboom;
unsigned long previousMillisBuzzer;
unsigned long previousMillisVerkeerslicht;
unsigned long previousMillisAftellen;
unsigned long previousMillisKnipperen;
unsigned long previousMillisOranjeRechts;
unsigned long previousMillisOranjeLinks;

//Display Patronen
int lopen[] = {0, 1, 1, 1, 0, 0, 0};
int stoppen[] = {1, 1, 1, 0, 1, 1, 0};
int pasOp[] = {1, 1, 1, 0, 0, 1, 1};
int alleAan[] = {1, 1, 1, 1, 1, 1, 1, 1};


//Verkeerslicht Patronen  {GR, YR, RR, GL, YL, RL}
int beideOpRood[] = {0, 0, 1, 0, 0, 1};
int beideOpOranje[] = {0, 1, 0, 0, 1, 0};
int beideUit[] = {0, 0, 0, 0, 0, 0};
int linksOpRood[] = {0, 0, 0, 0, 0, 1};
int linksOranjeRechtsRood[] = {0, 0, 1, 0, 1, 0};
int linksOpGroen[] = {0, 0, 0, 1, 0, 0};
int rechtsRoodLinksGroen[] = {0, 0, 1, 1, 0, 0};
int rechtsOranjeLinksRood[] = {0, 1, 0, 0, 0, 1};
int rechtsGroenLinksRood[] = {1, 0, 0, 0, 0, 1};
int allesAan[] = {1, 1, 1, 1, 1, 1};

void setup() {
  servo.attach(SERVOPIN);
  for (int i = 0; i < PINARRAYSIZE; i++) {
    pinMode(PINARRAY[i], OUTPUT);
  }
  setVerkeerslicht(beideOpRood);
  setDisplay(lopen);
  setupTimers();
  setupSlagboom();
  // testthings
  Serial.begin(9600);
}

void loop() {
  knipperVerkeerslicht();
  unsigned long currentMillis = millis();
  /*
  switch (verkeersState) {
    case VOETGANGERSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        slagboomOmhoog();
        checkVoorInput();
        setVerkeerslicht(beideOpRood);
        setDisplay(lopen);
        tikSnel();
        veranderState();
      }
      if (verkeersState != VOETGANGERSTATE && verkeersState != NACHTSTATE) {
        previousMillisVoetganger_Exit = millis();
        voetganger_exit();
        previousMillisMain = millis();
      }
      break;

    case AUTOLINKSSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        setVerkeerslicht(rechtsRoodLinksGroen);
        checkVoorInput();
        tikLangzaam();
        veranderState();
      }
      if (verkeersState != AUTOLINKSSTATE) {
        autolinks_exit();
        previousMillisMain = millis();
      }
      break;

    case AUTORECHTSSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        setVerkeerslicht(rechtsOpGroen);
        checkVoorInput();
        tikLangzaam();
        veranderState();
      }
      if (verkeersState != AUTORECHTSSTATE) {
        autorechts_exit();
        previousMillisMain = millis();
      }
      break;

    case NACHTSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        setDisplay(stoppen);
        tikLangzaam();
        slagboomOmhoog();
        if (slagboomOpen == true) {
          setDisplay(pasOp);
          knipperVerkeerslicht();
          checkVoorInput();
          veranderState();
        }
      }
      if (verkeersState != NACHTSTATE) {
        nacht_exit();
        previousMillisMain = millis();
      }
      break;
  }
  */
}

void setupTimers() {
  previousMillisMain = millis();
  previousMillisVoetganger = millis();
  previousMillisVoetganger_Exit = millis();
  previousMillisAutoLinks = millis();
  previousMillisAutoLinksExit = millis();
  previousMillisAutoRechts = millis();
  previousMillisAutoRechtsExit = millis();
  previousMillisSlagboom = millis();
  previousMillisBuzzer = millis();
  previousMillisVerkeerslicht = millis();
  previousMillisAftellen = millis();
  previousMillisKnipperen = millis();
  previousMillisOranjeRechts = millis();
  previousMillisOranjeLinks = millis();

}

