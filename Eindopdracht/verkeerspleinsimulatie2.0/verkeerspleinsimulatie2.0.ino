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
const int NACHTSTANDSLAGBOOMOMHOOG = 4;
const int NACHTSTANDSLAGBOOMOMLAAG = 5;
const int VOETGANGERSLAGBOOMOMHOOG = 6;
const int VOETGANGERSLAGBOOMOMLAAG = 7;

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
unsigned long previousMillisSnel;
unsigned long previousMillisLangzaam;
unsigned long previousMillisDrieKeer;

//Display Patronen
int lopen[] = {0, 1, 1, 1, 0, 0, 0};
int stoppen[] = {1, 1, 1, 0, 1, 1, 0};
int pasOp[] = {1, 1, 1, 0, 0, 1, 1};
int alleAan[] = {1, 1, 1, 1, 1, 1, 1, 1};

//Verkeerslicht Patronen  {GR, YR, RR, GL, YL, RL}
int beideOpRood[] = {0, 0, 1, 0, 0, 1};
int beideOpOranje[] = {0, 1, 0, 0, 1, 0};
int beideUit[] = {0, 0, 0, 0, 0, 0};
int linksRoodRechtsGroen[] = {1, 0, 0, 0, 0, 1};
int linksRoodRechtsOranje[] = {0, 1, 0, 0, 0, 1};
int linksOranjeRechtsRood[] = {0, 0, 1, 0, 1, 0};
int linksGroenRechtsRood[] = {0, 0, 1, 1, 0, 0};
int rechtsRoodLinksGroen[] = {0, 0, 1, 1, 0, 0};
int rechtsOranjeLinksRood[] = {0, 1, 0, 0, 0, 1};
int rechtsGroenLinksRood[] = {1, 0, 0, 0, 0, 1};
int allesAan[] = {1, 1, 1, 1, 1, 1};

void setup() {
  servo.attach(SERVOPIN);
  for (int i = 0; i < PINARRAYSIZE; i++) {
    pinMode(PINARRAY[i], OUTPUT);
  }
  verkeersState = VOETGANGERSTATE;
  setVerkeerslicht(beideOpRood);
  setDisplay(lopen);
  setupTimers();
  setupSlagboom();
  // testthings
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  switch (verkeersState) {
    case VOETGANGERSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {

        if (slagboomOpen == true) {
          setVerkeerslicht(beideOpRood);
          setDisplay(lopen);
          checkVoorInput();
          veranderState();
          snelTikken();
        } else {
          slagboomOmhoog();
          langzaamTikken();
        }
      } else {
        langzaamTikken();
      }
      if (verkeersState == NACHTSTATE) {

      } else if (verkeersState != VOETGANGERSTATE) {
        voetganger_exit();
      }
      break;

    case AUTOLINKSSTATE:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        setDisplay(stoppen);
        langzaamTikken();
        setVerkeerslicht(linksGroenRechtsRood);
        if (currentMillis - previousMillisMain >= DODETIJD + 5000) {
          veranderState();
          previousMillisOranjeLinks = currentMillis;
        }
      }
      if (verkeersState != AUTOLINKSSTATE) {
        autolinks_exit();
      }
      break;

    case AUTORECHTSSTATE:
      setDisplay(stoppen);
      langzaamTikken();
      if (currentMillis - previousMillisMain >= DODETIJD) {
        setVerkeerslicht(rechtsGroenLinksRood);
        if (currentMillis - previousMillisMain >= DODETIJD + 5000) {
          veranderState();
          previousMillisOranjeRechts = currentMillis;
        }
      }
      if (verkeersState != AUTORECHTSSTATE) {
        autorechts_exit();
      }
      break;

    case NACHTSTATE:
      knipperVerkeerslicht();
      langzaamTikken();

      if (analogRead(LDRPIN) > 450) {
        verkeersState = NACHTSTANDSLAGBOOMOMLAAG;
      }
      if (verkeersState != NACHTSTATE) {
        nacht_exit();
      }
      break;

    case NACHTSTANDSLAGBOOMOMHOOG:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        if (slagboomOpen == false) {
          slagboomOmhoog();

        } else {
          nachtstandSlagboomOmhoog_exit();
        }
      }
      previousMillisMain = currentMillis;
      break;

    case NACHTSTANDSLAGBOOMOMLAAG:
      if (currentMillis - previousMillisMain >= DODETIJD) {
        if (slagboomOpen == true) {
          slagboomOmlaag();

        } else {
          nachtstandSlagboomOmlaag_exit();
        }
        previousMillisMain = currentMillis;
      }
      break;
  }
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
  previousMillisSnel = millis();
  previousMillisLangzaam = millis();
  previousMillisDrieKeer = millis();
}

