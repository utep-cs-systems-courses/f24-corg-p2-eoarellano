#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
int state = 0;

void state_advance()
{   
    switch (state)
    {
    case 1:
        both_leds_on();
        buzzer_set_period(1000);
        break;
    case 2:
        red_led_on();
        buzzer_set_period(0);
        break;
    case 3:
        //wdt handles siren
        break;
    case 4:
        green_led_on();
        break;
    }
}

void __interrupt_vec(WDT_VECTOR) WDT()
{
    if (state == 3)
    {
        siren();
    }
    if (state == 4)
    {
        halloween_update();
    }
    else 
    {
        state_advance();
    }
}