#include <stdio.h>
#include <limits.h>

unsigned int ex = 1;

void tc1() {
     printf ("tc1\n");
     /* Note these are automatic conversions */
     int a = 5.6;
     printf ("%d\n",a); /* truncation */
     float b = 3/2;
     printf("%f", b);
     float c = 7;
     printf ("%f\n",c); /* to float */
}

void tc2(){
     printf ("tc2\n");
     /* it overflows  */
     unsigned int op3 = UINT_MAX + 2;
     printf ("Example %d: %d\n", ex ,op3);
     ex++;

}

void tc3() {
     /*  relevant conversion is from signed to unsigned */
     /* -1, when cast to unsigned will become the largest possible
	 value for that type -- e.g. with a 32-bit unsigned, it'll be
	 4,294,967,295. When you add 1 to that, the value "wraps
	 around" to 0. */
     printf ("tc3\n");
     signed int op1=-1;
     unsigned int op2=1;
     int res = op1 + op2;
     printf("%d\n",res);
     ex++;
}

void tc4() {
     printf ("tc4\n");
     /* In a two's complement representation -- which is by far the
      * most commonly used -- this conversion does not change the bit
      * pattern. That is, only low value bits will be count and high
      * order bits will be discarded. See section A6.2 of K&R*/
     unsigned int v = 2147479567; /*  1111111111111111111000000001111 */
     unsigned short w = v; /* 1111000000001111 */
     printf ("Example %d: %d\n",ex,w); /* 61455 = 1111000000001111 */
     ex++;

}

void tc5() {

     printf ("tc5\n");

     /* type conversion plus operator precedence */
     /* http://stackoverflow.com/questions/13663545/does-one-double-promote-every-int-in-the-equation-to-double */
     int a=1, b=2, c=3, e=4;
     double d = 4.;

     float res0 = b/c;
     printf ("res0 = %f\n",res0);

     double res1 = a + b / d + c; // equal to 4 or to 4.5?
     printf ("res0 =%f\n",res1);

     double res2 = (a + b)/d + c; // equal to 3 or to 3.75?
     printf ("res0 =%f\n",res2);

     double res3 = a/b + d; // equal to 4 or to 4.5?
     printf ("res0 =%f\n",res3);

    int res4 = e/b;
    printf ("res0 = %d\n",res4);
}

void tc6() {
  /*http://www.geeksforgeeks.org/integer-promotions-in-c/*/
  printf ("tc6\n");
  char a = 30, b = 40, c = 10;
  char d = (a * b) / c;
  printf ("%d ", d);
}

void tc7() {
     printf ("tc7\n");
/* This code shows two ancient and mystical techniques for calculating
   one. I call these techniques "iterative-adding" and
   "multiplying". And, just to show how messy this stuff is I do the
   multiplication twice. That's three separate calculations of the
   same thing. Naturally we get three different results, and only one
   of them is the unity we were seeking:

   sum = 1.000000119209290, mul = 1.000000000000000, mul2 = 1.000000014901161

   Disclaimer: the results you get will depend on your compiler and
   your compiler settings, which actually helps make the point.

   http://www.altdevblogaday.com/2012/02/22/comparing-floating-point-numbers-2012-edition/
*/

 float f = 0.1f;
    float sum;
    sum = 0;

    for (int i = 0; i < 10; ++i)
	sum += f;
    float product = f * 10;
    printf("sum = %1.15f, mul = %1.15f, mul2 = %1.15f\n",
	   sum, product, f * 10 /*our compiler knows*/);
}

void tc8() {

/* unsigned to signed conversion for values that don't fit in the
 * positive values of the signed type is implementation defined. Here,
 * for your particular compiler, probably it turns out to be -1 and
 * that then converted to unsigned is UINT_MAX.
 */
  printf ("tc8\n");
unsigned int x = 0xDEADBEEF;
unsigned short y = 0xFFFF;
if (x > (signed short) y)
     printf("True\n");
else
     printf ("False\n");

}

void tc9() {
     printf ("tc9\n");
     double l = 12.2;
     double r = .1;
     double t = 1.5;

     double res = (int)((l-(2*r))/(t*2));
     printf ("%f\n",res);

}

void tc10() {
  /* Exemplification of an int that cannot be represented in a
     float */
  printf ("tc10\n");
  int a=16777217; /* $2^{mantissa+1}+1$, mantissa is 24 bits */
  float b = a;
  printf ("%f\n",b); /* 16777216.000000 (1 less!!) */
}

void tc11() {
  /* Exemplification of an int that cannot be represented in a
     float */
  printf ("tc11\n");
  int a=16777218; /* $2^{mantissa+1}+1$, mantissa is 24 bits */
  float b = a;
  printf ("%f\n",b); /* 16777218.000000 (=!!) */
}

void tc12() {
  printf ("tc12\n");
  double da = 3.3;
  double db = 3.3;
  double dc = 3.4;
  int result = (int)da + (int)db + (int)dc; //result == 9
  double result2 = da + db + dc; //result == 10.0000
  printf ("%d\n",result);
  printf ("%f\n",result2);
  //if implicit conversion would be used (as if result = da + db +
  //dc), result would be equal to 10
}

int main(void)
{

  /* Type conversion examples */
     tc1();

     tc2();

     tc3();

     tc4();

     tc5();

     tc6();

     tc7();

     tc8();

     tc9();

     tc10();

     tc11();

     tc12();

/* What happens then with the following?
  int + float = ?
  int * float = ?
  float * int = ?
  int / float = ?
  float / int = ?
  int / int = ?
  int ^ float = ?
*/
     return 0;
}

/*
If either is      long          double the other is promoted to      long          double
If either is                    double the other is promoted to                    double
If either is                    float  the other is promoted to                    float
If either is long long unsigned int    the other is promoted to long long unsigned int     (C99 only)
If either is long long          int    the other is promoted to long long          int     (C99 only)
If either is long      unsigned int    the other is promoted to long      unsigned int
If either is long               int    the other is promoted to long               int
if either is           unsigned int    the other is promoted to           unsigned int
If either is                    int    the other is promoted to                    int
Both operators are promoted to int
*/
