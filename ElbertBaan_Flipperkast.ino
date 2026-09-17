#include <Servo.h>

Servo motorLinks;      // servo voor linker flipper
Servo motorRechts;     // servo voor rechter flipper

int flipperlinks = 2;      // knop links
int flipperrechts = 3;     // knop rechts

void setup() {
  pinMode(flipperlinks, INPUT_PULLUP);
  pinMode(flipperrechts, INPUT_PULLUP);

  motorLinks.attach(9);     // servo links op pin 9
  motorRechts.attach(10);   // servo rechts op pin 10

  Serial.begin(9600);
}

void loop() {
  int statusLinks = digitalRead(flipperlinks);
  int statusRechts = digitalRead(flipperrechts);

  // Linker flipper
  if (statusLinks == LOW) {
    motorLinks.write(95);     // ingedrukt → omhoog
  } else {
    motorLinks.write(0);      // niet ingedrukt → omlaag
  }

  // Rechter flipper
  if (statusRechts == LOW) {
    motorRechts.write(95);
  } else {
    motorRechts.write(0);
  }
}