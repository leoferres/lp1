/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: guess1.c
 *
 * PURPOSE: Computer thinks a number from 1 to 10, we humans have to
 * guess it. Obviously, it will take the ceiling of lg 10 attempts
 * (3.01029995664), so we'll put 4 attempts here.
 *
 * SOURCE: Minor modifications of
 * http://www.c.happycodings.com/Miscellaneous/code19.html
 *
 * CREATION DATE: 2013-04-02-16:44; MODIFIED: 
 *
 ******************************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int mine = 0;
  int yours = 0;
  
  srand(time(NULL));
  mine = 1 + rand() % 10;

  int attempts = 4; /* how many "lives" I have */

  while (attempts) {
      printf("Guess my number, 1 - 10: ");
      scanf("%d", &yours);
      
      if(yours < mine)
	  printf("Your guess was to low\n");
      else if(yours > mine)
	  printf("Your guess was to high\n");
      else {
	  printf("Yesss ... you got it!\n");
	  return 0;
      }
      attempts--; /* using up "lives" */
  }
  return 0;
}