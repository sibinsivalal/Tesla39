void charge()
{
  if(solarV>Vbat && Vbat<14.20)
  {
    if(Vbat<= 13.60)
    {
      duty=255;
        analogWrite(chargePin,duty);

    }
    else if (Vbat > 13.6 && Vbat <= 14.20)
    
                  {
       
                    

                  
                  error=(14.20-Vbat);
                  ep=error*100;
                  ///////////////////OMMITING NEGATIVE VALUES//////////////////////////
                  if(ep<0)
                  {
                  ep=0;
                  }
                  
                  else if(ep>100)
                  {
                  ep=100;
                  }
                  /////////////////////////////////////////////
                  else if(ep>0 && ep<=100)
                  {
                  duty =(ep*255)/100;
                  }
                  analogWrite(chargePin,duty);
              
                  }
                  
                 
                 
                  
  }
///////////////////////////////////END///////////////////////////////////////////////////////////////////////////
  else
  {

        analogWrite(chargePin,0);
        duty=0;
  }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  



  
}
