#include <stdio.h>
 
int main() {
   char key;
 
   printf("Press any key or E to exit:\n");
   while(1) {
     scanf("%c", &key);
     // if E or e, exit
     if (key == 'E' ||  key == 'e')
       break;
   }
   printf("Goodbye!\n");
   return 0;
}
