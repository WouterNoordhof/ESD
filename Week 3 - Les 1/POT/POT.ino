const int POTPIN = A0;
int potValue1 = 0;
int LED = 13;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POTPIN, INPUT);
  Serial.begin(9600);
}

void loop() {

  potValue1 = analogRead(POTPIN);
  int potValue2 = mapfunctie(potValue1, 0, 1023, 0, 180);
  Serial.println(potValue2);
  delay(1000);

}

int mapfunctie(long input, long minInput, long maxInput, long minOutput, long maxOutput) {

  int resultaat = (input - minInput) * (maxOutput - minInput) / (maxInput - minInput);
  return resultaat;
}

