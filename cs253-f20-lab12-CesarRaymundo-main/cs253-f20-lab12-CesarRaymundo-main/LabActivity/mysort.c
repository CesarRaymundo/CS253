/* 
 * Author: Luke Hindman
 * Date: Fri 13 Nov 2020 12:21:37 PM PST
 * Description: Starter code for stream processing lab
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define READ_BUFFER_SIZE 1024
#define MAX_FILEPATH_SIZE 4096
int SortDataStream(int reverse, FILE * in, FILE * out);

int main (int argc, char * argv[]) {
    int reverseFlag = false;
/* Allocate space for filepath on stack
 *  intialize filePath to empty string */
char filepath[MAX_FILEPATH_SIZE];
filepath[0] = '\0'; 

int opt;

while ((opt = getopt(argc, argv, "hf:r")) != -1){
    switch(opt){
        case 'h':
        fprintf(stderr, "Usage: %s [-f <file>] [-h]\n",argv[0]);
        exit(0);
        break;

        case 'f':
            strncpy(filepath, optarg,MAX_FILEPATH_SIZE);
            break;
        case 'r':
        reverseFlag = true;
        break;
        default:
        fprintf(stderr, "Usage: %s [-f <file>] [-h]\n",argv[0]);
        exit(1);
        break;

    }
}

int status = 0;
if(strcmp(filepath,"") == 0){
    status = SortDataStream(reverseFlag, stdin, stdout);
} else{
    FILE * inputStream = fopen(filepath, "r");
    status = SortDataStream(reverseFlag,inputStream,stdout);
    fclose(inputStream);
}

if(status != 0){
    fprintf(stderr, "Error: Sort did not complete successfully \n");
    exit(1);
}
    return 0;
}
char ** GrowArray(char **array, int current_length, int new_length){
    if(array == NULL){
        return NULL;
    }

    if(new_length <= current_length){
        return NULL;
    }

    char **newArray = (char **)malloc(sizeof(char *) * new_length);
    if(newArray == NULL){
        return NULL;
    }

    for(int i = 0; i<current_length; i++){
        newArray[i] = array[i];
    }

    free(array);

    return newArray;
}

int MyStringCompare(const void *entryA, const void *entryB){
    char *string1 = *(char**) entryA;
    char *string2 = *(char**) entryB;

    int result = strcmp(string1, string2);

    return result;
}

int MyReverseStringCompare(const void *entryA, const void *entryB){
    char *string1 = *(char**) entryA;
    char *string2 = *(char**) entryB;

    int result = strcmp(string2, string1);

    return result;
}
int SortDataStream(int reverse, FILE * in, FILE * out){
    char buffer[READ_BUFFER_SIZE];
    size_t readCount = 0;
    size_t writeCount = 0;

    /*Setup lineArray*/
    const size_t INIT_NUM_LINES = 16;
    char ** lineArray = (char **) malloc (sizeof(char *) * INIT_NUM_LINES);
    int lineArrayCapacity = INIT_NUM_LINES;

    if (lineArray == NULL){
        fprintf(stderr, "Error: Unable to allicated lineArray\n");
        return -1;    
    }

    /* Read data from input stream and sort lines in the array */
    int lineCout = 0;
    while (fgets(buffer, READ_BUFFER_SIZE, in) != NULL){
        readCount = strlen(buffer);
     
        if(lineCout >= lineArrayCapacity){
            lineArray = GrowArray(lineArray, lineArrayCapacity, lineArrayCapacity * 2);   
        lineArrayCapacity *= 2;
        }

        lineArray[lineCout] = (char *) malloc (sizeof (char) * readCount +1);
        if(lineArray[lineCout] == NULL){
            fprintf(stderr, "Error: Unable to allocate memory\n");
            return -1;
        }

        strcpy(lineArray[lineCout], buffer);
        lineCout++;
    }

    /*Sort the lineArray*/
    if(reverse == true){
    qsort(lineArray, lineCout, sizeof(char *), MyReverseStringCompare);
    }else{
    qsort(lineArray, lineCout, sizeof(char *), MyStringCompare);
    }
    /* Write the lines to output stream */
    for (int i = 0; i<lineCout; i++){
        writeCount = fwrite(lineArray[i], sizeof(char), strlen(lineArray[i]), out);

        if(writeCount != strlen(lineArray[i])){
            fprintf(stderr, "Error: An error occurent whule writing to output stream\n");
            return -1;
        }
    }
    
    for(int i = 0; i < lineCout; i++){
        free(lineArray[i]);
    }
    free(lineArray);
    return 0;
}
