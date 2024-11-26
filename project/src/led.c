#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void led_init()
{
    P1DIR |= LEDS;
    P1OUT &= ~LEDS; /* leds initially off */
}

both_leds_on()
{
    P1OUT |= LEDS;
}

int led_on = 0;

// Toggles the green LED
void siren()
{
  if (led_on) {
    P1OUT &= ~LED_RED;   /* turn off red LED */
    P1OUT |= LED_GREEN;  /* turn on green LED */
    buzzer_set_period(1000);
    led_on = 0;
  } else {
    P1OUT &= ~LED_GREEN; /* turn off green LED */
    P1OUT |= LED_RED;    /* turn on red LED */
    buzzer_set_period(500);
    led_on = 1;
  }
}

void led_update() {

}

  int wcount = 0;

  // Uses the watchdog timer to toggle the green LED every 250 interrupts or 1 second
  void
  __interrupt_vec(WDT_VECTOR) WDT() /* 250 interrupts/sec */
  {
    wcount++ ; if (wcount == 100)
    {
      wcount = 0;
      state_next();
    }
  }