#include <avr/io.h>
#include "activity3.h"
void initialize_pwm()
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    DDRD|=(1<<PD6);
}
