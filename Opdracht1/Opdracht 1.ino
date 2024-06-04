void setup()
{
  // Stel de pinnen 13 en 10 in als uitvoer
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // LED op pin 13 aanzetten, wachten voor 2000 milliseconden, en dan weer uitzetten
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  
    // LED op pin 10 aanzetten, wachten voor 2000 milliseconden, en dan weer uitzetten
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
}