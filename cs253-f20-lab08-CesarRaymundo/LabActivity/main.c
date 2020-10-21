#include <stdio.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

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
void PrintMenu(ShoppingCart userCart) {
    char myChar = ' ';
    char c = ' ';

    while (myChar != 'q') {

        printf("\nMENU\n");
        printf("a - Add item to cart\n");
        printf("r - Remove item from cart\n");
        printf("c - Change item quantity\n");
        printf("i - Output items' descriptions\n");
        printf("o - Output shopping cart\n");
        printf("q - Quit\n\n");

        while (myChar != 'a' && myChar != 'r' && myChar != 'c' &&
               myChar != 'i' && myChar != 'o' && myChar != 'q') {

            printf("Choose an option:\n");
            scanf(" %c", &myChar);
        }

        
        if (myChar == 'a') { /*Adds an item to the shopping cart.*/

            while ((c = getchar()) != EOF && c != '\n');

            ItemToPurchase item;

            printf("\nADD ITEM TO CART\n");

            /*Adding item's name*/
            printf("Enter the item name:\n");
            scanf("%79[^\n]s", item.itemName);
            BufferPurge();

            /*Adding item's description*/
            printf("Enter the item description:\n");
            scanf("%79[^\n]s", item.itemDescription);
            BufferPurge();

            /*Adding item's price and quantity*/
            printf("Enter the item price:\n");
            scanf("%d", &item.itemPrice);
             BufferPurge();
            printf("Enter the item quantity:\n");
            scanf("%d", &item.itemQuantity);
             BufferPurge();

            userCart = AddItem(item, userCart);

            printf("\n");
            myChar = ' ';

        } else if (myChar == 'r') { //Removes an item from the shopping cart
        while ((c = getchar()) != EOF && c != '\n');

        ItemToPurchase item;

            printf("\nREMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            scanf("%79[^\n]s", item.itemName);
            BufferPurge();

           userCart = RemoveItem(item.itemName, userCart);

            myChar = ' ';

        } else if (myChar == 'c') {//Changes item quantity
              while ((c = getchar()) != EOF && c != '\n');

            char temp[50];
            char tempStr[50];

            printf("\nCHANGE ITEM QUANTITY\n");

            printf("Enter the item name:\n");
            fgets(temp, 50, stdin);

            int i = 0;
            while (temp[i] != '\n') {
                tempStr[i] = temp[i];
                ++i;
            }
            tempStr[i] = '\0';

            userCart = ModifyItem(tempStr, userCart);


            myChar = ' ';

        } else if (myChar == 'i') {//Outputs items descriptions 
            printf("\nOUTPUT ITEMS' DESCRIPTIONS\n");
            PrintDescriptions(userCart);
            myChar = ' ';

        } else if (myChar == 'o') {// Outputs the shopping cart 
            printf("\nOUTPUT SHOPPING CART\n");
            PrintTotal(userCart);
            myChar = ' ';

        }

    }
}


int main() {

    ShoppingCart userCart;
    userCart.cartSize = 0;

    printf("Enter Customer's Name:\n");
    scanf("%79[^\n]s", userCart.customerName);
    BufferPurge();
    printf("Enter Today's Date:\n");
    scanf("%79[^\n]s", userCart.currentDate);
    BufferPurge();

    printf("\nCustomer Name: %s\n", userCart.customerName);
    printf("Today's Date: %s\n", userCart.currentDate);

    PrintMenu(userCart);

return 0;
}