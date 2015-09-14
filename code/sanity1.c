/*******************************************************************************
 *    This program by L A Ferres is in the public domain and freely copyable.
 *    If you find any bugs, please report them immediately to: leo@inf.udec.cl
 *******************************************************************************
 *
 * FILE NAME: sanity1.c
 *
 * PURPOSE: My favorite use of if expressions is to sanitize input. I
 * don't know. I just like it a lot. Here are some common examples of
 * input sanitation.
 *
 * CREATION DATE: 2013-04-02-18:25; MODIFIED:
 *
 ******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {

  /* EXAMPLE 1 */


  if (argc < 2 ) {
    puts("Write in some arguments!");
    puts("Usage: sanity1 arg1 arg2 [arg3] [arg4]");
    return -1;
  } else if (argc > 4) {
    puts("Whew. Too many arguments.");
    puts("Usage: sanity1 arg1 arg2 [arg3] [arg4]");
    return -2;
  }

  puts("I'm doing very interesting stuff with your args now!");

  puts("<snip><snip><snip><snip><snip><snip>");

  /* EXAMPLE 2 */

  puts("Are you sure you want to delete all files in this computer? (y or n) ");
  char c = getchar();
  if(c=='y') {
    puts("brrrrrrr. All files deleted.");
  } else {
    /* notice we don't really ask for no. Everything else is a "no" */
    puts("Files kept.");
  }

  puts("<snip><snip><snip><snip><snip><snip>");


  /* EXAMPLE 3 */

  int num = 0;
  puts("Please enter a number from 1 to 10");
  scanf("%d",&num);

  /* it would be a bad idea to just run this code as is... what if
     someone enters the wrong number? Program goes boom!
  */

  /* is there another way to write this code? */
  if (num > 0 && num < 11) {
    puts("Ok.");
  } else {
    puts("You're dumb.");
  }





  return 0;
}
