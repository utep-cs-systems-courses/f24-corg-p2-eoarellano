#ifndef led_included
#define led_included

#define LED_GREEN BIT0            // P1.0
#define LED_RED BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();		/* initialize LEDs */
void siren();
void both_leds_on();
void green_led_on();
void red_led_on();

#endif // included
