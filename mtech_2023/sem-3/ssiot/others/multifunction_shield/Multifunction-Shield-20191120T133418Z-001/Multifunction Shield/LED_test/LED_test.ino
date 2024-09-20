void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}
void loop()
{
  // led On
  digitalWrite(13, LOW);
  delay(100);
  // led Off
  digitalWrite(13, HIGH);
  delay(100);
    // led On
  digitalWrite(12, LOW);
  delay(100);
  // led Off
  digitalWrite(12, HIGH);
  delay(100);  // led On
  digitalWrite(11, LOW);
  delay(100);
  // led Off
  digitalWrite(11, HIGH);
  delay(100);  // led On
  digitalWrite(10, LOW);
  delay(100);
  // led Off
  digitalWrite(10, HIGH);
  delay(100);
}