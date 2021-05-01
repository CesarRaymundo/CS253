/**
 * Author: Cesar Raymundo
 * Date: October, 24 2020
 * Description: File uses ContactNode file to create Contacts in Singlelinked
 * list. Uses user entry to create contacts and then stores and prints out the 
 * contacts
 **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ContactNode.h"

void NewlineTrim(char * line);

int main(void) {
   char fullName[50] = "";
   char phoneNum[50] = "";
   int rc;
   const int NUM_CONTACTS = 3;

   ContactNode * headNode = NULL;
   ContactNode * tailNode = NULL;
   ContactNode * currentNode = NULL;

   /*Contact entry loop*/
   for(int i = 0; i<NUM_CONTACTS; i++){
      
      printf("Person %d\n", i+1);
      printf("Enter name:\n");
      fgets(fullName, 50, stdin);
      NewlineTrim(fullName);

      printf("Enter phone number:\n");
      fgets(phoneNum, 50, stdin);
      NewlineTrim(phoneNum);

      printf("You entered: %s, %s\n\n", fullName, phoneNum);

      /* Create ContactNode and verify*/
      currentNode = CreateContactNode(fullName, phoneNum);
      if(currentNode == NULL){
         printf("Error: Unable to create node...\n");
         printf("Name: %s\n", fullName);
         printf("Phone Number: %s\n", phoneNum);
         exit(1);
      }

      /* Check if this is the first node in the list */
      if(headNode == NULL){
         headNode = currentNode;
         tailNode = currentNode;
      } else{
         /* Insert ContactNode after tailNode and verify */
         rc = InsertContactAfter(tailNode, currentNode);
         if(rc < 0){
            printf("Error: Unable to insert the node in the list...\n");
            PrintContactNode(currentNode);
            exit(1);
         }
           tailNode = currentNode;
      }
   }

   //Print contact list
   printf("CONTACT LIST]\n");
   currentNode = headNode;
   while(currentNode != NULL){
      PrintContactNode(currentNode);
      currentNode = GetNextContact(currentNode);
      printf("\n");
   }

   /*Cleanup the node in the list*/
   currentNode = headNode;
   ContactNode * nextNode;
   while(currentNode != NULL){
      nextNode = GetNextContact(currentNode);
      DestroyContactNode(currentNode);
      currentNode = nextNode;
   }
   return 0;
}


/*NewlineTrim: Remove the trailing newline
* character from strings returned from fgets.
*line - NULL terminated string
*/
void NewLineTrim(char * line){
   size_t linelength;

   /*validate parameter*/
   if(line == NULL){
      return;
   }
   linelength = strlen(line);
   if(line[linelength - 1] == '\n'){
      line[linelength-1] = '\0';
   }
}
