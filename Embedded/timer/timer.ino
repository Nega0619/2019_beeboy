void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - timer1 > 4999)
  {
    timer1 = millis();
    Serial.println("duration 5seconds");
  }
  if (millis() - timer2 > 1999)
  {
    timer2 = millis();
    Serial.println("duration 2seconds");
  }
}
