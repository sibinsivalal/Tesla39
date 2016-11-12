void load()
{
  if(button==HIGH)
  {
    digitalWrite(loadPin, HIGH); 
   // Serial.println("ON");
       if(Vbat>11.70)
       {
        digitalWrite(loadPin,HIGH);
       }
       else
       {
        do
        {
            sense();
          digitalWrite(loadPin,LOW);
          lcddisplay();
          

            if(button==HIGH)// if button is pressed in do while after battery gets fully discharged display blinks " battery low"
             {
            lcd.setCursor(0,1);
            lcd.print("!!BATTERY LOW!!");

              }
              else
              {
               lcd.setCursor(0,1);
               lcd.print("batry discharged");
              }
          
          
        }
        while(solarV<14.00);
       }
  }
  else
  {
    digitalWrite(loadPin, LOW); 
   //Serial.println("OFF");
  }
}

