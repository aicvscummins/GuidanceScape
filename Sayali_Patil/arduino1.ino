#define RED_PIN 8
#define YELLOW_PIN 10
#define GREEN_PIN 12

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN,OUTPUT);
  pinMode(YELLOW_PIN,OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_PIN,HIGH);
  delay(3000);
  digitalWrite(YELLOW_PIN,HIGH);
  delay(1000);
  digitalWrite(RED_PIN,LOW);
  digitalWrite(YELLOW_PIN,LOW);
  digitalWrite(GREEN_PIN,HIGH);
  delay(3000);
  digitalWrite(GREEN_PIN,LOW);
  for(int i=0;i<3;i=i+1)
  {
    delay(500);
    digitalWrite(GREEN_PIN,HIGH);
    delay(500);
    digitalWrite(GREEN_PIN,LOW);
   
  }
   digitalWrite(YELLOW_PIN,HIGH);
   delay(1000);
   digitalWrite(YELLOW_PIN,LOW);

}
