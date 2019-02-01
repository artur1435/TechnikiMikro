#include <msp430.h>
	

	char stansw;
	

	int main(void)
	{
	  WDTCTL = WDTPW + WDTHOLD;                 
	  P1DIR |= BIT6 + BIT0;
	  P1OUT |= BIT3;
	  P1REN |= BIT3;
	  
	  while(1)
		{
		volatile unsigned int i;
		stansw = P1IN & BIT3;
		if (stansw==0)
			{
			P1OUT ^= BIT6;
			}
			else
			{
			P1OUT ^= BIT0;
			}
		i=50000;
		do(i--);
		while(i!=0);
		}
	}