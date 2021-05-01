#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
#include "Song.h"
int main(int argc, char *argv[]) {

if(argc != 3){
   fprintf(stderr, "Usage: %s <catalog.csv> <size>\n", argv[0]);
exit(1);
}

char * userFilename = argv[1];
char * userSize = argv[2];

/* Open and validate file */
errno = 0;
FILE * dataFile = fopen(userFilename,"r");
if(dataFile == NULL){
   perror("fopen");
   exit(1);
}

/* Convert size from string to int */
//int listSize = atoi(userSize);
int listSize = 0;
int rc = sscanf(userSize,"%d", &listSize);
if(rc != 1){
   fprintf(stderr, "Error: Please enter an integer value for size!\n");
   exit(1);
}

if(listSize <= 0){
   fprintf(stderr, "Error: Please specify a list size greater than zero!");
   exit(1);
}
Song ** songList = (Song **) malloc(sizeof(Song *) * listSize);
if(songList == NULL){
   fprintf(stderr, "Error: Unable to allocate memory for songlist!");
   exit(1);
}

/* Temporary variables for holding CSV fields */
const int MAX_FIELD_SIZE = 256;
char artistField[MAX_FIELD_SIZE];
char albumField[MAX_FIELD_SIZE];
char titleField[MAX_FIELD_SIZE];
int durationField;

int songCount = 0;
int numRead;
while(!feof(dataFile) && songCount < listSize){
   numRead = fscanf(dataFile, "%255[^,],%255[^,],%255[^,],%d\n", artistField, albumField, titleField, &durationField);
   if(numRead == 4){
      songList[songCount++] = CreateSong(artistField, albumField, titleField,durationField);
   }else{
      fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
   }
}
/*Cleanup*/
fclose(dataFile);
fprintf(stdout, "Successfully loaded %d of songs!\n", songCount);

/*Display the songList */
for(int i =0; i < songCount; i++){
   PrintSong(songList[i]);
}

/*Cleanup the songlist*/
for(int i =0; i<songCount; i++){
   DestroySong(songList[i]);
}
free(songList);
return 0;
}