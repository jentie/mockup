/*
 *	mockup - compile and run Arduino sketch on PC for debugging
 *
 *	jentie, 2015-05-18
 *
 *	MIT license, see file LICENSE for more information
 */


#include <stdio.h>
#include <sys/time.h>

#include "mockup.h"



struct timeval t_start;


void
initialize ()
{
  gettimeofday (&t_start, 0);
}


/*
 *	Arduino functions
 */

unsigned long
millis ()
{
  struct timeval t_now;

  gettimeofday (&t_now, 0);

  return ((t_now.tv_sec - t_start.tv_sec) * 1000 +
	  (t_now.tv_usec - t_start.tv_usec) / 1000);
}

unsigned long
micros (void)
{
  struct timeval t_now;

  gettimeofday (&t_now, 0);

  return ((t_now.tv_sec - t_start.tv_sec) * 1000000 +
	  (t_now.tv_usec - t_start.tv_usec));
}

void
delay (unsigned long ms)
{
  unsigned long start = millis ();
  while (millis () - start < ms)
    {
    }				// delay is blocking
}


void
pinMode (int pin, char mode)
{
  printf ("pinMode %i-%c\n", pin, mode);
}

void
digitalWrite (int pin, int value)
{
  printf ("digitalWrite %i-%i\n", pin, value);
}

int
digitalRead (int pin)
{				// dummy, not implemented yet
  printf ("digitalRead - warning\n");
  return HIGH;
}


void analogWrite(pin, value) {
	
  printf ("analogWrite %i-%i\n", pin, value);
}
  
  
int analogRead(int pin) {
    						// dummy, not implemented yet
    printf ("analogRead - warning\n");
    return 0;	
}




long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/*
 *	main loop, call Arduino sketch
 */

void
main ()
{

  initialize ();		// internal housekeeping

  setup ();			// arduino sketch setup()

  for (;;)
    loop ();			// arduino sketch loop()

}
