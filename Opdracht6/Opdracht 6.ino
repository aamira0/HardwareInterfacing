#include <Servo.h>

Servo servo; // Maak een Servo object aan

// Definieer de pinnen voor de ultrasone sensor
const int triggerPin = 12;
const int echoPin = 11;

void setup() {
  servo.attach(6); // Servo is verbonden met pin 6
  pinMode(triggerPin, OUTPUT); // Stel trigger pin in als output
  pinMode(echoPin, INPUT); // Stel echo pin in als input

  servo.write(0); // Zet de servo in de rustpositie (0 graden)
  Serial.begin(9600); // Start seriële communicatie voor debugging
}

void loop() {
  // Stuur een ultrasonisch signaal
  digitalWrite(triggerPin, LOW); // Zet trigger pin laag
  delayMicroseconds(2); // Korte vertraging van 2 microseconden
  digitalWrite(triggerPin, HIGH); // Zet trigger pin hoog
  delayMicroseconds(10); // Houd de trigger pin hoog voor 10 microseconden
  digitalWrite(triggerPin, LOW); // Zet trigger pin laag

  // Meet de duur van het terugkerende signaal
  long duration = pulseIn(echoPin, HIGH); // Meet de pulsduur van de echo
  int distance = duration * 0.034 / 2; // Bereken de afstand in cm

  // Print de gemeten afstand naar de seriële monitor
  Serial.print("Afstand: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Bereken de positie van de servo op basis van de afstand
  int servoPos;
  if (distance <= 4) {
    // Als de afstand 4 cm of minder is, draai de servo naar 0 graden
    servoPos = 0;
  } else if (distance > 4 && distance <= 10) {
    // Als de afstand tussen 4 cm en 10 cm ligt, bereken de servo positie lineair
    servoPos = map(distance, 4, 10, 180, 0);
  } else {
    // Als de afstand meer dan 10 cm is, draai de servo weer naar 0 graden
    servoPos = 0;
  }

  // Schrijf de berekende positie naar de servo
  servo.write(servoPos);

  // Wacht 100 milliseconden voor de volgende meting
  delay(100);
}


