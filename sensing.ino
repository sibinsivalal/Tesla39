int sense()
{

  int sum2 = 0;
  int sample2 ;
    int sum1 = 0;
  int sample1 ;
  for (int i=0; i<100; i++) 
  {                                        // loop through reading raw adc values AVG_NUM number of times  
    sample1 = analogRead(A0);  
      sample2 = analogRead(A1);  // read the input pin  
    sum1 += sample1;   
    sum2 +=sample2;// store sum for averaging
    delayMicroseconds(50);              // pauses for 50 microseconds  
  }
  
average1 = sample1 / 100;// calculate the average1:

/////////////////////////////////////////

average2 = sample2 / 100;// calculate the average1:

/////////////////////////////////////////////


float vref1 = average1 * (4.11 / 1023.00);
solarV = vref1/0.1479;
          if (solarV<0.09) 
          {

          solarV=0.0;//statement to quash undesired reading !
          }

            

float vref2 = average2 * (4.11 / 1023.00);
Vbat = vref2/0.1466;
          if (Vbat<0.09) 
          {
          Vbat=0.0;//statement to quash undesired reading !
          }
delay(1);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) 
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
      if (reading != buttonState) 
      {
      buttonState = reading;
      if (buttonState == HIGH) 
      {
        loadState = !loadState;
      }
      }
  }

  button=loadState;

  lastButtonState = reading;
//Serial.println(loadState);

 

}

