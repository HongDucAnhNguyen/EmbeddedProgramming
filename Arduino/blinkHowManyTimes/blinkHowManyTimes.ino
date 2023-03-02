int mySerIntVal;
int led = 4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//this tells arduino to exchange data with serial monitor
//at a rate of 9600 bits per sec - baud rate
pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("How many times do you want to blink the LED: ");
//while there is no data in serial port
while(Serial.available() == 0){
//do nothing
}
mySerIntVal = Serial.parseInt();
//Serial.readString() to read a string val
blink(led, mySerIntVal);
}

void blink(int led, int blinkNum){
  for(int i = 0; i < blinkNum; i++){
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
  }
}
