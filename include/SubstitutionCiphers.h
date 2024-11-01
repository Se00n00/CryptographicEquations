#ifndef SUBSTITUTIONCIPHERS_H
#define SUBSTITUTIONCIPHERS_H

#include<string.h>
#include<ctype.h>

char *CeaserCipherEncrypt(char *Message, int Key=0){
    Key %=26;
    char Encrypted[strlen(Message)];

    //Encrypt and store the message in Encrypted String
    for(int i=0;i<strlen(Message); i++){
        if(islower(Message[i])){
            Encrypted[i] = (Message[i] + Key - 'a')%26 + 'a';
        }else if(isupper(Message[i])){
            Encrypted[i] = (Message[i] + Key - 'A')%26 + 'A';
        }else{
            continue;
        }
    }

    return Encrypted;
}

char *CeaserCipherEncrypt(char *CryptedMessage, int Key=0){
    Key %=26;
    char Decrypted[strlen(CryptedMessage)];

    //Decrypt and store the message in Decrypted String
    for(int i=0;i<strlen(CryptedMessage); i++){
        if(islower(CryptedMessage[i])){
            Decrypted[i] = (CryptedMessage[i] - Key - 'a' + 26)%26 + 'a';
        }else if(isupper(CryptedMessage[i])){
            Decrypted[i] = (CryptedMessage[i] - Key - 'A' + 26)%26 + 'A';
        }else{
            continue;
        }
    }

    return Decrypted;
}

#endif