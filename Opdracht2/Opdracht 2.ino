void setup()
{
  // Stel de pinnen 1, 3, 5, 7, 8, 10, 12, en 13 in als uitvoer
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop(){
  // Roep de functie 'blinking' aan met een wachttijd van 100 milliseconden
  blink(100);
}

void blinking(int time){
  // LEDs op pins aanzetten, wachten, en dan weer uitzetten
  digitalWrite(13, HIGH);
  delay(time);
  digitalWrite(13, LOW);
  
  digitalWrite(12, HIGH);
  delay(time);
  digitalWrite(12, LOW);
  delay(time);
  
  digitalWrite(10, HIGH);
  delay(time);
  digitalWrite(10, LOW);
  delay(time);
  
  digitalWrite(8, HIGH);
  delay(time);
  digitalWrite(8, LOW);
  delay(time);
  
  digitalWrite(7, HIGH);
  delay(time);
  digitalWrite(7, LOW);
  delay(time);
  
  digitalWrite(5, HIGH);
  delay(time);
  digitalWrite(5, LOW);
  delay(time);
  
  digitalWrite(3, HIGH);
  delay(time);
  digitalWrite(3, LOW);
  delay(time);
  
  digitalWrite(1, HIGH);
  delay(time);
  digitalWrite(1, LOW);
  
  // Terugkeren in de omgekeerde volgorde
  digitalWrite(1, HIGH);
  delay(time);
  digitalWrite(1, LOW);
  delay(time);
  
  digitalWrite(3, HIGH);
  delay(time);
  digitalWrite(3, LOW);
  delay(time);
  
  digitalWrite(5, HIGH);
  delay(time);
  digitalWrite(5, LOW);
  delay(time);
  
  digitalWrite(7, HIGH);
  delay(time);
  digitalWrite(7, LOW);
  delay(time);
  
  digitalWrite(8, HIGH);
  delay(time);
  digitalWrite(8, LOW);
  delay(time);
  
  digitalWrite(10, HIGH);
  delay(time);
  digitalWrite(10, LOW);
  delay(time);
  
  digitalWrite(12, HIGH);
  delay(time);
  digitalWrite(12, LOW);
  delay(time);
  
  digitalWrite(13, HIGH);
  delay(time);
  digitalWrite(13, LOW);
}
