// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 10, en = 9, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;  // input pin for the potentiometer
int digitalValue = 0;// variable to store the value coming from the sensor

int PWM_Pin = 3; /* give PWM_Pin name to D3 pin */
float duty=0.3;

float analogVoltage=0.0;
char ADCSHOW[5]; //initializing a character of size 5 for showing the ADC result
float max_light=1.25;



void setup() 
{
  pinMode(PWM_Pin,OUTPUT);
  analogWrite(PWM_Pin,127*2*duty);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("ARAPUMPKIN");
  delay(1000);
}


void loop() {

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  // print the number of seconds since reset:
  

  digitalValue = analogRead(sensorPin);// read the value from the analog channel
  //lcd.print(millis() / 1000);
  analogVoltage = (digitalValue * 5.00)/1023.00*(100/max_light);

  lcd.print("Light: ");
  String ADCVALUE = String(analogVoltage); //intailizing a string and storing ADC value in it 

  ADCVALUE.toCharArray(ADCSHOW, 5); // convert the reading to a char array 

  lcd.print(ADCSHOW); //showing character of ADCSHOW

  lcd.print("%");
  delay(500);

}
