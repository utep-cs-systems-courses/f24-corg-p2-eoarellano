// Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void)
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_RED;
  P1OUT |= LED_GREEN;

  configureClocks();     /* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts(); /* enable periodic interrupt */

  or_sr(0x18); /* CPU off, GIE on */
}

int led_on = 0;

// Toggles the green LED
void toggle_green_led()
{
  if (led_on){
    P1OUT &= ~LED_GREEN;
    led_on = 0;
  }else{
    P1OUT |= LED_GREEN;
    led_on = 1;
  }
}
  int wcount = 0;

  // Usses the watchdog timer to toggle the green LED every 250 interrupts or 1 second
  void
  __interrupt_vec(WDT_VECTOR) WDT() /* 250 interrupts/sec */
  {
    wcount++ ; if (wcount == 50)
    {
      wcount = 0;
      toggle_green_led();
    }
  }