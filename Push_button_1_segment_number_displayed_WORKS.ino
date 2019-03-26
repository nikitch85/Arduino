/*
 * 
 *The below code returns the number of button pushes and it is then displayed on 1 digit 7 segment display
 *Everytime you push the button buttonPushCounter increments to one
 *When you relese the button the last push button becomes LOW
 *Next time you push and hold the button it will also increase to one
 *
 *  Note: This is for 1 digit 7 segment display with common anode(+)
 *  The led is off when the output is HIGH and the led  is ON when the output is LOW.
 *      
 *      The following is the scematic of pin mapping.
 *      6
 *    -------
 *  7 |     |
 *    |  8  | 5
 *    -------
 *    |     |
 *  2 |     | 4
 *    -------
 *        3   * 9
 *     
 */


//Constant variables won't change
const int pushButton = 10; //setting up button at digital pin 10
byte Digital[11]={0x03,0xCF,0X25,0X85,0XC9,0X91,0X11,0XC7,0X01,0X81,0XFE};//the character code for number 0-9 and a dot

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
boolean buttonState = LOW;         // current state of the button
boolean lastButtonState = LOW;     // previous state of the button
int i = 0;

void setup() {
pinMode(pushButton, INPUT); //initializing the pin 10 to input
int i=2;
for(i=2;i<10;i++) //initializing 1 digit 7 segment
  {
   pinMode(i,OUTPUT);
   digitalWrite(i,HIGH);
  }
Serial.begin(9600); //enabling Serial for showing the results
}

void loop() {

if (digitalRead(pushButton))
{
  
  if (digitalRead(pushButton) && lastButtonState == LOW)
{
  delay(5);
  buttonState = digitalRead(pushButton);
  if (digitalRead(pushButton) == buttonState)
  {
    buttonPushCounter++;
  lastButtonState = digitalRead(pushButton);
  }
  else
  {
  lastButtonState = LOW;
 }
Serial.print("Number of pushes: ");
Serial.println(buttonPushCounter);

}
}
else
{
 lastButtonState = LOW;
}
if (buttonPushCounter > 9) buttonPushCounter = 0;
i = buttonPushCounter;
 int j;
    for(j=0;j<8;j++)
   {  
    if(Digital[i]&1<<j)
    digitalWrite(9-j,HIGH);
    else
    digitalWrite(9-j,LOW);
    }

}
