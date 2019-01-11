int ldrValue = 0;
const int LDRPIN = A0;

void setup() {  
  pinMode(LDRPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(LDRPIN);
  Serial.println(ldrValue);
  delay(1000);

}

