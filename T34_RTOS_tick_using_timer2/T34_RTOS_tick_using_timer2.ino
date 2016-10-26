//RTOS tick using Timer2 
uint16_t ms;
uint8_t sec;

void setup() 
{
  Serial.begin(9600);
  SCH_Init_T2();
}

void loop() 
{
  Serial.println(sec);
  delay(1000);
}

void SCH_Init_T2(void)
{
  TCCR2A = 0x00;                  //clearing the registers because at wiring.c these were used for pwm 
  TCCR2B = 0x00;
  TCNT2 = 0x00;
  
  TCCR2A |= (1<<WGM21);           //CTC mode
  TCCR2B |= (1<<CS20)|(1<<CS22);  //prescalar is 128
  OCR2A = 125;                    //Output compare register loaded
  TIMSK2 |= (1<<OCIE2A);          //Timer/Counter2 Output Compare Match A Interrupt Enabled
  sei();                          //global interrupt enabled
}

ISR(TIMER2_COMPA_vect) 
{ 
  ms++;
  if(ms == 1000)
    {
      ms = 0;
      sec++;
      if(sec == 60)
        {
          sec = 0;
        }
    }
}



