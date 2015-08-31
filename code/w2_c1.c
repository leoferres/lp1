/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: signedness.c
 *
 * PURPOSE: Shows weird things that happen when dealing with
 * floats. This is just sample code, you're not supposed to understand
 * this at this point. Only know that dragons may creep up.
 *
 * CREATION DATE: 2013-04-04-16:13; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>
#include <math.h>

/* See
   http://hal.archives-ouvertes.fr/docs/00/28/14/29/PDF/floating-point-article.pdf
   for a nice treatment of the issue. */
int main(int argc, char *argv[]) {

/* IEEE 754 floating point numbers can represent positive or negative
   infinity, and NaN (not a number).  */

  printf ("%f\n",1.0f/.0f); /* division by zero, no way to evenly
			       distribute 10 cookies to nobody; in
			       IEEE returns positive infinity */
  printf ("%f\n",log(0));   /* no power can give an answer of zero, in
			       IEEE log 0 is negative infinity */
  printf ("%f\n",sqrt(-1)); /* cannot be represented in R, IEEE nan */

  float f1 = 1234.123412345678f;
  printf ("%f\n",f1);    /* cannot be represented exactly */
  printf ("%8.9f\n",f1); /* worse, :) more precision is less
			    precision */
/* 
   Explanation:
   Consider 1234.12345678
  
   It's easy enough to deal with 1234. Here are the bits: 10011010010

   So let's try to deal with 0.12345678, using binary notation.

   So 0.1 (binary) is 0.5 (decimal), 0.01 (binary) is 0.25 (decimal), and
   so on.

   0.1 = 1/2 = 0.5 - too large
   0.01 = 1/4 = 0.25 - too large
   0.001 = 1/8 = 0.125 - too large
   0.0001 = 1/16 = 0.0625 - too small
   0.00011 = 3/32 = 0.09375 - too small
   0.000111 = 7/64 = 0.109375 - too small
   0.0001111 = 15/128 = 0.1171875 - too small
   0.00011111 = 31/256 = 0.12109375 - too small
   0.000111111 = 63/512 = 0.123046875 - too small
   0.0001111111 = 127/1024 = 0.1240234375 - too large
   0.00011111101 = 253/2048 = 0.12353515625 - too large
   0.000111111001 = 505/4096 = 0.123291015625 - too small
   0.0001111110011 = 1011/8192 = 0.1234130859375 - too small
   0.00011111100111 = 2023/16384 = 0.12347412109375 - too large
   0.000111111001101 = 4045/32768 = 0.123443603515625 - too small
   0.0001111110011011 = 8091/65536 = 0.1234588623046875 - too large

   So far, we've used 16 bits on this. Keep on calculatin', and find out
   how many bits you need if you're to get an *exact* representation of
   0.12345678. You might well be surprised by the result.
*/
  
  printf ("%0.23f\n",0.1); /* at some point, it starts accumulating
			      error */
  float f = 0.1f;
  float sum;
  sum = 0;

  /* Iterative product. Introduces error after ~6 decimal places. */
  for (int i = 0; i < 10; i++)
    sum +=f;
  
  float product = f*10;
  printf ("sum=%1.15f, mul1=%1.15f\n", sum, product);

  if (sum==product) {
    printf ("Same!\n");
  } else {
    printf ("Not same!\n");
  }
  
  return 0;
}
