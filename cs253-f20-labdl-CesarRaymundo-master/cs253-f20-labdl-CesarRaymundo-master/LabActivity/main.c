/*
* Author: Cesar Raymundo
* Date: November 2nd, 2020
* Description: The program is a game of M.A.S.H. using a linked list, the program has a list
* of possibilities the user can get from each list. The program asks for the user's name and 
* creates random values from each list and prints them on stdout to show the user's future.
*/

#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "DataNode.h"
int main(void) {
/*Declaring variables*/
char name[50];
const char *database[6];
enum indexes{HOME_LIST, FEMALE_SPOUSE_LIST, MALE_SPOUSE_LIST,
OCCUPATION_LIST,TRANSPORATION_LIST,HOMETOWN_LIST};

/*Making arrays for the enums in the database*/
char *homeArray[] = {"mansion", "apartment", "shack", "house", "rock"};

char *femaleArray[]  = {"Megan", "Melissa", "Grace", "Chloe", "Clair"};

char *maleArray[] = {"Richard", "Bob", "Stanely", "Conner", "Edgar"};

char *ocupationArray[] =  {"teacher", "stockbroker", "software developer", "actor", "lawyer"};

char *transArray[] = {"jetpack", "walk", "private jet", "bike", "ride a bus"};

char *townArray[] = {"Hollywood", "Miami", "The Bronx", "Staten Island", "Boise"};

/*Making the headNode for database*/
DataNode *headNode = CreateDataNode(database);

/*Building data list*/
database[HOME_LIST] = BuildDataList(homeArray,5);
database[FEMALE_SPOUSE_LIST] = BuildDataList(femaleArray,5);
database[MALE_SPOUSE_LIST] = BuildDataList(maleArray,5);
database[OCCUPATION_LIST] = BuildDataList(ocupationArray,5);
database[TRANSPORATION_LIST] = BuildDataList(transArray,5);
database[HOMETOWN_LIST] = BuildDataList(townArray,5);
database[FEMALE_SPOUSE_LIST] = BuildDataList(femaleArray,5);


/*Prinitng on stdout the future possiblities of each list*/
printf("----------------------------Future Possibilities Database----------------------------\n");
printf("Home list: ");
PrintDataList(database[HOME_LIST]); 
printf("Home list: ");
PrintDataList(database[FEMALE_SPOUSE_LIST]);
printf("Male Spouse List: ");
PrintDataList(database[MALE_SPOUSE_LIST]);
printf("Ocupation List: ");
PrintDataList(database[OCCUPATION_LIST]);
printf("Transportation list: ");
PrintDataList(database[TRANSPORATION_LIST]);
printf("Hometown List: ");
PrintDataList(database[HOMETOWN_LIST]);
printf("-------------------------------------------------------------------------------------\n");

/*Getting random data nodes from each list*/
srand(time(0));
DataNode *randHome = GetRandomDataNode(database[HOME_LIST]);
DataNode *randHome2 = GetRandomDataNode(database[HOME_LIST]);
DataNode *randFem = GetRandomDataNode(database[FEMALE_SPOUSE_LIST]);
srand(time(0));
DataNode *randMale = GetRandomDataNode(database[MALE_SPOUSE_LIST]);
DataNode *randOcup = GetRandomDataNode(database[OCCUPATION_LIST]);
DataNode *randTrans = GetRandomDataNode(database[TRANSPORATION_LIST]);
DataNode *randTown = GetRandomDataNode(database[HOMETOWN_LIST]);

/*User input*/
printf("Please enter your name: ");
scanf("%s", name);
printf("\n\n");

/*Random value to determine female or male spouse list*/
srand(time(0));
bool coin = rand() % 2;
		if(coin == true){
	printf("Welcome %s, this is you future...\n", name);
   printf("You will marry %s and live in a %s\n", randFem->dataValue, randHome->dataValue);
	printf("After 3 years of marriage, you will finally get your dream job of being a %s.\n", randOcup->dataValue);
   printf("Your family will move to a %s in %s where you will %s to work everyday.\n", randHome2->dataValue, randTown->dataValue,randTrans->dataValue);  
      }else{
	printf("Welcome %s, this is you future...\n", name);
   printf("You will marry %s and live in a %s\n", randMale->dataValue, randHome->dataValue);
	printf("After 3 years of marriage, you will finally get your dream job of being a %s.\n", randOcup->dataValue);
   printf("Your family will move to a %s in %s where you will %s to work everyday.\n", randHome2->dataValue, randTown->dataValue,randTrans->dataValue); 
		}
   
   /*Freeing dynamic memory*/
   DestroyDataList(database[HOME_LIST]);
   DestroyDataList(database[FEMALE_SPOUSE_LIST]);
   DestroyDataList(database[MALE_SPOUSE_LIST]);
   DestroyDataList(database[OCCUPATION_LIST]);
   DestroyDataList(database[TRANSPORATION_LIST]);
   DestroyDataList(database[HOMETOWN_LIST]);

   return 0;
}