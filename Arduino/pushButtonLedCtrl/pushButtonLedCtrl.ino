int redLedPin = 13;
int btnPin = 12;
int btnDigiRead;

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);
pinMode(12, INPUT);
Serial.begin(9600);
}

void loop() {
  //Reading from pin 12
btnDigiRead = digitalRead(btnPin);
/*showing digital value read from pin 12 to
Serial Monitor
*/
Serial.println(btnDigiRead);
delay(100);
if(btnDigiRead == 1){
/*1 signals button is not pressed in the context
of pull-up resistor*/
  digitalWrite(redLedPin, LOW);
}
 /*0 signals button is pressed in the context
  of pull-up resistor*/
  else{
    digitalWrite(redLedPin, HIGH);
  }
}
