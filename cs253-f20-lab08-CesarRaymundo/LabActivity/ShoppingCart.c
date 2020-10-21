#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
    cart.cartItems[cart.cartSize] = item;
    cart.cartSize = cart.cartSize + 1;
    return cart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart){
char itemFound = 'n';

for(int i =0; i<cart.cartSize; i++){
    if(strcmp(name, cart.cartItems[i].itemName) == 0){
        itemFound = 'y';
        for (int j = i; j<cart.cartSize; j++){
            cart.cartItems[j] = cart.cartItems[j+1];
        }
    }
}
if(itemFound == 'y'){
    cart.cartSize = cart.cartSize - 1;
    printf("Item removed!\n");
}
//If item cannot be found
if(itemFound == 'n'){
    printf("Item was not found in cart.\n");
}
return cart;
}

ShoppingCart ModifyItem(char item[50], ShoppingCart cart){
    int quantity;
    char itemFound = 'n';

    printf("Enter the new quantity:\n");
    scanf("%d", &quantity);

    for (int i = 0; i < cart.cartSize; ++i) {
        if (strcmp(item, cart.cartItems[i].itemName) == 0) {
        itemFound = 'y';
        cart.cartItems[i].itemQuantity = quantity;
        }
    }
    
    if (itemFound == 'n') {
        printf("Item not found in cart. Nothing modified.\n");
    }
    else{
        printf("Item quantity changed!\n");
    }
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart){
return cart.cartSize;
}

int GetCostOfCart(ShoppingCart cart){
    int total = 0;
    int temp = 0;
    for(int i =0; i<cart.cartSize; i++ ){
        temp = (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
        total = total + temp;    
    }
return total;
}

void PrintTotal(ShoppingCart cart){
int total = 0;
int numItems = 0;

for(int i = 0; i<cart.cartSize; i++){
    numItems += cart.cartItems[i].itemQuantity;
}

printf("%s\'s Shopping Cart - %s\n",cart.customerName, cart.currentDate);
printf("Number of items: %d\n", numItems);

if(cart.cartSize == 0){
    printf("Shopping CART IS EMPTY\n");
    printf("Total: 0\n");
}
else{
    for(int i = 0; i<cart.cartSize; i++){
    printf("%s %d @ $%d = $%d\n", 
    cart.cartItems[i].itemName, 
    cart.cartItems[i].itemQuantity, 
    cart.cartItems[i].itemPrice, 
    (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice));
    total = total +  (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
        }
printf("\nTotal: $%d\n", total);
    }
}

void PrintDescriptions(ShoppingCart cart){
    printf("%s\'s Shopping Cart - %s\n", cart.customerName, cart.customerName);
    printf("Item Descriptions\n");
    for(int i =0; i<cart.cartSize; i++){
        printf("%s: %s\n", cart.cartItems[i].itemName,cart.cartItems[i].itemDescription);
    }

}