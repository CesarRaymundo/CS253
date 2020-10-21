/*
* Author: Cesar Raymundo
* Date: October 16, 2020
* Description: implements ItemToPurchase and uses user input to make
* make an item with its quantitiy and cost and the total cost of the item.
* It also prints out these items and the total cost of them combined
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ItemToPurchase.h"
/*
* BufferPurge: Remove all remaining characters 
*     from the input buffer.
*/
void BufferPurge(void){
   char c = getchar();
while(c != '\n' && c != EOF) {
   c = getchar();
   }
}

int main(void) {
 /* Declare variables */
 int rc = 0;
 ItemToPurchase item1; 
 ItemToPurchase item2;

/* Intializes items */
rc = MakeItemBlank(&item1);
if(rc <0 ){
   printf("Error: Unable to intialize item1\n");
   exit(1);
}

rc = MakeItemBlank(&item2);
if(rc <0 ){
   printf("Error: Unable to intialize item2\n");
   exit(1);
}

/* Setup first item */
printf("Item 1\n");
printf("Enter the item name: ");
scanf("%79[^\n]s", item1.itemName);
BufferPurge();
printf("Enter the item price: ");
/* Reads user input and validates */
while (scanf("%d", &item1.itemPrice) < 1){
printf("Please enter an integer value\n");
BufferPurge();
}
BufferPurge();
printf("Enter item quantity: ");
/* Reads user input and validates */
while(scanf("%d", &item1.itemQuantity) < 1){
printf("Please enter an integer value\n");
BufferPurge();
}
BufferPurge();

/* Setup second item */
printf("\n\nItem 2\n");
printf("Enter the item name: ");
scanf("%79[^\n]s", item2.itemName);
BufferPurge();
printf("Enter the item price: ");
/* Reads user input and validates */
while(scanf("%d", &item2.itemPrice) < 1){
printf("Please enter an integer value\n");
BufferPurge();
}
BufferPurge();
printf("Enter item quantity: ");
/* Reads user input and validates */
while(scanf("%d", &item2.itemQuantity) < 1){
printf("Please enter an integer value\n");
BufferPurge();
}
BufferPurge();

/* Calculate total cost */
int totalCost = 0;
totalCost+= item1.itemQuantity * item1.itemPrice;
totalCost+= item2.itemQuantity * item2.itemPrice;
/* Display first item */
printf("\nTotal Cost:\n");
PrintItemCost(item1);
PrintItemCost(item2);   
printf("Total: $%d\n", totalCost);


   return 0;
}