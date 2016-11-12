void lcddisplay()
{
   lcd.setCursor(0,0);
  lcd.write((uint8_t)0);
  lcd.setCursor(2,0);
  lcd.print(solarV);

  lcd.setCursor(9,0);
  lcd.write((uint8_t)1);
   lcd.setCursor(11,0);
  lcd.print(Vbat);

   lcd.setCursor(0,1);
 lcd.print("duty :");
}

