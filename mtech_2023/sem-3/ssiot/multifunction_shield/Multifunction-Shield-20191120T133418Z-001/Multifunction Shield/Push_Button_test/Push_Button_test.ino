/* Define pin numbers used to read the state of the buttons. 
  The buttons are connected to the Arduino's analogue pins but 
  because they only have two states we will read them as digital 
  inputs */
#define BUTTON1 A1
#define BUTTON2 A2
#define BUTTON3 A3

void setup()
{
 Serial.begin(9600); 
}

void loop()
{

 /* Has button one been pressed? */
 if(!digitalRead(BUTTON1))
   /* If so then send a message to the serial port */
   Serial.println("Button 1 Pressed!");
 /* Has button two been pressed? */
 if(!digitalRead(BUTTON2))
   /* If so then send a message to the serial port */
   Serial.println("Button 2 Pressed!");
 /* Has button three been pressed? */
 if(!digitalRead(BUTTON3))
   /* If so then send a message to the serial port */
   Serial.println("Button 3 Pressed!");
}