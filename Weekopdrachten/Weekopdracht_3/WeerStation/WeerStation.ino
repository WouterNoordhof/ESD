int ldrValue = 0;
const int LDRPIN = A0;

void setup() {
  pinMode(LDRPIN, INPUT);
  Serial.begin(9600);
  initTemp();
}

void loop() {
  ldrValue = analogRead(LDRPIN);
  int ldrValue2 = mapjes(ldrValue, 0, 1023, 0, 255);
  Serial.print("Lichtwaarde = ");
  Serial.println(ldrValue2);
  float temp = printTemperature();
  Serial.print("Temperatuur = ");
  Serial.println(temp);
  delay(1000);
  
  
}
