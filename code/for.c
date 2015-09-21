/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: multtable.c
 *
 * PURPOSE:
 *
 * CREATION DATE: 2013-04-18-10:19; MODIFIED:
 *
 ******************************************************************************/

#include <stdio.h>

#define MAX_TABLE 10

int main(int argc, char *argv[]) {
  int m1, m2, r; /* m1, m2 are multipliers, r is the result */
  scanf("%d", &m2);

  /* Some sanity check */
  if (m2<0 && m2 >9) {
    printf("Number should be positive lower than 10. You entered %d", m2);
    return -1;
  }

  /* Some pretty-printing... */
  printf ("%2d times table\n",m2);
  printf ("==============\n");

  for (m1 = 1; m1 <= MAX_TABLE; m1++) {
    r = m1*m2;
    printf ("%2d x %2d = %3d\n",m1, m2, r);
  }

  return 0;
}
