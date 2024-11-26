#ifndef switches_included
#define switches_included

// #define SW1 BIT0		/* switch1 on top board is p2.0 */
// #define SW2 BIT1		/* switch2 on top board is p2.1 */
// #define SW3 BIT2		/* switch3 on top board is p2.2 */
// #define SW0 BIT3		/* switch4 on bottom board is p1.3 */
// #define SW4 BIT4        /* switch4 on top board is p2.4 */
// #define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

#define SW1 BIT0		/* switch1 is p1.3 */
#define SWITCHES SW1        /* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

#endif // included