#include <Servo.h>
const int SERVOPIN = 3;
Servo servo;
int servoMin = 0;
int servoMax = 180;
int servoDelay = 10;
boolean start = false;


int potPin = A0;


void setup() {
  Serial.begin(9600);
  servo.attach(SERVOPIN);
  pinMode(potPin, INPUT);
}

void loop() {
  switch (Serial.read()) {
    case 'S':
      start = !start;
      break;
    case '-':
      servoMin = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
      break;
    case '+':
      servoMax = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
      break;
    case 'F':
      servoDelay = mapfunctie(analogRead(potPin), 0, 1023, 10, 100);
      break;
  }
  if (start) {
    for (int i = servoMin; i < servoMax; i++) {
      switch (Serial.read()) {
        case 'S':
          start = !start;
          break;
        case '-':
          servoMin = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
          break;
        case '+':
          servoMax = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
          break;
        case 'F':
          servoDelay = mapfunctie(analogRead(potPin), 0, 1023, 10, 100);
          break;
        case 'L':
          servo.write(180);
      }
      servo.write(i);
      delay(servoDelay);
    }
    for (int i = servoMax - 1; i >= servoMin; i--) {
      switch (Serial.read()) {
        case 'S':
          start = !start;
          break;
        case '-':
          servoMin = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
          break;
        case '+': 
          servoMax = mapfunctie(analogRead(potPin), 0, 1023, 0, 180);
          break;
        case 'F':
          servoDelay = mapfunctie(analogRead(potPin), 0, 1023, 10, 100);
          break;
      }
      servo.write(i);
      delay(servoDelay);
    }
  }
}

int mapfunctie(long input, long minInput, long maxInput, long minOutput, long maxOutput) {

  int resultaat = (input - minInput) * (maxOutput - minInput) / (maxInput - minInput);
  return resultaat;
}
