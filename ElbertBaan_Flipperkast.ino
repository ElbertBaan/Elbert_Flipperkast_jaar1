

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Netwerk
String naam = "Elbert";
String machine = "TI1C";

// Waardes
int levens = 3;
long score = 0;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Startknop
const int startKnop = 10;
bool spelGestart = false;

// Relais voor DC-motor
const int relaisPin = 2;

// Cooldowns
int lastScoreStatus = HIGH;
int lastLevensStatus = HIGH;

unsigned long lastScoreTime = 0;
unsigned long lastLevensTime = 0;

const unsigned long scoreCooldown = 500;
const unsigned long levensCooldown = 15000;

// Servo's
Servo motorlinks;
Servo motorrechts;

const int flipperlinks = 11;
const int flipperrechts = 10;


unsigned long lastLedTime = 0;
bool ledStand = false;



void setup() {

  Serial.begin(9600);


  // Flippers
  pinMode(flipperlinks, INPUT_PULLUP);
  pinMode(flipperrechts, INPUT_PULLUP);

  motorlinks.attach(9);
  motorrechts.attach(8);

  motorlinks.write(0);
  motorrechts.write(0);

  // Startknop
  pinMode(startKnop, INPUT_PULLUP);

  // Relais
  pinMode(relaisPin, OUTPUT);
  digitalWrite(relaisPin, LOW);

  // LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Rechter knop");

  lcd.setCursor(0, 1);
  lcd.print("voor start");
}

void fliplinks() {
  if (digitalRead(flipperlinks) == LOW) {
    motorlinks.write(95);
  } else {
    motorlinks.write(0);
  }
}

void fliprechts() {
  if (digitalRead(flipperrechts) == LOW) {
    motorrechts.write(0);
  } else {
    motorrechts.write(95);
  }
}

void toonScore() {
  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.print(score);
  lcd.print("      ");
}

void toonLevens() {
  lcd.setCursor(0, 1);                
  lcd.print("Levens: ");
  lcd.print(levens);
  lcd.print("      ");
}


  


void loop() {

  // Wachten op start
  if (!spelGestart) {

    if (digitalRead(startKnop) == LOW) {

      spelGestart = true;
      score = 0;
      levens = 3;

      // Motor starten
      digitalWrite(relaisPin, HIGH);

      lcd.clear();
      toonScore();
      toonLevens();
    }

    return;
  }

  // Flippers
  fliplinks();
  fliprechts();

  
       


}