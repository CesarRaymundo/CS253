#include<stdio.h>
#include <string.h>
/*
* Author: Cesar Raymundo
* Date October 12, 2020
* Description: The program prompts the user to enter a string of their choosing. After 
* entering the data, they are prompt to a menu that gives them options of what they can
* do with the text they gave.
*/


/*
* Returns the number non-whitespace characters
* word - null terminated string
*/
void GetNumOfNonWSCharacters(const char word[]){
int count =0; 
for (size_t i = 0; i < strlen(word); i++){
if(word[i] != ' '){
count++;
   }
} 
printf("\nNumber of non-whitespace characters: %d\n", count);
}

/*
* Returns the number of words
* word - null terminated string
*/
void GetNumOfWords(const char word[]){
   int count = 0;
   for (size_t i = 0; i < strlen(word); i++){
      if(word[i] == ' '){
         count++;
      }
}
printf("\nNumber of words: %d\n", count+1);
}

/*
* Fixes string with correct capitalization
* word - null terminated string
* returns - string with proper caputalization
*/
char * FixCapitalization(char word[]){
int i =0;
  
for(size_t i = 0; i < strlen(word);){
if(word[i] - 'a' >= 0 && word[i] - 'a' < 26){
word[i] = toupper(word[i]);
i++;
}
  
while(1){
if(word[i] != '\n' && word[i] != '.')
i++;
else
break;
}
if(word[i] != '\n') i++;
while(word[i] == ' ') i++;
}
  
return word;
}

/*
* Takes string and replace each "!" with a "."
* word - null terminated string
* returns - string without exlamations marks
*/
char * ReplaceExclamation(char word[]){ 
for(size_t i = 0; i < strlen(word); i++){
if(word[i] == '!'){
word[i] = '.';
}
}
  
return word;
}

/*
* Takes string and replace all sequences of 2 or more spaces with a single space.
* str - null terminated string
*/
void ShortenSpace(char str[]){
   char test[250];
int i = 0, j = 0;
while (*(str+i) != '\0'){ //check for extra spaces
if (!(*(str+i) == ' ' && *(str+(i+1))== ' ')){
test[j] = *(str+i);
j++;
}
i++;
}

test[j] = '\0';
printf("Edited text is: %s\n",test );
}
int main(void) {

   /* Declaring Variables */
   const int MAX_LENGTH = 250;
   char userString[MAX_LENGTH];
   //int charCount=0;
   char option = ' ';

   /* Prompt user for string */
   printf("Enter a sample text:\n");
   fgets(userString,MAX_LENGTH,stdin);
   
   /*Remove trailing newline character*/
   userString[strlen(userString)-1] = '\0';

   /* Output the string */
   printf("You entered: %s\n", userString);
   
   /* Menu with options that with given option to do with the array of userString */
   do
   {
      //Prints the menu
      printf("\nMENU\n");
      printf("c - Number of non-whitespace characters\n");
      printf("w - Number of words\n");
      printf("f - Fix capitalization\n");
      printf("r - Replace all !'s\n");
      printf("s - Shorten spaces\n");
      printf("q - Quit\n");
      printf("\nChoose an option:\n");
      scanf(" %c", &option);
      //use switch case
      switch (option)
      {
      
      /*Number of non-whitespace characters.*/
      case 'c':
      GetNumOfNonWSCharacters(userString);
      break;

      /*Number of words*/
      case 'w':
       GetNumOfWords(userString);
         break;
      
      /*Fix capitalization*/
      case 'f':
        printf("Edited text: %s\n",FixCapitalization(userString));
         break;
      
      /* Replace all !'s */
      case 'r':
      printf("Edited text: %s\n",ReplaceExclamation(userString));
         break;
     
      /* Outputs shorten spaces */
      case 's':
      ShortenSpace(userString);
      break;
      
      /*Quits the program*/
      case 'q':
         break;
      
      default:
         break;
      }
   } while (option != 'q');

   return 0;
}