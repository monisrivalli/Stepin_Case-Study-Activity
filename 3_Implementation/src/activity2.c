#include <avr/io.h>
#include "activity2.h"


void initialize_adc()
{
    ADMUX|=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t adc_read(uint8_t ch)
{
    //uint16_t ADC=100;
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);

    return (ADC);
}

