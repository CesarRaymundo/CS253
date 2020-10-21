/*
* Author: Cesar Raymundo
* Date: October 5th, 2020
* Description: The program prompts the user to enter 5 player's jersey number and their rating and stores them
* into two different arrays. With the given values, the user is prompt to a menu that gives them the options to update
* the information they gave of the players, print the most current roster, and see other players ratings.
*/
#include <stdio.h>
const int TEAM_SIZE = 5;

int main(void)
{
   /*Declaring variables*/
   int jersey[TEAM_SIZE];
   int rating[TEAM_SIZE];
   char option = ' ';
   int jer = 0, rate = 0, index, k = 0;

   /* Reads player's jersey number and rating and stores them to their own arrays.*/
   for (int i = 0; i < TEAM_SIZE; i++)
   {
      printf("Enter player %d's jersey number:\n", (i + 1));
      scanf("%d", &jersey[i]);

      printf("Enter player %d's rating:\n", (i + 1));
      scanf("%d", &rating[i]);
      printf("\n");
   }
   
   /*Prints out the roster with the given values*/
   printf("ROSTER\n");

   for (int i = 0; i < TEAM_SIZE; i++)
   {
      printf("Player %d -- Jersey number:%d, Rating:%d\n", i + 1, jersey[i], rating[i]);
   }
   printf("\n");
   int i = 0;
   
   /* Menu with options that with given option to do with the array of player */
   do
   {
      //Prints the menu
      printf("\nMENU\n");
      printf("u - Update player rating\n");
      printf("a - Output players above a rating\n");
      printf("r - Replace player\n");
      printf("o - Output roster\n");
      printf("q - Quit\n");
      printf("\nChoose an option:\n");
      scanf(" %c", &option);
      //use switch case
      switch (option)
      {
      
      /*Updates the player's rating.*/
      case 'u':
         //read player's jersey number and new rating
         printf("\nEnter a jersey number:\n");
         scanf("%d", &jer);
         printf("Enter a new rating for a player:\n");
         scanf("%d", &rate);
         //search for the player
         for (int i = 0; i < TEAM_SIZE; i++)
         {
            if (jersey[i] == jer)
               break;
         }
         //update the ratings
         index = i;
         rating[index] = rate;
         break;
      
      /*Output players above a rating*/
      case 'a':
         //read a rating
         printf("\nEnter a rating:\n");
         scanf("%d", &k);
         //print the players above a rating
         printf("\nABOVE %d\n", k);
         for (int i = 0; i < TEAM_SIZE; i++)
         {
            if (rating[i] > k)
            {
               printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey[i], rating[i]);
            }
         }

         break;
      
      /*Replace a player*/
      case 'r':
         //read the jersey number
         printf("\nEnter a jersey number:\n");
         scanf("%d", &jer);
         //search for the player
         int p;
         for (p = 0; p < TEAM_SIZE; p++)
         {
            if (jersey[p] == jer)
               break;
         }
         index = p;
         //read new player's jersey number and rating
         printf("Enter a new jersey number:\n");
         scanf("%d", &jer);
         jersey[index] = jer;
         printf("Enter a rating of new player:\n");
         scanf("%d", &rate);
         //replace the player
         rating[index] = rate;
         break;
      
      /* Outputs the current roster*/
      case 'o':
         printf("\nROSTER\n");
         for (int i = 0; i < TEAM_SIZE; i++)
         {
            printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey[i], rating[i]);
         }
         break;
      
      /*Quits the program*/
      case 'q':
         break;
      
      default:
         break;
      }
   } while (option != 'q');

   return 0;
}