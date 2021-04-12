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

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    buf = Serial.read();
    if ('0' == buf) {
      digitalWrite(dir_l, HIGH);
      digitalWrite(dir_r, HIGH);
      analogWrite(pwm_l, 100);
      analogWrite(pwm_r, 100);
      Serial.println("0 Clicked : Start Move");
    }
    else if ('1' == buf) {
      analogWrite(pwm_l, 0);
      analogWrite(pwm_r, 0);
      Serial.println("1 Clicked : Stop");
    }
  }
}
