void dutylg()
{
int tempduty;
Serial.println(duty);
  tempduty=map(duty,0,255,0,100);

        lcd.setCursor(6,1);
        lcd.print(tempduty); 
        lcd.setCursor(9,1);
        lcd.print("%");
        if(tempduty<100)
        {
        lcd.setCursor(9,1);
        lcd.print(" ");
        lcd.setCursor(8,1);
        lcd.print("%");
        }
        if(tempduty<10)
        {
        lcd.setCursor(8,1);
        lcd.print("  ");
        lcd.setCursor(7,1);
        lcd.print("%");
        }

        
        
    
  
  
}

