#ifndef KEYHANDLER_H
#define KEYHANDLER_H
#include<stdlib.h>
#include<stdio.h>
#include "Utility.h"

//Key List Data Structure
struct Node{
    struct Node *Next;
    int KeyId;
    char *Key;
};
typedef struct Node KeyNODE;
int Id = 1;
KeyNODE *START = NULL;
KeyNODE *TERMAINAL = NULL;

int AddToKeyList(char *Key){
    KeyNODE *temp = (KeyNODE *)malloc(sizeof(KeyNODE));
    temp->Key = Key;
    temp->KeyId = Id;
    Id++;

    if(START == NULL){
        START = temp;
        TERMAINAL = temp;
        return temp->KeyId;
    }else{
        TERMAINAL ->Next = temp;
        TERMAINAL = temp;
        return temp->KeyId;
    }
}

char *GetKeyFromKeyList(int KeyId){
    KeyNODE *temp = START;
    while(temp!=NULL){

        if(temp->KeyId == KeyId){
            return temp->Key;
        }
        temp = temp->Next;
    }
    return NULL;
}

int GeyIdFromKeyList(char *Key){
    KeyNODE *temp = START;
    while(temp!=NULL){
        if( areEqualString(temp->Key,Key)){
            return temp->KeyId;
        }
        temp = temp->Next;
    }
    return -1;
}
int DeleteFromKeyList(int KeyId){
    
    KeyNODE *temp = START;

    //Key at the Begining Node
    if(START->KeyId == KeyId){
        START = START->Next;
        temp->Next=NULL;
        free(temp);
        return 0;
    }

    //Key at else where
    while(temp!=NULL){
        if(temp->Next->KeyId == KeyId){
            KeyNODE *ptr = temp->Next;
            temp->Next = ptr->Next;
            ptr->Next = NULL;
            if(temp == NULL){
                TERMAINAL = temp;
            }
            free(ptr);
            return 0;
        }
        temp=temp->Next;
    }
    return -1;
}

void DisplayKeyList(){
    KeyNODE *temp = START;
    printf("\nKEY in KEYLIST ::\n");
    while(temp!=NULL){
        printf("KID :: %d\tKEY :: %s\n",temp->KeyId,temp->Key);
        temp = temp->Next;
    }
}

#endif