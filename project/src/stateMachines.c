#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static int state = 1; // Initial state

void state_advance()
{
    switch (state)
    {
    case 1:
        both_leds_on();
        buzzer_set_period(0);
        state = 2;
        break;
    case 2:
        siren();
        state = 3;
        break;
    case 3:
        buzzer_set_period(3000);
        state = 1;
        break;
    }
}