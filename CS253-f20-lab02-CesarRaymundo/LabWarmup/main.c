#include <stdio.h>

int main(void) {
   int userNum;
   int userNum1;
   
   printf("Enter integer:\n");
   scanf("%d", &userNum);
   printf("You entered: %d\n", userNum);
   printf("%d sqaured is %d\n", userNum, (userNum * userNum));
   printf("And %d cubed is %d!!\n", userNum, (userNum * userNum * userNum));
   printf("Enter another integer:\n");
   scanf("%d", &userNum1);
   printf("%d + %d is %d\n", userNum, userNum1, (userNum + userNum1));
   printf("%d * %d is %d\n", userNum, userNum1, (userNum * userNum1));
   
   return 0;
}