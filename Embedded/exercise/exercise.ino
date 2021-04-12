//2초주기로 깜빡이는 led
//5초주기로 온도값 블루투스 전송
#include <NeoSWSerial.h>
int RX = 3;
int TX = 2;
NeoSWSerial mySerial(RX, TX);
int dir_l = 4;
int dir_r = 7;
int pwm_l = 6;
int pwm_r = 5;
int red = 10;
int green = 9;
int blue = 11;
volatile int vel = 100;
volatile int led = 0;
unsigned long timer1 = 0;
unsigned long timer2 = 0;
float temp, volt;
int analogv;
bool myLedStep = false;
void setup() {
  // put your setup code here, to run once:  Keyboard.begin();
  pinMode(dir_l, OUTPUT);
  pinMode(dir_r, OUTPUT);
  pinMode(pwm_l, OUTPUT);
  pinMode(pwm_r, OUTPUT);
  Serial.begin(9600);
  mySerial.attachInterrupt(handleRxChar);
  mySerial.begin(9600);

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
}

volatile char mybuf;
volatile bool flag;

static void handleRxChar(uint8_t c)
{
  mybuf = (char)c;
  flag = true;
}

char str[256];

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - timer1 > 4999)
  {
    timer1 = millis();
    Serial.println("duration 5seconds");
    analogv = analogRead(A0);
    volt = 3.3 * ((float)analogv / 1024.0);
    temp = (float)((volt * 100) - 50);
    mySerial.println(temp);
  }
  if (millis() - timer2 > 1999)
  {
    timer2 = millis();
    Serial.println("duration 2seconds");
    if (myLedStep)
    {
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
    }
    else
    {
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    }
    myLedStep = !myLedStep;
  }



  if (flag/*mySerial.available()*/) {
    flag = false;
    //mybuf = mySerial.read();
    if (96 < mybuf) {
      moving(HIGH, HIGH, 0, 0);
      Serial.println(mybuf);
      Serial.println("");
    }
    else {
      //전진
      if ('U' == mybuf)
      {
        Serial.println("U : Start normal forward");
        vel = 100;
        moving(HIGH, HIGH, vel, vel);
      }
      //후진
      else if ('D' == mybuf)
      {
        Serial.println("D : Start normal Backward");
        moving(LOW, LOW, 100, 100);
      }
      //좌회전
      else if ('L' == mybuf)
      {
        Serial.println("L : Start Left Spin");
        moving(LOW, HIGH, 200, 200);
      }
      //우회전
      else if ('R' == mybuf)
      {
        Serial.println("R : Start Right Spin");
        moving(HIGH, LOW, 200, 200);
      }
      //좌전진
      else if ('B' == mybuf)
      {
        Serial.println("B: Start Turn LEFT");
        moving(LOW, HIGH, 0, 200);
      }
      //우전진
      else if ('E' == mybuf)
      {
        Serial.println("E : Start Turn RIGHT");
        moving(HIGH, LOW, 200, 0);
      }
      //밀기
      else if ('F' == mybuf)
      {
        Serial.println("F : start add velocity");
        vel = vel + 50;
        vel = vel > 255 ? 100 : vel;
        moving(HIGH, HIGH, vel, vel);

      }
      //LED
      else if ('A' == mybuf)
      {
        Serial.println("A : start led");
        led = led % 4;
        Serial.println(led);
        switch (led)
        {
          case 0:
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            break;
          case 1:
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            break;
          case 2:
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
            break;
          default:
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            break;
        }
        led = led + 1;
      }
      else
      {
        moving(HIGH, HIGH, 0, 0);
        Serial.println(mybuf + "default : Stop");
        Serial.println("");
      }
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

/*buzzerStep = buzzerStep % 2;
      Serial.println(buzzerStep);
      switch (buzzerStep)
      {
        case 0:
          tone(8, 100);
          delay(50);
          break;
        case 1:
          noTone(8);
          break;
        default:
          noTone(8);
          break;
      }
      //buzzerStep = buzzerStep + 1;*/
