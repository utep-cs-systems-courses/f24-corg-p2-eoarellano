#include <msp430.h>
#include "switches.h"

void switch_init()
{
  P1REN |= SWITCHES;  /* enables resistors for switches */
  P1IE |= SWITCHES;   /* enable interrupts from switches */
  P1OUT |= SWITCHES;  /* pull-ups for switches */
  P1DIR &= ~SWITCHES; /* set switches' bits for input */
}

void switch_interrupt_handler()
{
  char p1val = P1IN;
  P1IES |= (p1val & SWITCHES);  // if switch up, sense falling edge
  P1IES &= (p1val | ~SWITCHES); // if switch down, sense rising edge

  if (~p1val & SWITCHES)
  {
    state_advance();
  }
}

void __interrupt_vec(PORT1_VECTOR) Port_1()
{
  if (P1IFG & SWITCHES)
  {                             // Check if any switch was pressed
    P1IFG &= ~SWITCHES;         // Clear interrupt flag
    switch_interrupt_handler(); // Handle switch interrupt
  }
}
