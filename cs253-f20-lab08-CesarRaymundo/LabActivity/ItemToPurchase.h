#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#define MAX_ITEM_NAME_SIZE 80
#define MAX_ITEM_DESCRIPTION_SIZE 150

/* Define itemToPurchase struct */
struct itemToPurchase
{
    char itemName[MAX_ITEM_NAME_SIZE];
    char itemDescription[MAX_ITEM_DESCRIPTION_SIZE];
    int itemPrice;
    int itemQuantity;
};

/* Define itemToPurchase type */
typedef struct itemToPurchase ItemToPurchase;

/* 
* MakeItemBlank: intailize the field in the specified ItemToPurchace struct 
* item - Pointer to ItemToPurchase object
* return - 0 on success, and -1 on error
*/
int MakeItemBlank(ItemToPurchase * itemPtr);

/*
* PrintItemCost: Display item cost
*   BY printing to stdout
* item - ItemToPurchase object to be displayed
*/
void PrintItemCost(ItemToPurchase item);

/*
* PrintItemDescription: Display item description
*   BY printing to stdout
* item - ItemToPurchase object to be displayed
*/
void PrintItemDescription(ItemToPurchase item);
#endif