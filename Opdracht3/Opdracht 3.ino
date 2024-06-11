// Definieer de pinnen voor de LEDs en de knop
const int led1 = 11;
const int led2 = 5;
int pinButton = 8;
int counter = 0;
int lastButtonState = LOW; // Vorige status van de knop zodat het uit staat

void setup() {
  // Stel de pin van de knop in als invoer
  pinMode(pinButton, INPUT_PULLUP); // Gebruik INPUT_PULLUP om interne pull-up weerstanden te gebruiken
  // Stel de pinnen van de LEDs in als uitvoer
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Zet beide LEDs uit aan het begin
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  // Lees de status van de knop
  int buttonState = digitalRead(pinButton);

  // Controleer of de knop is ingedrukt (overgang van HIGH naar LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    counter++; // Verhoog de teller
    delay(50); // Debouncing delay

    // Wissel de LEDs op basis van de tellerwaarde
    if (counter % 2 == 0) {
      // Zet LED op pin 11 uit
      digitalWrite(led1, LOW);
      // Zet LED op pin 5 aan
      digitalWrite(led2, HIGH);
    } else {
      // Zet LED op pin 11 aan
      digitalWrite(led1, HIGH);
      // Zet LED op pin 5 uit
      digitalWrite(led2, LOW);
    }
  }

  // Sla de huidige status van de knop op
  lastButtonState = buttonState;
}


