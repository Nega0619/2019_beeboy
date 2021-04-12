int dir_l = 4;
int dir_r = 7;
int pwm_l = 6;
int pwm_r = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(dir_l, OUTPUT);
  pinMode(dir_r, OUTPUT);
  pinMode(pwm_l, OUTPUT);
  pinMode(pwm_r, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir_l, HIGH);
  digitalWrite(dir_r, HIGH);
  analogWrite(pwm_l, 100);
  analogWrite(pwm_r, 100);
}
