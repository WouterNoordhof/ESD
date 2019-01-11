const int LEDPIN = 13;

void light_setup() {
  pinMode(LEDPIN, OUTPUT);
}

void LIGHT_ON() {
  digitalWrite(LEDPIN, HIGH);
}


void LIGHT_OFF() {
  digitalWrite(LEDPIN, LOW);
}
