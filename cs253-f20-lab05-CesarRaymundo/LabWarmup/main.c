/**
 * Author: Cesar Raymundo
 * Date: 09/28/2020
 * Description:Purpose of this code is to get a specific character and height from user.
 * Then with the given input, output a triangle with the given values.
 **/ 
 
#include <stdio.h>

int main(void) {
   char triangleChar;
   int triangleHeight;

   printf("Enter a character:\n");
   scanf("%c", &triangleChar);
   
   printf("Enter triangle height:\n");
   scanf("%d", &triangleHeight);
   printf("\n");

for(int i = 0; i < triangleHeight; i++){
for(int j = 0; j < i+1; j++){
printf("%c ", triangleChar);
}
printf("\n");
}
       

   return 0;
}