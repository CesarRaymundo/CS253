#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ContactNode.h"
 
ContactNode* CreateContactNode(char name[], char phoneNum[]){
   ContactNode * thisNode = (ContactNode *) malloc(sizeof(ContactNode));

 
   if(thisNode == NULL){
      return NULL;
   }

   strncpy(thisNode->contactName, name,CONTACT_FIELD_SIZE);
   strncpy(thisNode->contactPhoneNum, phoneNum,CONTACT_FIELD_SIZE);
   thisNode->nextNodePtr = NULL;

   return thisNode;
}

int InsertContactAfter(ContactNode* nodeInList, ContactNode* newNode){
   ContactNode* tmpNext = NULL;

   /*Validates parameters*/
   if(nodeInList == NULL || newNode == NULL){
      return -1;
   }

   tmpNext = nodeInList->nextNodePtr;
   nodeInList->nextNodePtr = newNode;
   newNode->nextNodePtr = tmpNext;

   return 0;
}
ContactNode* GetNextContact(ContactNode* nodeInList){
   /* Validate parameter */
   if(nodeInList == NULL){
      return NULL;
   }
   return nodeInList->nextNodePtr;
   
}
void PrintContactNode(ContactNode* thisNode){
     /* Validate parameter */
   if(thisNode == NULL){
      return; 
   }
   printf("Name: %s\n", thisNode->contactName);
   printf("Phone Number: %s\n", thisNode->contactPhoneNum);

   return;
}
void DestroyContactNode(ContactNode* thisNode){
 /* Validate parameter */
   if(thisNode == NULL){
      return; 
   }
   free(thisNode);
}

