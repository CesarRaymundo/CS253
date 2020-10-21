# Lab08 Guide
## Getting Started

Please watch the [Lab08 Walkthough Video](https://www.youtube.com/playlist?list=PLvnIObHoMl8cYVKwOXlAgRFquwLgPpYAH).

### Code Style Requirements
Please review the [CS253 Style Guide](https://docs.google.com/document/d/1zKIpNfkiPpDHEvbx8XSkZbUEUlpt8rnZjkhCSvM-_3A/edit?usp=sharing) and apply it in all lab warmups, lab activities and projects this semester. Coding Style will assessed as part of your lab and project grades.

### Code Quality Requirements
- Code must compile without warnings using the provided Makefile
- Programs must handle unexpected user input and either reprompt (loops) or gracefully exit with a non-zero exit status.
- Programs must handle error conditions gracefully, without crashing, ideally by checking function returns codes (if available) and returning a non-zero exit status.
- Programs should be free of memory related errors, buffer overflows, stack smashing, etc... Whether the program crashes or not.

## Lab Warmup - Online shopping cart (Part 1)
### Problem Description  
1. Create three files to submit:

- ItemToPurchase.h - Struct definition and related function declarations
- ItemToPurchase.c - Related function definitions
- main.c - main() function

Build the ItemToPurchase struct with the following specifications: 

- Data members 
    - char itemName [ ]
    - int itemPrice
    - int itemQuantity
- Related functions
    - MakeItemBlank() 
        - Has a pointer to an ItemToPurchase parameter. 
        - Sets item's name = "none", item's price = 0, item's quantity = 0
    - PrintItemCost()
        - Has an ItemToPurchase parameter.

<br />
Ex. of PrintItemCost() output:

```
Bottled Water 10 @ $1 = $10
```
<br />
2. In main(), prompt the user for two items and create two objects of the ItemToPurchase struct.  Before prompting for the second item, enter the following code to allow the user to input a new string. `c` is declared as a char.  

```
c = getchar();
while(c != '\n' && c != EOF) {
   c = getchar();
}
```
<br />
Ex:

```
Item 1
Enter the item name:
Chocolate Chips
Enter the item price:
3
Enter the item quantity:
1

Item 2
Enter the item name:
Bottled Water
Enter the item price:
1
Enter the item quantity:
10
```
<br />
3. Add the costs of the two items together and output the total cost. 
<br /><br />
Ex:

```
TOTAL COST
Chocolate Chips 1 @ $3 = $3
Bottled Water 10 @ $1 = $10

Total: $13
```

### Implementation Guide
1. Expand the folder named LabWarmup and open the files named ItemsToPurchase.c, ItemsToPurchase.h and main.c
2. Enter the program code to create an application as described in the Problem Description.
3. Test the program using to ensure it functions as expected.
4. Commit the changes to your local repository with a message stating that LabActivity is completed.
5. Push the changes from your local repository to the github classroom repository.
6. Update the Coding Journal with an entry describing your experience using the steps outlined below.

## Lab Activity - Online shopping cart (Part 2)
### Problem Description  
This program extends the earlier "Online shopping cart" program. Please copy ItemToPurchase.c and ItemToPurchase.h from the LabWarmup folder into the LabActivity folder.  

<br />
1. Extend the ItemToPurchase struct to contain a new data member.   

- char itemDescription[ ] - set to "none" in MakeItemBlank() 

Implement the following related functions for the ItemToPurchase struct.

- PrintItemDescription()
   - Has an ItemToPurchase parameter.

<br />
Ex. of PrintItemDescription() output:

```
Bottled Water: Deer Park, 12 oz.
```
<br />
2. Create three new files:

- ShoppingCart.h - struct definition and related function declarations
- ShoppingCart.c - related function definitions
- main.c - main() function (Note: main()'s functionality differs from the warm up)

Build the ShoppingCart struct with the following data members and related functions. Note: Some can be function stubs (empty functions) initially, to be completed in later steps.

- Data members 
   - char customerName [ ]
   - char currentDate [ ]
   - ItemToPurchase cartItems [ ] - has a maximum of 10 slots (can hold up to 10 items of any quantity)
   - int cartSize - the number of filled slots in array cartItems [ ] (number of items in cart of any quantity)
- Related functions
   - AddItem()
      - Adds an item to cartItems array. Has parameters ItemToPurchase and ShoppingCart. Returns ShoppingCart object.
   - RemoveItem()
      - Removes item from cartItems array (does not just set quantity to 0; removed item will not take up a slot in array). Has a char[ ](an item's name) and a ShoppingCart parameter. Returns ShoppingCart object.
      - If item name cannot be found, output this message: `Item not found in cart. Nothing removed.`
   - ModifyItem()
      - Modifies an item's description, price, and/or quantity. Has parameters ItemToPurchase and ShoppingCart. Returns ShoppingCart object.
   - GetNumItemsInCart() 
      - Returns quantity of all items in cart. Has a ShoppingCart parameter.
   - GetCostOfCart() 
      - Determines and returns the total cost of items in cart. Has a ShoppingCart parameter. 
   - PrintTotal()
      - Outputs total of objects in cart. Has a ShoppingCart parameter.
      - If cart is empty, output this message: `SHOPPING CART IS EMPTY`
   - PrintDescriptions()
      - Outputs each item's description. Has a ShoppingCart parameter.

<br />
Ex. of PrintTotal() output:

```
John Doe's Shopping Cart - February 1, 2016
Number of Items: 8

Nike Romaleos 2 @ $189 = $378
Chocolate Chips 5 @ $3 = $15
Powerbeats 2 Headphones 1 @ $128 = $128

Total: $521
```
<br />
Ex. of PrintDescriptions() output:

```
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes
Chocolate Chips: Semi-sweet
Powerbeats Headphones: Bluetooth headphones
```
<br />
3. In main(), prompt the user for a customer's name and today's date. Output the name and date. Create an object of type ShoppingCart. 
<br /><br />

```
Enter Customer's Name:
John Doe
Enter Today's Date:
February 1, 2016

Customer Name: John Doe
Today's Date: February 1, 2016
```
<br />
4. Implement the PrintMenu() function. PrintMenu() has a ShoppingCart parameter, and outputs a menu of options to manipulate the shopping cart. Each option is represented by a single character. Build and output the menu within the function.

If the an invalid character is entered, continue to prompt for a valid choice. *Hint: Implement Quit before implementing other options.*
Call PrintMenu() in the main() function. Continue to execute the menu until the user enters q to Quit. 
<br /><br />

```
MENU
a - Add item to cart
r - Remove item from cart
c - Change item quantity
i - Output items' descriptions
o - Output shopping cart
q - Quit

Choose an option:

```
<br />
5. Implement the "Output shopping cart" menu option.
<br /><br />

```
OUTPUT SHOPPING CART
John Doe's Shopping Cart - February 1, 2016
Number of Items: 8

Nike Romaleos 2 @ $189 = $378
Chocolate Chips 5 @ $3 = $15
Powerbeats Headphones 1 @ $128 = $128

Total: $521
```
<br />
6. Implement the "Output item's description" menu option. 
<br /><br />

```
OUTPUT ITEMS' DESCRIPTIONS
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes
Chocolate Chips: Semi-sweet
Powerbeats Headphones: Bluetooth headphones
```
<br />
7. Implement "Add item to cart" menu option. 
<br /><br />

```
ADD ITEM TO CART
Enter the item name:
Nike Romaleos
Enter the item description:
Volt color, Weightlifting shoes
Enter the item price:
189
Enter the item quantity:
2
```
<br />
8. Implement the "Remove item from cart" menu option. 
<br /><br />

```
REMOVE ITEM FROM CART
Enter name of item to remove:
Chocolate Chips
```
<br />
9. Implement "Change item quantity" menu option. 

*Hint: Make new ItemToPurchase object before using ModifyItem() function.* 
<br /><br />

```
CHANGE ITEM QUANTITY
Enter the item name:
Nike Romaleos
Enter the new quantity:
3
```


### Implementation Guide
1. Expand the folder named LabActivity and open the file named service_invoice.c
2. Enter the program code to create an application as described in the Problem Description.
3. Test the program using to ensure it functions as expected.
4. Commit the changes to your local repository with a message stating that LabActivity is completed.
5. Push the changes from your local repository to the github classroom repository.
6. Update the Coding Journal with an entry describing your experience using the steps outlined below.

## Coding Journal
Keep a journal of your activities as you work on this lab. Many of the best engineers that I have worked with professionally have kept some sort of engineering journal. I personally packed notebooks around with me for nearly 8 years before I began keeping my notes electronically.   

Your journal can track ideas, bugs, cool links, code snippets, shell commands, rants, or simply a reflection on what worked well or not-so-well with this lab activity. I will not be grading the content of your journal, but I will expect at least two date-stamped journal entries of at least a paragraph each added to the provided Journal.md file.

### Implementation Details
1. Add an entry to the provided Journal.md located in the CodingJournal folder, formatted using markdown notation. You can find a reference at the bottom of this guide.

2. Commit the changes to your local repository with a message stating an entry has been added to the journal.
3. Push the changes from your local repository to the github classroom repository.
4. Repeat for reach additional journal entry
## Markdown Resources
Markdown is a notation that is used to format text documents.  It is widely used in Software Development shops around the world, which is why we're asking you to use it in your lab documentation.  

Github provides a guide for getting started:  [Mastering Markdown](https://guides.github.com/features/mastering-markdown/)
