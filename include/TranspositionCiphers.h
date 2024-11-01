#ifndef TRANSPOSITIONCIPHERS_H
#define TRANSPOSITIONCIPHERS_H
#include "Utility.h"
#include "KeyHandler.h"
#include<stdio.h>
#include<string.h>

void RailFenceEncryption(char *Message, int depth){
    int Message_len = strlen(Message);
    char Encryption_Matrix[depth][Message_len];

    // for(int i)

    for(int i=0;i<depth;i++){
        for(int j=0;j<Message_len;j++){
            Encryption_Matrix[i][j] = 0;
            printf("%d ",Encryption_Matrix[i][j]);
        }
        printf("\n");
    }

    // for(int i=0;i<Message_len;i++){
    //     // int j = dep
    //     Encryption_Matrix[i%depth][i] = Message[i];
    // }
    int k = 0;
    int j = 0;
    while(k<Message_len){
        while(j<depth&k<Message_len){
            Encryption_Matrix[j][k] = Message[k];
            k++;
            j++;
        }
        j=j-2;
        while(j>0&k<Message_len){
            Encryption_Matrix[j][k] = Message[k];
            k++;
            j--;
        }
        // j++;
        // for(int j=0;j<depth&k<Message_len;j++){
        //     Encryption_Matrix[j][k] = Message[k];
        //     k++;
        // }
        // for(int j = depth-1&k<Message_len;j<0;j--){
        //     Encryption_Matrix[j][k] = Message[k];
        //     k++;
        // }
        // k++;
    }
    // for(int i=0;i<Message_len;i=i+depth){
        
    // }
    // for(int i=1;i<depth;i++){
    //     for(int j=0;j<Message_len;j++){

    //     }
    // }
    for(int i=0;i<depth;i++){
        for(int j=0;j<Message_len;j++){
            printf("%c ",Encryption_Matrix[i][j]);
        }
        printf("\n");
    }
    // return NULL
}

void RowColumnEncryption(char *Message, char *Key){
    
    int KeyId = AddToKeyList(Key);
    int Key_len = strlen(Key);
    int Message_len = strlen(Message);
    int rows;
    if(Message_len%Key_len == 0){
        rows = Message_len/Key_len;
    }else{
        rows = Message_len/Key_len +1;
    }
    char Encryption_Matrix[rows][Key_len];
    char *Ordered_Key = KeyInOrder(Key);
}
#endif
