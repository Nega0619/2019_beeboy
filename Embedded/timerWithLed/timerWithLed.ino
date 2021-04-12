//MANG
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(500);
}
unsigned long timer1 = 0;
unsigned long timer2 = 0;

int step = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - timer1 > 4999)
  {
    timer1 = millis();
    Serial.println("duration 5seconds");
    switch (step) {
      case 0:
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 1:
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 2:
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 3:
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(500);
        break;
      default : break;
    }
    step = step + 1;
  }
  if (millis() - timer2 > 1999)
  {
    timer2 = millis();
    Serial.println("duration 2seconds");
    switch (step) {
      case 0:
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 1:
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 2:
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        delay(500);
        break;
      case 3:
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(500);
        break;
      default : break;
    }
    step = step + 1;
  }    
  Serial.println(step);
  step = step % 4;

}
