#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "PlaylistNode.h"

PlaylistNode* CreatePlaylistNode(char id[], char songName[], char artistName[], int songLength){
    PlaylistNode * thisNode = (PlaylistNode *)malloc(sizeof(PlaylistNode));

    if(thisNode == NULL){
        return NULL;
    }
    
    strncpy(thisNode->uniqueID, id, FIELD_SIZE); 
    strncpy(thisNode->songName, songName, FIELD_SIZE);
    strncpy(thisNode->artistName, artistName, FIELD_SIZE);  
    thisNode->songLength = songLength;
    thisNode->nextNodePtr = NULL;

    return thisNode;
}

int InsertPlaylistNodeAfter(PlaylistNode* nodeInList, PlaylistNode* newNode){
PlaylistNode* tmpNext = NULL;

/* Validates parameters */
if(nodeInList == NULL || newNode == NULL){
    return -1;
}

tmpNext = nodeInList->nextNodePtr;
nodeInList->nextNodePtr = newNode;
newNode->nextNodePtr = tmpNext;

return 0;
}

int SetNextPlaylistNode(PlaylistNode* nodeInList, PlaylistNode* newNode){
/* Validate parameter */
if(nodeInList == NULL){
    return -1;
}
nodeInList->nextNodePtr = newNode;
return 0;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* nodeInList){
/* Validate parameter */
if(nodeInList == NULL){
    return NULL;
}
return nodeInList->nextNodePtr;
}

void PrintPlaylistNode(PlaylistNode* thisNode){
/* Validate parameter */
if(thisNode == NULL){
    return;
}
printf("Unique ID: %s\n", thisNode->uniqueID);
printf("Song Name: %s\n", thisNode->songName);
printf("Artist Name: %s\n", thisNode->artistName);
printf("Song Length (in seconds): %d\n", thisNode->songLength);

return;
}


void DestroyPlaylistNode(PlaylistNode* thisNode){
/* Validate Parameters */
if(thisNode == NULL){
    return;
}
free(thisNode);
}
