#ifndef UTILITY_H
#define UTILITY_H

#include<string.h>
#include<stdbool.h>

// Evaluate if Given Two Strings are Equal Or Not
bool areEqualString(char *Str1, char *Str2){
    int Str1_len = strlen(Str1);
    int Str2_len = strlen(Str2);

    if(Str1_len != Str2_len){
        return false;
    }else{
        for(int i=0;i<Str1_len;i++){
            if(Str1[i] != Str2[i]){
                return false;
            }
        }
    }
    return true;
}

// Return the KeyArray with ach of its item ranked
char *KeyInOrder(char *Key){
    char Encrypted_Key[strlen(Key)];
    
    //Copy the whole key text to Encrypted_Key
    for(int i=0;i<strlen(Key);i++){
        Encrypted_Key[i] = Key[i];
    }

    // Ranking the Encrypted_Key
    // Sort the Encrypted_key
    int Rank = strlen(Key);
    for(int i=0;i<strlen(Key);i++){
        int max = Key[0];
        for(int j=0;j<strlen(Key);j++){
            if(max<Encrypted_Key[j]){
                max = Encrypted_Key[j];
            }
        }
    }
}
#endif