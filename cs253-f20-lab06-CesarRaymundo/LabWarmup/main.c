/*
* Author: Cesar Raymundo
* Date: October 5th, 2020
* Description: The program prompts the user to enter 5 weights and store them to an array.
* we then print out all those weights along with total, average, and max weight.
*/

#include <stdio.h>
const int TEAM_SIZE = 5;
int main(void) {

double maxWeight = 0.0;
double totalWeight = 0.0;

/* Declare array of 5 doubles */
double teamWeights[TEAM_SIZE];

   /* Read weights and store in array */
   for (int i = 0; i< TEAM_SIZE; i++){
   printf("Enter weight %d: ", (i + 1) );
   scanf("%lf", &teamWeights[i]);
}
   /* Display weights on a single line */
   printf("You entered: ");
   for (int i = 0; i< TEAM_SIZE; i++){
      printf("%0.2lf ", teamWeights[i]);
   }
   printf("\n");
    printf("\n");

   /* Total weight*/
   for (int i = 0; i < TEAM_SIZE; i++){
      totalWeight += teamWeights[i];
   }
   /* Calculate maxWeight */
    for (int i = 0; i < TEAM_SIZE; i++){
       maxWeight = (teamWeights[i] > maxWeight)?teamWeights[i]:maxWeight;
    }
   
   /* Printing out the total, average, and max weight */
   printf("Total weight: %0.2lf\n", totalWeight);
   printf("Average weight: %0.2lf\n", totalWeight/TEAM_SIZE);
   printf("Max weight: %0.2lf\n", maxWeight);
   return 0;
}