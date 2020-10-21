#include<stdio.h>
#include <string.h>
/*
* Author: Cesar Raymundo
* Date October 12, 2020
* Description: The program prompts the user to enter a sentence or phrase, then with the 
* given data we give the number of character and the sentece or phrase wihtout whitespace
* characters
*/

/*
* Output string to stdout wihtout whitespace characters
* usrStr - null terminated string
*/
void OutputWithoutWhitespace(const char usrStr[]){
for (size_t i = 0; i < strlen(usrStr); i++){
   if(usrStr[i] != ' ' && usrStr[i] != '\t'){
   printf("%c", usrStr[i]);
   }
}
printf("\n");
}


/* 
* Returns the number of characters in usrStr
* usrStr - null terminated string
* returns - number of characters in string
*/

int GetNumOfCharacters(const char usrStr[]) {
   int numChars = 0;
   int i = 0;
while (usrStr[i] != '\0'){
   numChars++;
   i++;
}

return numChars;
}
   
int main(void) {

   /* Declare variables */
   const int MAX_LENGTH = 50;
   char userString[MAX_LENGTH];
   int charCount=0;

   /* Prompt user for string */
   printf("Enter a sentence or phrase:\n");
   fgets(userString,MAX_LENGTH,stdin);
   
   /*Remove trailing newline character*/
   userString[strlen(userString)-1] = '\0';

   /* Output the string */
   printf("You entered: %s\n", userString);


   /* Output the character length */
   charCount = GetNumOfCharacters(userString);
   printf("Number of characters: %d\n", charCount);

    /* Output the string without whitespace characters */
    OutputWithoutWhitespace(userString);
   return 0;
}