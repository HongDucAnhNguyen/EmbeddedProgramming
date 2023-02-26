#define led 10
#define potenPin A1
float analogVal = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(potenPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potenVal = analogRead(potenPin);
  analogVal = (255. / 1023.) * potenVal; //to get range 0-255
  analogWrite(led, analogVal); 
}
