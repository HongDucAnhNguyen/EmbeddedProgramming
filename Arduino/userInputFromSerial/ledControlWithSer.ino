String mySerVal;
int ledRed = 4;
int ledYellow = 5;
int ledGreen = 6;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    // this tells arduino to exchange data with serial monitor
    // at a rate of 9600 bits per sec - baud rate
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println("Pick an LED color to light up");
    Serial.println("1/ Red");
    Serial.println("2/ Yellow");
    Serial.println("3/ Green");
    Serial.println("4/ Traffic Lights");

    // while there is no data in serial port
    while (Serial.available() == 0)
    {
        // do nothing
    }
    mySerVal = Serial.readString();
    // similar to fgets

    mySerVal.toLowerCase();

    // Serial.readString() to read a string val
    if (mySerVal == "red\n")
    {
        digitalWrite(ledRed, HIGH);

        handleLights(ledRed, ledYellow, ledGreen);
    }
    else if (mySerVal == "yellow\n")
    {
        handleLights(ledYellow, ledRed, ledGreen);
    }
    else if (mySerVal == "green\n")
    {
        handleLights(ledGreen, ledRed, ledYellow);
    }
    else if (mySerVal == "traffic lights\n")
    {

        handleLights(ledRed, ledYellow, ledGreen);
        delay(1000);
        handleLights(ledYellow, ledRed, ledGreen);
        delay(1000);
        handleLights(ledGreen, ledRed, ledYellow);
        delay(1000);
    }

    else
    {
        Serial.println("Invalid Input!");
    }
}

void handleLights(int pinToHigh, int pinToLow1, int pinToLow2)
{

    digitalWrite(pinToHigh, HIGH);
    digitalWrite(pinToLow1, LOW);
    digitalWrite(pinToLow2, LOW);
}
