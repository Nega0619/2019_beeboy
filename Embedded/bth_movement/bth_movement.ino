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

int vel = 0;

void loop() {
  // put your main code here, to run repeatedly:
/*  if (Serial.available()) {
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
      //가속(밀기)
      case 'F':
      case 'f':
        //실행부분
        Serial.println(buf);
        mySerial.write(buf);
        break;
      default:
        mySerial.write(buf);
        break;
    }
  }*/
  if (mySerial.available()) {
    mybuf = mySerial.read();
    //전진
    if ('U' == mybuf)
    {
      Serial.println("U : Start normal forward");
      vel = 100;
      moving(HIGH, HIGH, vel, vel);

      //Serial.println("vel = " + vel);
    }
    else if ('u' == mybuf)
    {
      Serial.println("u : Stop forward");
      vel = 0;
      moving(HIGH, HIGH, vel, vel);
      Serial.println("");
    }
    //후진
    else if ('D' == mybuf)
    {
      Serial.println("D : Start normal Backward");
      vel = 100;
      moving(LOW, LOW, vel, vel);
    }
    else if ('d' == mybuf)
    {
      Serial.println("d : Stop Backward");
      vel = 0;
      moving(LOW, LOW, vel, vel);
      Serial.println("");
    }
    //좌회전
    else if ('L' == mybuf)
    {
      Serial.println("L : Start Left Spin");
      moving(HIGH, HIGH, 0, 200);
    }
    else if ('l' == mybuf)
    {
      Serial.println("l : Stop Left Spin");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //우회전
    else if ('R' == mybuf)
    {
      Serial.println("R : Start Right Spin");
      moving(HIGH, HIGH, 200, 0);
    }
    else if ('r' == mybuf)
    {
      Serial.println("r : Stop Right Spin");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //좌전진
    else if ('B' == mybuf)
    {
      Serial.println("B: Start Turn LEFT");
      moving(HIGH, HIGH, 100, 200);
    }
    else if ('b' == mybuf)
    {
      Serial.println("b : Stop Turn LEFT");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //우전진
    else if ('E' == mybuf)
    {
      Serial.println("E : Start Turn RIGHT");
      moving(HIGH, HIGH, 200, 100);
    }
    else if ('e' == mybuf)
    {
      Serial.println("e : Stop Turn RIGHT");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    //밀기
    else if ('F' == mybuf)
    {
      Serial.println("F : start add velocity");
      vel += 50;
      //Serial.println("vel = " + vel);
      moving(HIGH, HIGH, vel, vel);
    }
    else if ('f' == mybuf)
    {
      Serial.println("f : Stop add velocity");
      moving(HIGH, HIGH, 0, 0);
      Serial.println("");
    }
    else
    {
      moving(HIGH, HIGH, 0, 0);
      Serial.println("default : Stop");
      Serial.println("");
    }
  }
}

void moving(int dirl, int dirr, int pwml, int pwmr)
{
  digitalWrite(dir_l, dirl);
  digitalWrite(dir_r, dirr);
  analogWrite(pwm_l, pwml);
  analogWrite(pwm_r, pwmr);
}
