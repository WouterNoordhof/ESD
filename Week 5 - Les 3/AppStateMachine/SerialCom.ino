int const BAUD = 9600;

void serialInput_Setup() {
  Serial.begin(BAUD);
}

boolean serialInput_Received() {
  int value = Serial.read();

  if (value > -1) {
    return true;
  } else {
    return false;
   }
}

