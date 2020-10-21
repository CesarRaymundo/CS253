/*
* Author: Cesar Raymundo
* Date: 09/21/20
* Description: LabActivity, the purpose of this program is to get input from the user
* and output the selected services along with the total cost of those services. 
* 
*/
#include <stdio.h>
#include<string.h>

int main(void) {
const int MAX_WORD_LENGTH = 40;
char service1[MAX_WORD_LENGTH + 1];
char service2[MAX_WORD_LENGTH + 1];
//char service2Word1[MAX_WORD_LENGTH + 1];
//char service2Word2[MAX_WORD_LENGTH + 1];
printf("Davy's auto shop services\n Oil change -- $35\n Tire rotation -- $19\n Car wash -- $7\n Car wax -- $12\n");
printf("\n");
printf("Select first service: \n");
scanf("%[^\n]",service1);

printf("Select second service: \n");
scanf(" %[^\n]",service2);
printf("\n");
/*Part 2 - Output of the serivces selected and their prices*/
printf("Davy's auto shop invoice\n");
printf("\n");
//If statment for service 1
if((strcmp(service1, "Oil change") == 0)){
   printf("Service 1: Oil change, $35\n");
}else if( (strcmp(service1, "Tire rotation") == 0)) {
  printf("Service 1: Tire rotation, $19\n");
}else if( (strcmp(service1, "Car wash") == 0)){
   printf("Service 1: Car wash, $7\n");
}else if( (strcmp(service1, "Car wax") == 0)){
   printf("Service 1: Car wax, $12\n");
}else{
   printf("Services is not recognized\n");
}

//If statement for service 2
if((strcmp(service2, "Oil change") == 0)){
   printf("Service 2: Oil change, $35\n");
}else if( (strcmp(service2, "Tire rotation") == 0)) {
  printf("Service 2: Tire rotation, $19\n");
}else if( (strcmp(service2, "Car wash") == 0)){
   printf("Service 2: Car wash, $7\n");
}else if( (strcmp(service2, "Car wax") == 0)){
   printf("Service 2: Car wax, $12\n");
}else if( (strcmp(service2, "-") == 0)){
   printf("Service 2: No service\n");
}else{
   printf("Services is not recognized\n");
}

if((strcmp(service1,"Oil change")==0) && (strcmp(service2,"Tire rotation")==0)){
   printf("Total: $54\n");
}else if ((strcmp(service1,"Oil change")==0) && (strcmp(service2,"Car wash")==0)){
   printf("Total: $42\n");
}else if ((strcmp(service1,"Oil change")==0) && (strcmp(service2,"Car wax")==0)){
   printf("Total: $47\n");
}else if ((strcmp(service1,"Oil change")==0) && (strcmp(service2,"-")==0)){
   printf("Total: $35\n");
}else if ((strcmp(service1,"Tire rotation")==0) && (strcmp(service2,"Oil change")==0)){
   printf("Total: $54\n");
}else if ((strcmp(service1,"Tire rotation")==0) && (strcmp(service2,"Car wash")==0)){
   printf("Total: $26\n");
}else if ((strcmp(service1,"Tire rotation")==0) && (strcmp(service2,"Car wax")==0)){
   printf("Total: $31\n");
}else if ((strcmp(service1,"Tire rotation")==0) && (strcmp(service2,"-")==0)){
   printf("Total: $19\n");
}else if ((strcmp(service1,"Car wash")==0) && (strcmp(service2,"Oil change")==0)){
   printf("Total: $42\n");
}else if ((strcmp(service1,"Car wash")==0) && (strcmp(service2,"Tire rotation")==0)){
   printf("Total: $26\n");
}else if ((strcmp(service1,"Car wash")==0) && (strcmp(service2,"Car wax")==0)){
   printf("Total: $19\n");
}else if ((strcmp(service1,"Car wash")==0) && (strcmp(service2,"-")==0)){
   printf("Total: $7\n");
}else if ((strcmp(service1,"Car wax")==0) && (strcmp(service2,"Oil change")==0)){
   printf("Total: $47\n");
}else if ((strcmp(service1,"Car wax")==0) && (strcmp(service2,"Tire rotation")==0)){
   printf("Total: $31\n");
}else if ((strcmp(service1,"Car wax")==0) && (strcmp(service2,"Car wash")==0)){
   printf("Total: $19\n");
}else if ((strcmp(service1,"Car wax")==0) && (strcmp(service2,"-")==0)){
   printf("Total: $12\n");
}else{
   printf("Total: $0 ");
}

   return 0;
}