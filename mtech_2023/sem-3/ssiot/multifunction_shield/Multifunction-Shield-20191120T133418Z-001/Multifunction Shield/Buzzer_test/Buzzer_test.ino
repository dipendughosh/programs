//Define the analogue pin used to read the potentiometer
#define POT_DIO 0

/* Define the digital pin used to control the buzzer */
#define BUZZER_DIO 3

#define OFF HIGH
#define ON LOW

void setup()
{
 /* Set the buzzer pin to an output and turn the buzzer off */
 pinMode(BUZZER_DIO, OUTPUT);
 digitalWrite(BUZZER_DIO, OFF);

}

void loop()
{
 /* Read the current position of the 10K potentiometer and use it 
    as a time delay */
 delay(analogRead(POT_DIO));
 
 /* Turn the buzzer on for 20ms and then turn it back off again */
 digitalWrite(BUZZER_DIO, ON);
 delay(20);
 digitalWrite(BUZZER_DIO, OFF);
}