## Description
This program turns on the red led

Be sure to understand the manipulation of P1OUT and P1DIR.

## Suggested Activities

* Modify so that different combinations of LEDs are illuminated.

* Determine the impact of not setting one of the LED bits in P1DIR (and why).

The impact of not setting one of the LED bits in P1DIR is that the leds wont turn on when called because the bits in P1DIR correspond directly to which LED to turn on. In my msp430 RED led is on p1.6 and green LED is on p1.0 so i had to modify led.h