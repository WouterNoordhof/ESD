char drieKeer[] = "ttt ";
int tempoDrieKeer[] = { 1, 1, 1, 7};
int snelheidDrieKeer = 25;

char snel[] = "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt";
int tempoSnel[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int snelheidSnel = 25;


char langzaam[] = "t t t t t";
int tempoLangzaam[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
int snelheidLangzaam = 100;

int teller = 0;

void speelToon(int toon, int duratie) {
  for (long i = 0; i < duratie * 1000L; i += toon * 2) {
    digitalWrite(BUZZERPIN, HIGH);
    delayMicroseconds(toon);
    digitalWrite(BUZZERPIN, LOW);
    delayMicroseconds(toon);
  }
}

void speelNoot(char noot, int duratie) {
  char namen[] = {'t'};
  int tonen[] = { 4500};

  for (int i = 0; i < 8; i++) {
    if (namen[i] == noot) {
      speelToon(tonen[i], duratie);
    }
  }
}


void tikDrieKeer() {
  for (int i = 0; i < 15; i++) {
    if (drieKeer[i] == ' ') {
      delay(tempoDrieKeer[i] * snelheidDrieKeer);
    } else {
      speelNoot(drieKeer[i], tempoDrieKeer[i] * snelheidDrieKeer);
    }

    delay(snelheidDrieKeer / 2);
  }
}
void tikSnel() {
  for (int i = 0; i < 15; i++) {
    if (snel[i] == ' ') {
      delay(tempoSnel[i] * snelheidSnel); // rest
    } else {
      speelNoot(snel[i], tempoSnel[i] * snelheidSnel);
    }

    delay(snelheidSnel / 2);
  }
}

void tikLangzaam() {
  for (int i = 0; i < 15; i++) {
    if (langzaam[i] == ' ') {
      delay(tempoLangzaam[i] * snelheidLangzaam); // rest
    } else {
      speelNoot(langzaam[i], tempoLangzaam[i] * snelheidLangzaam);
    }

    delay(snelheidLangzaam / 2);
  }
}
