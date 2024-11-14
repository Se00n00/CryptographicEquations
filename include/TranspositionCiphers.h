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

//Encrypt the Given Message and Key Using Row-Column Transposition Cipher
char *RowColumn(char *Message,int Key[], int Key_len){
    int Message_len = strlen(Message);
    int rows;
    if(Message_len%Key_len == 0){
        rows = Message_len/Key_len;
    }else{
        rows = Message_len/Key_len +1;
    }
    char EncryptionMatrix[rows][Key_len];
    int k = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<Key_len;j++){
            if(k<Message_len){
                EncryptionMatrix[i][j] = Message[k];
                k++;
            }else{
                EncryptionMatrix[i][j] = ' ';
            }
        }
    }
    char *CryptedMessage = (char *)malloc((rows*Key_len+1)*sizeof(char));
    int idx = 0;
    for (int i = 0; i < Key_len; i++) {
        int col = Key[i]-1;
        idx = (col*rows);
        for (int j = 0; j < rows; j++) {
            CryptedMessage[idx] = EncryptionMatrix[j][i];
            printf("%c ", CryptedMessage[idx]);
            idx++;
            
        }
    }   

    CryptedMessage[rows*Key_len] = '\0';
    return CryptedMessage;
}

//Decrypt the Given Crypted Message that had been encrypted Using Row-Column Transposiition
char *RowColumnDecryption(char *CryptedMessage,int Key[], int Key_len){
    int Message_len = strlen(CryptedMessage);
    int rows = Message_len/Key_len;
    char EncryptionMatrix[rows][Key_len];

    int idx = 0;
    for(int i=0;i<Key_len;i++){
        for(int j=0;j<rows;j++){
            EncryptionMatrix[i][j] = CryptedMessage[Key[0]-1];
        }
    }
    char *DecryptedMessage = (char *)malloc((Message_len+1)*sizeof(char));
    int idx = 0;
    for (int i = 0; i < Key_len; i++) {
        int col = Key[i]-1; // Adjusting index to 0-based
        // printf
        idx = (col*rows);
        for (int j = 0; j < rows; j++) {
            CryptedMessage[idx] = EncryptionMatrix[j][i];
            printf("%c ", CryptedMessage[idx]);
            idx++;
            
        }
    }   

    CryptedMessage[rows*Key_len] = '\0';
    return CryptedMessage;
}

#endif
