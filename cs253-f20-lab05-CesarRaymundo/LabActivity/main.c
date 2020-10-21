/**
 * Author: Cesar Raymundo
 * Date:09/28/20
 * Description: Gets user input to get dimensions to be able to output half an arrow to the
 * terminal. Also only accepts dimensions if arrow head width is larger than arrow head base
 * width.
 * */

#include <stdio.h>

int main(void) {
   int arrowBaseHeight;
   int arrowBaseWidth;
   int arrowHeadWidth;
   
   printf("Enter arrow base height:\n");
   scanf("%d", &arrowBaseHeight);
   
   printf("Enter arrow base width:\n");
   scanf("%d", &arrowBaseWidth);
   
   printf("Enter arrow head width:\n");
   scanf("%d", &arrowHeadWidth);
   printf("\n");
    
    while(arrowHeadWidth <= arrowBaseWidth){
     printf("Enter a arrow head width that is larger than arrow base width:\n");
     scanf("%d", arrowHeadWidth); 
   }

   // Draw arrow base (height = 3, width = 2)
  for(int i = 0; i<arrowBaseHeight; i++){
     for(int j = 0; j<arrowBaseWidth; j++){
        printf("*");
     }
     printf("\n");
  }
   
   // Draw arrow head (width = 4)
   for(int i =0; i<arrowHeadWidth; i++){
      for(int j = 0; j < arrowHeadWidth-i; j++){
         printf("*");
      }
      printf("\n");
   }
   
   return 0;
}