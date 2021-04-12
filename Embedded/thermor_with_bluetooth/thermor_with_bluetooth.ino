#include <SoftwareSerial.h>
int RX = 3;
int TX = 2;
SoftwareSerial mySerial(RX, TX);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

float temp, volt;
int analogv;

void loop() {
  // put your main code here, to run repeatedly:
  analogv = analogRead(A0);
  volt = 3.3 * ((float)analogv / 1024.0);
  temp = (float)((volt * 100) - 50);
  mySerial.println(temp);
  //Serial.println(temp);
  delay(500);
}
