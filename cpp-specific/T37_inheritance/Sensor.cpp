#include "Sensor.h"

volatile static uint16_t adcValue = 0;

Sensor::Sensor()                                             
{}

void Sensor::init(void)
{
  ADMUX|=(1<<REFS0);    //AVCC with external capacitor at AREF pin 
  ADMUX|=(1<<MUX2)|(1<<MUX0); //0101adc channel 5 selected for adc input
  ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);   //prescalar 128 selected 
  ADCSRA|=(1<<ADEN);    //adc enabled
  ADCSRA|=(1<<ADATE);   // ADC Auto Trigger Enable
  ADCSRA|=(1<<ADIE);   //adc interrupt enable such that interrupt will happen after each conversion
  ADCSRA|=(1<<ADSC);   //conversion process begins
  sei();
}

uint16_t Sensor::readRawAdcValue(void)
{
  return adcValue;
}

float Sensor::readmv(void)
{
  return((readRawAdcValue()/1024.0)*5000);
}

ISR(ADC_vect)       //adc interrupt service routine /tasks which will be executed by microprocessor after each conversion
{
adcValue=ADCL;        //ADCL data register read 
adcValue+=(ADCH<<8);  //ADCH data register read
}


