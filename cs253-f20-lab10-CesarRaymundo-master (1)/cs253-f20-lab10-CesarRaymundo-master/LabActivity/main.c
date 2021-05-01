/**
 * Description: Uses Student.h and command line arguments to create a Student struct
 * With that it is put into a gradebook list and sorted from worst to best grade. Then
 * it is outputed on stdout.
 * 
 * Author:Cesar Raymundo
 * Date: November 9th 2020
 **/

#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
#include "Student.h"
/* growArray: Allocates more space in heap for a larger array size. Gets a copy of the 
 * current array(gradebook) into the new array(newGradbook). Return Null on error and leaves the current
 * array(gradebook) unchanged.
 *
 *  gradebook - pointer to current Student gradebook
 * current_length - the sizee of the current int array
 *  
 * returns - pointer to newly allocated int array
 */
Student ** growArray(Student ** gradebook, int currentLength){
   if(gradebook == NULL){
      return NULL;
   }
   Student ** newGradebook = (Student **) malloc(sizeof(Student*) * (currentLength * 2));
   if(newGradebook == NULL){
      return NULL;
   }

   for (int i = 0; i < currentLength; i++)
   {
      newGradebook[i] =  gradebook[i];
   }

   free(gradebook);
   printf("Growing Array: %d -> %d\n",currentLength,currentLength*2);

   return newGradebook;
   
}


int main(int argc, char *argv[]) {

if(argc != 2){
   fprintf(stderr, "Usage: %s <gradebook.csv>\n", argv[0]);
exit(1);
}

char * userFilename = argv[1];

/* Open and validate file */
errno = 0;
FILE * dataFile = fopen(userFilename,"r");
if(dataFile == NULL){
   perror("fopen");
   exit(1);
}
const int INIT_STDENT_SIZE = 8;
Student ** gradebook = (Student **) malloc(sizeof(Student *) * INIT_STDENT_SIZE);
int  gradebookArrayCapacity = INIT_STDENT_SIZE;
if(gradebook == NULL){
   fprintf(stderr, "Error: Unable to allocate memory for studentList!");
}
/* Temporary variables for holding CSV fields */
const int MAX_FIELD_SIZE = 20;
char lastNameField[MAX_FIELD_SIZE];
char firstNameField[MAX_FIELD_SIZE];
int id;
int score;

int studentCount = 0;
int numRead;
/* Reads in the file and creates a Student with given data from the file*/
while(!feof(dataFile)){
   numRead = fscanf(dataFile, "%255[^,],%255[^,],%d,%d\n", lastNameField, firstNameField, &id, &score);
   if(numRead == 4){
      if(studentCount >= gradebookArrayCapacity){
         gradebook = growArray(gradebook,gradebookArrayCapacity);

   if(gradebook == NULL){
      fprintf(stderr, "Error: An error occured while growing the array.\n");
   }
        gradebookArrayCapacity *=2;
      }
        gradebook[studentCount++] = CreateStudent(lastNameField, firstNameField, id, score);

   }else{
      fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
   }  
}
/*Cleanup*/
fclose(dataFile);
fprintf(stdout, "Successfully loaded %d Students!\n",studentCount);
qsort(gradebook, studentCount,sizeof(Student *),CompareStudents);

/*Display the gradebook*/
for(int i = 0; i < studentCount; i++){
   PrintStudent(gradebook[i]);
}

/*Cleanup for memory*/
for(int i =0; i<studentCount;i++){
   DestroyStudent(gradebook[i]);
}
free(gradebook);

   return 0;
}
