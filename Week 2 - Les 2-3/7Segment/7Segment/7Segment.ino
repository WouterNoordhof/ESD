// Arduino-Pin verbunden mit SH_CP des 74HC595
int shiftPin = 9; // CLOCK DISPLAY -> 12, LEDS -> 11
// Arduino-Pin verbunden mit ST_CP des 74HC595
int storePin = 10; //STOREPIN -> 9
// Arduino-Pin verbunden mit DS des 74HC595
int dataPin = 11; // DATAPIN -> 10
 
// Dieses Muster soll ausgegeben werden
int zero[8] = {1, 1, 1, 0, 1, 1, 1, 1};
int one[8] = {0, 0, 1, 0, 0, 0, 1, 0};
int two[8] = {0, 1, 1, 1, 1, 1, 0, 0};
int three[8] = {0, 1, 1, 1, 0, 1, 1, 0};
int four[8] = {1, 0, 1, 1, 0, 0, 1, 0};
int five[8] = {1, 1, 0, 1, 0, 1, 1, 0};
int six[8] = {1, 1, 0, 1, 1, 1, 1, 0};
int seven[8] = {0, 1, 1, 0, 0, 0, 1, 0};
int eight[8] = {1, 1, 1, 1, 1, 1, 1, 1};
int nine[8] = {1, 1, 1, 1, 0, 1, 1, 1};
int a[8] = {1, 1, 1, 1, 1, 0, 1, 0};
int b[8] = {1, 0, 0, 1, 1, 1, 1, 0};
int c[8] = {1, 1, 0, 0, 1, 1, 0, 0};
int d[8] = {0, 0, 1, 1, 1, 1, 1, 0};
int e[8] = {1, 1, 0, 1, 1, 1, 0, 0};
int f[8] = {1, 1, 0, 1, 1, 0, 0, 0};
void setup() {
 
 // Pins 8,9,10 auf Ausgabe
 pinMode(storePin, OUTPUT);
 pinMode(shiftPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
 
 // storePin sicherheitshalber auf LOW
 digitalWrite(storePin, LOW); 
 
 for (int i=0; i<8; i++) {
 // first all 3 pins at LOW
 // things happen from the transition from LOW to HIGH
 digitalWrite(shiftPin, LOW);
 // Jetzt den Wert der aktuellen Stelle ans Datenpin DS anlegen 
 digitalWrite(dataPin, six[i]);
 // Dann ShiftPin SHCP von LOW auf HIGH, damit wird der Wert
 // am Datenpin ins Register geschoben. 
 digitalWrite(shiftPin, HIGH);
 }
 
 // Wenn alle 8 Stellen im Register sind, jetzt das StorePin STCP
 // von LOW auf HIGH, damit wird Registerinhalt an Ausgabepins
 // kopiert und der Zustand an den LEDs sichtbar
 
 digitalWrite(storePin, HIGH);
}
 
void loop () {
 // Nothing happens here
}

