

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>




// Waardes
int levens = 3;
long score = 0;

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Startknop
const int startKnop = 10;
bool spelGestart = false;

// Servo's
Servo motorlinks;
Servo motorrechts;

const int flipperlinks = 11;
const int flipperrechts = 10;


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

  // LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Rechter knop");

  lcd.setCursor(0, 1);
  lcd.print("voor start");
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
void fliplinks() {
  if (digitalRead(flipperlinks) == LOW) {
    motorlinks.write(95);
  } else {
    motorlinks.write(0);
  }
}


  if (digitalRead(flipperrechts) == LOW) {
    motorrechts.write(0);
  } else {
    motorrechts.write(95);
}

  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.print(score);
  lcd.print("      ");



  lcd.setCursor(0, 1);                
  lcd.print("Levens: ");
  lcd.print(levens);
  lcd.print("      ");

       


}