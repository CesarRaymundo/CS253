/*
 * Author: Cesar Raymundo 
 * Date: 9/9/20
 * Description: This shows how to use
 * scanf with given data from user and 
 * how to print it various way
 */

#include <stdio.h>

int main(void) {
   int    userInt;
   double userDouble;
   char userChar;
   char userString[80];
   // FIXME: Define char and string variables similarly
   
   printf("Enter integer:\n");
   scanf("%d", &userInt);

   printf("Enter a double:\n");
   scanf("%lf",&userDouble);

   printf("Enter a character:\n");
   scanf(" %c",&userChar);

   printf("Enter a string:\n");
   scanf("%s",userString);

   // FIXME (1): Finish reading other items into variables, then output the four values on a single line separated by a space
   printf("%d, %lf, %c, %s\n", userInt, userDouble, userChar, userString);
   
   // FIXME (2): Output the four values in reverse
    printf("%s, %c, %lf, %d\n", userString, userChar, userDouble, userInt);
   
   // FIXME (3): Cast the double to an integer, and output that integer
   printf("%lf cast to an integer is %d\n", userDouble, (int)userDouble);
   return 0;
}