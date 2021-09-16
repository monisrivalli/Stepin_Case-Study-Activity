/*
 */

#include <avr/io.h>
#include <util/delay.h>

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"

uint16_t adc_read(uint8_t ch);
uint16_t buttons();

int main(void)
{

    // Insert code


         initialize_peripheral();
         initialize_adc();
         initialize_pwm();

         uint16_t temp_val=0,previous_value=0;


   while(1)
   {
if (!buttons())
        {
            continue;
        }
        else
        {
            while(1)
            {   previous_value=temp_val;
                temp_val  = adc_read(0);
                if (temp_val==previous_value)
                {
                    continue;
                }
                if (temp_val<=200)
                {
                    OCR0A=51;
                    _delay_ms(200);
                }
                else if(temp_val<=500)
                {
                    OCR0A=102;

                    _delay_ms(200);
                }
                else if(temp_val<=700)
                {
                    OCR0A=179;

                    _delay_ms(200);
                }
                else
                {
                    OCR0A=243;
                  _delay_ms(200);
                }
            }
        }
   }

    return 0;

};
