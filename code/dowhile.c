/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: dowhile.c
 *
 * PURPOSE: 
 *
 * CREATION DATE: 2013-04-18-11:00; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {

  /* in this case, we see how the while loop never gets executed (the
     condition is evaluated before executing the iteration), while in
     the do-while case, at least the first iteration will be executed
     before evaluating the while condition. Thus, we expect this
     program to output "executing do-while" */

  int a = 0;

  while(a) {
    printf ("executing while.\n");
  }

  do
    {
      printf ("executing do-while.\n");      
    } while (a);

  return 0;
}
