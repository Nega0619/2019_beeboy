void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  for (i = 0; i < 256; i++) {
    for
    analogWrite(9, i);
    analogWrite(10, i);
    analogWrite(11, i);
    delay(10);
  }

}
