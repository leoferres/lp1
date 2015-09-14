/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: case0.c
 *
 * PURPOSE: show switch/case fall
 * through. http://www.tutorialspoint.com/ansi_c/switch_statement_examples.htm
 *
 * CREATION DATE: 2013-04-03-09:27; MODIFIED: 
 *
 ******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
  int  Grade = 'A';

     switch( Grade )
     {
        case 'A' : printf( "Excellent\n" );
        case 'B' : printf( "Good\n" );
        case 'C' : printf( "OK\n" );
        case 'D' : printf( "Mmmmm....\n" );
        case 'F' : printf( "You must do better than this\n" );    
        default  : printf( "What is your grade anyway?\n" );
     }	
  return 0;
}
