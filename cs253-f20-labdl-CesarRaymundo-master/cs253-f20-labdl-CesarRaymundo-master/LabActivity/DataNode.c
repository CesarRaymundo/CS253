#include <time.h>
#include <stdio.h>
#include "DataNode.h"

DataNode* CreateDataNode(const char data[]){
    if(data == NULL){
        return NULL;
    }
    DataNode * thisNode = (DataNode *) malloc(sizeof(DataNode));
    char * heapString = (char *) malloc(sizeof(data[0]) * strlen(data));
    if(thisNode == NULL || heapString == NULL){
        return NULL;
    }
    
    thisNode->dataSize = sizeof(DataNode);
    strncpy(heapString, data, strlen(data) + 1);
    thisNode->dataValue = heapString;
    thisNode->nextNodePtr = NULL;
  
    
return thisNode;
}

int InsertDataNodeAfter(DataNode* nodeInList, DataNode* newNode){
    DataNode* tmpNext = NULL;
/* Validates parameters */
if(nodeInList == NULL || newNode == NULL){
    return -1;
}

tmpNext = nodeInList->nextNodePtr;
nodeInList->nextNodePtr = newNode;
newNode->nextNodePtr = tmpNext;

return 0;
}


int SetNextDataNode(DataNode* nodeInList, DataNode* newNode){
    /* Validate parameter */
if(nodeInList == NULL){
    return -1;
}
nodeInList->nextNodePtr = newNode;
return 0;
}

DataNode* GetNextDataNode(DataNode* nodeInList){
    /* Validate parameter */
if(nodeInList == NULL){
    return NULL;
}
return nodeInList->nextNodePtr;

}

void PrintDataNode(DataNode* thisNode){
    /* Validate parameter */
if(thisNode == NULL){
    return;
}
printf("%s\n", thisNode->dataValue);
thisNode = thisNode->nextNodePtr;
return;
}

void DestroyDataNode(DataNode* thisNode){
    /* Validate Parameters */
if(thisNode == NULL){
    return;
}
free(thisNode);
}

DataNode* BuildDataList(char * data[], int numElements){
    DataNode * listHead = NULL;
    DataNode * listTail = NULL;
    DataNode * current = NULL;
    int listSize = 0;


    for (int i = 0; i < numElements; i++){
        current = CreateDataNode(data[i]);
        if (listSize == 0){
            listHead = current;
            listTail =current;
        }else if (listSize == 1){
            InsertDataNodeAfter(listHead,current);
            listTail=current;
        }else { 
            InsertDataNodeAfter(listTail,current);
            listTail = current;
        }
        listSize++;
    }
    return listHead;
}


int GetDataListSize(DataNode* listHead){
    DataNode * current = listHead;
    if(listHead == NULL){
        return -1;
    }
    int size = 0;
    while(current != NULL){
        size++;
        current = current->nextNodePtr;
    }
    return size;
}

void PrintDataList(DataNode *listHead){
DataNode * current = listHead;
while (current != NULL)
{
    if (current->nextNodePtr != NULL)
    {
        printf("%s, ", current->dataValue);
    }else
    {
        printf("%s\n", current->dataValue);
    }
    current = current->nextNodePtr;
    
}
}

DataNode* GetRandomDataNode(DataNode *listHead){
    if(listHead == NULL){
        return NULL;
    }
    srand(time(0));
    DataNode * current = listHead;
    int random = GetDataListSize(listHead);
    int index = rand() % random;
    for(int i = 0; i<index; i++){
        current = current->nextNodePtr;
    }
    return current;
}

void DestroyDataList(DataNode* listHead){
    free(listHead);
}

