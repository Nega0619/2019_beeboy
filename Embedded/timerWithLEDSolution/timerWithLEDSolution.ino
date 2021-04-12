void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
unsigned long timer1 = 0;

int count = 0; //하지마 overflow때문에 안좋아
//bool count = true;

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - timer1 > 4999)
  {
    timer1 = millis();
    if(count %2 )
    //if(count)
    Serial.println("on duration 5seconds");
    else 
    Serial.println("off duration 5seconds");
    count++;    //오버플로우 일어남. 안좋음
    //count = !count;
  }
  
}
