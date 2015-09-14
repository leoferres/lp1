/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: case1.c
 *
 * PURPOSE: Using case to elicit options from user
 *
 * CREATION DATE: 2013-04-03-09:22; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int input;
 
  printf( "1. Play game\n" );
  printf( "2. Load game\n" );
  printf( "3. Play multiplayer\n" );
  printf( "4. Exit\n" );
  printf( "Selection: " );
  scanf( "%d", &input );
  switch ( input )  {
  case 1:  /* Note the colon, not a semicolon */
    printf("Playing the game\n");
    break; /* Note the break, switch statements "fall through", break
	    * exits from switch */
  case 2:          
    printf("Loading the game\n");
    break;
  case 3:         
    printf("Playing multiplayer\n");
    break;
  case 4:        
    printf( "Thanks for playing!\n" );
    break;
  default:            
    printf( "Bad input!\n" );
    break;
  }

  /* break gets us here */

  puts("I reached the break!");

return 0;
}
