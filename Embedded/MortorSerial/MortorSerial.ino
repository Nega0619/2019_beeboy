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
}

char buf;
int vel = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    buf = Serial.read();
    if ('0' == buf) {
      digitalWrite(dir_l, HIGH);
      digitalWrite(dir_r, HIGH);
      vel = 100;
      Serial.println(vel);  Serial.println("");

      Serial.println("0 Clicked : Start Move");
    }
    else if ('1' == buf) {
      vel = 0;
      Serial.println(vel);  Serial.println("");

      Serial.println("1 Clicked : Stop");
    }
    else if ('2' == buf) {
      vel += 50;
      Serial.println(vel);  Serial.println("");

      Serial.println("2 Clicked : faster");
    }
    else if ('3' == buf)
    { vel -= 50;
    Serial.println(vel);  Serial.println("");

      Serial.println("3 Clicked : slower");
    }
  }
  //vel = vel < 20 ? 0 : vel;
  //vel = vel > 1000 ? 1000 : vel;
  //Serial.println("");
  analogWrite(pwm_l, vel);
  analogWrite(pwm_r, vel);
}
