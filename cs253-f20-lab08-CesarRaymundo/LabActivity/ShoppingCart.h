
#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"

#define MAX_CUSTOMER_NAME 50
#define MAX_DATE 50

/* Define ShoppingCart struct */
struct shoppingcart{
    char customerName[MAX_CUSTOMER_NAME];
    char currentDate[MAX_DATE];
    ItemToPurchase cartItems[10];
    int cartSize;
};

/* Define ShoppingCart type */
typedef struct shoppingcart ShoppingCart;

/* 
* AddItem: Adds an item to cartItems array 
* item - Pointer to ItemToPurchase object
* cart - Pointer to ShoppingCart object
* return - ShoppingCart object.
*/
ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);

/* 
* RemoveItem: Removes an item to cartItems array 
* name - Pointer to intemName from ItemToPurchase
* cart - Pointer to ShoppingCart object
* return - ShoppingCart object.
*/
ShoppingCart RemoveItem(char name[], ShoppingCart cart);

/* 
* ModifyItem: Modifies an item's description, price, and/or quantity. 
* item - Pointer to ItemToPurchase object
* cart - Pointer to ShoppingCart object
* return - ShoppingCart object.
*/
ShoppingCart ModifyItem(char item[50], ShoppingCart cart);

/* 
* GetNumItemsInCart: Gets the number of items in the current ShoppingCart object 
* cart - Pointer to ShoppingCart object
* return - ShoppingCart object.
*/
int GetNumItemsInCart(ShoppingCart cart);

/* 
* GetCostOfCart: Determines the total cost of item in the current ShoppingCart object 
* cart - Pointer to ShoppingCart object
* return - ShoppingCart object.
*/
int GetCostOfCart(ShoppingCart cart);

/* 
* PrintTotal: Display total objects in cart by printing to stdout 
* cart - ShoppingCart object to be displayed
*/
void PrintTotal(ShoppingCart cart);

/* 
* PrintDescription: Display each item's description in cart by printing to stdout 
* cart - ShoppingCart object to be displayed
*/
void PrintDescriptions(ShoppingCart cart);



#endif