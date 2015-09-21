/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: cashreg.c
 *
 * PURPOSE: 
 *
 * CREATION DATE: 2013-04-18-10:39; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>

/* this program just behaves as a simple cash register. we input
   numbers to be added and it outputs the total sum of those
   "prices" */

int main(int argc, char *argv[]) {
  int i, x, total = 0;

  for (i=0; i < 5; i++) {
    printf ("Enter the item's price: ");
    scanf("%d",&x);
    total += x;
  }
  printf ("Yor total is $%d\n",total);
  return 0;
}
