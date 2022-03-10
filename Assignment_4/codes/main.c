#include <avr/io.h>
#include <util/delay.h>

 
int main (void)
{
	
	
  
 
 DDRD   |= 0b00000000;



 DDRB   |= ((1 << DDB5));
 int i,p,q,r,s,LHS,RHS;
  while (1) {

     i = PIND;
 
	   
     p= i & 0b00000100;
     q= i & 0b00001000;
     r= i & 0b00010000;
     s= i & 0b00100000;
	LHS = (!p&&!q)&&(r&&!s)&&(!p&&s)&&(q&&r);
	RHS = !((!(!p&&!q))&&(!(p&&!s))&&(!(p&&!s))&&(!(q&&r)));

if(LHS==RHS)
PORTB = ((0 <<  PB5));
else
PORTB = ((1 <<  PB5));

  }

  /* . */
  return 0;

}
