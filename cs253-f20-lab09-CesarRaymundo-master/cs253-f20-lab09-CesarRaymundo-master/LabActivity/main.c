/*
* Author: Cesar Raymundo
* Date: October 28th, 2020
* Description: The program prompts the user to enter a playlist name, then after that they can manage 
* what they want to do with the playlist. They can add a song, change position of songs, remove a song, 
* output songs by a certain artist, and output the whole playlist.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PlaylistNode.h"

/*NewlineTrim: Remove the trailing newline
* character from strings returned from fgets.
*line - NULL terminated string
*/
void NewLineTrim(char *line)
{
   size_t linelength;

   /*validate parameter*/
   if (line == NULL)
   {
      return;
   }
   linelength = strlen(line);
   if (line[linelength - 1] == '\n')
   {
      line[linelength - 1] = '\0';
   }
}
/*
* BufferPurge: Remove all remaining characters 
*     from the input buffer.
*/
void BufferPurge(void)
{
   char c = getchar();
   while (c != '\n' && c != EOF)
   {
      c = getchar();
   }
}


int main(void)
{
   //Declaring variables for the program
   char playListName[25];
   char songName[50] = "";
   char artistName[50] = "";
   char id[50] = "";
   int sec;
   int sNum = 0;
   int position = 0;
   int newPosition = 0;
   int rc;
   bool foundNode;
   char option = ' ';
   int listSize;
   PlaylistNode *head;
   PlaylistNode *tail;
   PlaylistNode *current;
   PlaylistNode *nodeObj = NULL;
   PlaylistNode *beforeNode = NULL;
   PlaylistNode *afterNode = NULL;
   PlaylistNode *newBeforeNode = NULL;
   PlaylistNode *newAfterNode = NULL;

   //Entering the playlist name
   printf("Enter playlist's name:\n");
   fgets(playListName, 25, stdin);
   playListName[strlen(playListName) - 1] = '\0';

   do
   {
      //Prints the menu
      printf("\n%s PLAYLIST MENU\n", playListName);
      printf("a - Add song\n");
      printf("r - Remove song\n");
      printf("c - Change position of song\n");
      printf("s - Output songs by specific artist\n");
      printf("o - Output full playlist\n");
      printf("q - Quit\n\n");
      printf("Choose an option:\n");
      scanf(" %c", &option);
      //use switch case
      switch (option)
      {

      /*Add a song and create a node*/
      case 'a':

         printf("\nADD SONG\nEnter song's unique ID:\n");
         BufferPurge();
         fgets(id, 50, stdin);
         NewLineTrim(id);

         printf("Enter song's name:\n");
         fgets(songName, 50, stdin);
         NewLineTrim(songName);

         printf("Enter artist's name:\n");
         fgets(artistName, 50, stdin);
         NewLineTrim(artistName);

         printf("Enter song's length (in seconds):\n");
         scanf("%d", &sec);

         //printf("You entered: %s, %s, %s, %d\n\n", id, songName, artistName, sec);

         current = CreatePlaylistNode(id, songName, artistName, sec);
         if (current == NULL)
         {
            printf("Error: unable to create node\n");
            exit(1);
         }

         //check for fist
         if (head == NULL)
         {
            head = current;
            tail = current;
            listSize++;
         }
         else
         {
            rc = InsertPlaylistNodeAfter(tail, current);
            listSize++;
            tail = current;
            if (rc < 0)
            {
               printf("Error: unable to inser into list");
               PrintPlaylistNode(current);
               exit(1);
            }
         }
         printf("Song entered:\n");
         PrintPlaylistNode(current);

         break;

      /*Removing a song from the playlist*/
      case 'r':
         printf("\nREMOVE SONG\n");
         printf("Enter song's unique ID: ");
         scanf("%s", id);
         NewLineTrim(id);
         current = head;

         tail = NULL;

         do
         {
            if (strcmp(current->uniqueID, id) == 0)
            {
               foundNode = true;

               if (current == head)
               {

                  head = current->nextNodePtr;
               }
               else
               {

                  tail->nextNodePtr = current->nextNodePtr;
               }

               printf("\"%s\" removed.\n\n", current->songName);

               free(current);
            }
            else
            {
               tail = current;

               current = current->nextNodePtr;
            }

         } while ((foundNode == false) && (current != NULL));
         foundNode = false;
         break;

      /*Changing position of song*/
      case 'c':
         printf("\nCHANGE POSITION OF SONG\n");
         printf("Enter song's current position:\n");
         scanf("%d", &position);
         printf("Enter new position for song:\n");
         scanf("%d", &newPosition);

         current = head;

         if (position == 1){
            nodeObj = current;
            afterNode = current->nextNodePtr;
            current = current->nextNodePtr;

            sNum = 2;
         }else{

            sNum = 1;
         }

         if (newPosition == 1){

            newAfterNode = current;
         }

         while (current->nextNodePtr != NULL){
            if (sNum == position - 1){
               beforeNode = current;
               nodeObj = current->nextNodePtr;
            }

            if ((sNum == position) && (position != 1)){

               afterNode = current->nextNodePtr;
            }

            if ((sNum == newPosition - 1) && (newPosition < position)){

               newBeforeNode = current;

               newAfterNode = current->nextNodePtr;
            }

            if ((sNum == newPosition) && (newPosition > position)){

               newBeforeNode = current;

               newAfterNode = current->nextNodePtr;
            }

            current = current->nextNodePtr;

            sNum++;
         }

         if (position == 1){

            head = afterNode;
         }else{

            nodeObj->nextNodePtr = newAfterNode;
         }

         if (newPosition == 1){

            head = nodeObj;
         }else{

            newBeforeNode->nextNodePtr = nodeObj;
         }

         beforeNode->nextNodePtr = afterNode;

         printf("\"%s\" moved to position %d\n", nodeObj->songName, newPosition);
         break;

      /*Output of songs by specific artist*/
      case 's':
         printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");
         printf("Enter artist's name:");
         scanf(" %50[^\n]", artistName);

         current = head;
         sNum = 1;

         while (current != NULL)
         {

            if (strcmp(artistName, current->artistName) == 0)
            {

               printf("%d.\n", sNum);

               PrintPlaylistNode(current);
            }

            current = GetNextPlaylistNode(current);

            sNum++;
         }
         break;

      /*Ouput the full playlist*/
      case 'o':
         printf("%s - OUTPUT FULL PLAYLIST\n", playListName);

         if (head == NULL)
         {
            printf("Playlist is empty\n");
         }
         else
         {
            current = head;
            sNum = 1;
            while (current != NULL)
            {
               printf("%d.\n", sNum);
               PrintPlaylistNode(current);
               current = GetNextPlaylistNode(current);
               sNum++;
            }
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
