/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: case2.c
 *
 * PURPOSE: Case statement when fall-through is ok
 *
 * CREATION DATE: 2013-04-03-09:38; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {

  /* int i; */

  char i =getchar();

  //  scanf("%d",&i);

  printf ("%d\n", i);

  switch (i) {

  case 'A': case 'a':
  case 'E': case 'e':
  case 'I': case 'i':
  case 'O': case 'o':
  case 'U': case 'u':
    puts ("A vowel!");
    break;
  default:
    puts ("Not a vowel!");
  }
  
  return 0;
}
