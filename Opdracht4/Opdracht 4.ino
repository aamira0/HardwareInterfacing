// Definieer de pin voor de potentiometer
const int potPin = A5;
// Definieer de pins voor de LEDs
const int led[] = {13, 12, 10, 9, 7, 6};

// Variabelen voor de potmeterwaarde en de teller
int potmeterWaarde = 0;
int counter = 0;

void setup() {
  // Stel de pinnen van de LEDs in als uitvoer
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }

  // Start de seriële communicatie
  Serial.begin(9600);
}

void loop() {
  // Lees de waarde van de potentiometer
  potmeterWaarde = analogRead(potPin);

  // Map de potmeterwaarde naar een waarde tussen 0 en 6
  // Dit wordt gebruikt om te bepalen hoeveel LEDs aan moeten zijn
  counter = map(potmeterWaarde, 0, 1023, 0, 6);

  // Ga door elke LED
  for (int i = 0; i < 6; i++) {
    // Als de huidige LED binnen de teller valt, zet deze dan uit
    if (i < counter) {
      digitalWrite(led[i], LOW);  // LED uit
    } 
    // Anders, zet de LED aan
    else {
      digitalWrite(led[i], HIGH); // LED aan
    }
  }

  // Print de waarde van de potmeter naar de seriële monitor
  Serial.print("De waarde van de potmeter is: ");
  Serial.println(potmeterWaarde);

  // Print het aantal uitgeschakelde LEDs naar de seriële monitor
  Serial.print("Aantal LEDs uit: ");
  Serial.println(counter);

  // Wacht 500ms voordat de volgende lezing wordt gedaan
  delay(500);
}