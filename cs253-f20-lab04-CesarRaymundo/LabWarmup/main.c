/*
* Author: Cesar Raymundo
* Date: 09/21/20
* Description: LabWarmup, this program gets input from user to output service requested 
* cost of that service
*/

#include <stdio.h>
#include<string.h>
int main(void) {
const int MAX_WORD_LENGTH = 40;
char serviceWord1[MAX_WORD_LENGTH + 1];
char serviceWord2[MAX_WORD_LENGTH + 1];
   /* Part 1 - get service desired from user*/ 
   printf("Enter desired auto service: \n");
   scanf("%40s %40s", serviceWord1, serviceWord2);
   printf("You entered: %s %s\n", serviceWord1, serviceWord2);

/* Part 2 - output price of the requested service*/
if( (strcmp(serviceWord1, "Oil") == 0) && (strcmp(serviceWord2,"change") == 0)){
   printf("Cost of oil change: $35\n");
}else if( (strcmp(serviceWord1, "Tire") == 0) && (strcmp(serviceWord2,"rotation") == 0)){
   printf("Cost of tire rotation: $19\n");
}else if( (strcmp(serviceWord1, "Car") == 0) && (strcmp(serviceWord2,"wash") == 0)){
   printf("Cost of car wash: $7\n");
}else{
   printf("The requested service is not recognized\n");
}
   return 0;
}