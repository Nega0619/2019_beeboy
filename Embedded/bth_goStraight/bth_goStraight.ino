#include <SoftwareSerial.h>
int RX = 3;
int TX = 2;
SoftwareSerial mySerial(RX, TX);
int dir_l = 4;
int dir_r = 7;
int pwm_l = 6;
int pwm_r = 5;

void setup() {
  // put your setup code here, to run once:  Keyboard.begin();
  pinMode(dir_l, OUTPUT);
  pinMode(dir_r, OUTPUT);
  pinMode(pwm_l, OUTPUT);
  pinMode(pwm_r, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

char buf;
char mybuf;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    buf = Serial.read();
    //전진
    switch (buf)
    {
      //전진
      case 'U':
      case 'u':
      //후진
      case 'D':
      case 'd':
      //좌회전
      case 'L':
      case 'l':
      //우회전
      case 'R':
      case 'r':
      //좌전진
      case 'B':
      case 'b':
      //우전진
      case 'E':
      case 'e':
        //실행부분
        mySerial.write(buf);
        break;
      default:
        break;
    }

  }
  if (mySerial.available()) {
    mybuf = mySerial.read();
    //전진
    if ('U' == mybuf)
    {
      Serial.println("U : Start forward");
      moving(HIGH, HIGH, 100, 100);
    }
    if ('u' == mybuf)
    {
      Serial.println("u : Stop forward");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //후진
    if ('D' == mybuf)
    {
      Serial.println("D : Start Backward");
      moving(LOW, LOW, 100, 100);
    }
    if ('d' == mybuf)
    {
      Serial.println("d : Stop Backward");
      moving(LOW, LOW, 0, 0);
      Serial.println("");
    }
    //좌회전
    if ('L' == mybuf)
    {
      Serial.println("L : Start Turn LEFT");
      moving(HIGH, HIGH, 50, 100);
    }
    if ('l' == mybuf)
    {
      Serial.println("l : Stop Turn LEFT");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //우회전
if ('R' == mybuf)
    {
      Serial.println("R : Start Turn RIGHT");
      moving(HIGH, HIGH, 100, 50);
    }
    if ('r' == mybuf)
    {
      Serial.println("r : Stop Turn RIGHT");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //좌전진

    //우전진

  }
}

void moving(int dirl, int dirr, int pwml, int pwmr)
{
  digitalWrite(dir_l, dirl);
  digitalWrite(dir_r, dirr);
  analogWrite(pwm_l, pwml);
  analogWrite(pwm_r, pwmr);
}
