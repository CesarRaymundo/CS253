/**
 * Author: CesarRaymundo  
 * Date:9/9/20
 * Description: The purpose of this class is 
 * show how to use math functions to find the 
 * solution to the probelm given below.
 */
#include <stdio.h>
#include <math.h>                  // Note: Needed for math functions in part (3)

int main(void) {
   double wallHeight;
   double wallWidth;
   double wallArea;
   double gallonsNeeded;

   printf("Enter wall height (feet):\n");
   scanf("%lf", &wallHeight);
   // FIXME (1): Prompt user to input wall's width
   printf("Enter wall width(feet):\n");
   scanf("%lf", &wallWidth);               
   
   // Calculate and output wall area
   wallArea = wallHeight * wallWidth;                 // FIXME (1): Calculate the wall's area
   
 // FIXME (1): Finish the output statement
   printf("Wall area: %.2lf\n", wallArea);
   // FIXME (2): Calculate and output the amount of paint in gallons needed to paint the wall
   gallonsNeeded = wallArea / 350.0;
   printf("Paint needeed: %.2lf gallons\n", gallonsNeeded);
   // FIXME (3): Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
   printf("Cans needed: %.0lf can(s)\n", gallonsNeeded,round(gallonsNeeded));
   return 0;
}