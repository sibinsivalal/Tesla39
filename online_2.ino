
 #include <LiquidCrystal.h>

 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
////////////////////////////////////////////////////// ///PIN DECLARATION/////////////////////////////////////////////////////////////////
 int chargePin=9;
 const int buttonPin = 7; //push button attached to this pin
 int loadPin=13;

/////////////////////////////////////////////////// ///GLOBAL VARIABLES///////////////////////////////////////////////////////////////////

int average1 = 0;                // the average1

int average2 = 0;                // the average1

int  button =0;
int loadState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

 
float solarV;
 int sensorValue1;

 float Vbat;
 int sensorValue2;
 float error;
 float ep;
 int duty;

 /////////////





 byte solarChar[8] = 
 {
  0b10101,
  0b01010,
  0b10101,
  0b01010,
  0b10101,
  0b01010,
  0b10101,
  0b01010
};

byte batteryChar[8] = {
  0b01110,
  0b11011,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};
void setup() 
{
analogReference (EXTERNAL) ;
Serial.begin(9600);
lcd.begin(16, 2);


lcd.createChar(0, solarChar);
lcd.createChar(1, batteryChar);


pinMode(chargePin,OUTPUT);
 pinMode(buttonPin, INPUT);
 pinMode(loadPin,OUTPUT);
}


void loop() {
  sense();
  load();
  dutylg();
 lcddisplay();

charge();
load();

}
