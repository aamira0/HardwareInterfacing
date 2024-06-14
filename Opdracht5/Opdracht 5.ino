#include <Servo.h>

// Maak een Servo object aan
Servo servo;

// Definieer pinnen voor de drukknoppen
const int pinButton1 = 8;
const int pinButton2 = 4;

void setup(){
  servo.attach(11);
  // Stel de pin van de knop in als invoer
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
}

void loop() {
// Controleer of beide knoppen zijn ingedrukt
  if (digitalRead(pinButton1) == LOW && digitalRead(pinButton2) == LOW) {
    moveServo(0, 120, 3000); // Draai naar 120 graden in 3 seconden
    delay(5000); // Wacht 5 seconden
    moveServo(120, 0, 500); // Draai terug naar 0 graden in 0.5 seconden
  }
  else if (digitalRead(pinButton1) == LOW) {
  // Controleer of alleen de eerste knop is ingedrukt
    moveServo(0, 120, 3000); // Draai naar 120 graden in 3 seconden
    moveServo(120, 0, 3000); // Draai terug naar 0 graden in 3 seconden
  }
  // Controleer of alleen de tweede knop is ingedrukt
  else if (digitalRead(pinButton2) == LOW) {
    moveServo(0, 120, 500); // Draai naar 120 graden in 0.5 seconden
    moveServo(120, 0, 500); // Draai terug naar 0 graden in 0.5 seconden
  }
}

// Functie om de servo te verplaatsen tussen twee posities in een bepaalde tijdsduur
void moveServo(int startPos, int endPos, int duration) {
  int increment = (endPos > startPos) ? 1 : -1; // Bepaal de richting van de beweging
  int steps = abs(endPos - startPos); // Bereken het aantal stappen
  int stepDelay = duration / steps; // Bereken de vertraging per stap

  for (int pos = startPos; pos != endPos; pos += increment) {
    servo.write(pos); // Verplaats de servo naar de nieuwe positie
    delay(stepDelay); // Wacht voor de volgende stap
  }

  // Zorg ervoor dat de servo in de juiste positie stopt
  servo.write(endPos);
}


