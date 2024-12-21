#ifndef SUBSTITUTIONCIPHERS_H
#define SUBSTITUTIONCIPHERS_H

#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct originaltext_string{
    char *Message;
    char *EncryptionKey;
};
typedef struct originaltext_string OriginalText_S;

struct ciphertext_string{
    char *EncryptedMessage;
    char *EncryptionKey;
};
typedef struct ciphertext_string CipherText_S;

struct originaltext_int{
    char *Message;
    int EncryptionKey;
};
typedef struct originaltext_int OriginalText_I;

struct ciphertext_int{
    char *EncryptedMessage;
    int EncryptionKey;
};
typedef struct ciphertext_int CipherText_I;


CipherText *Encrypt_CeaserCipher(OriginalText *);
CipherText *Encrypt_MultiplicativeCipher(OriginalText_S *);
CipherText *Encrypt_AffineCipher(OriginalText *);
CipherText *Encrypt_VigenenceCipher(OriginalText *);
CipherText *Encrypt_VernamCipher(OriginalText *);
CipherText *Encrypt_OneTimePadCipher(OriginalText *);
CipherText *Encrypt_PlayFairCipher(OriginalText *);
CipherText *Encrypt_HillCipher(OriginalText *);
OriginalText *Decrypt_CeaserCipher(CipherText *);
OriginalText *Decrypt_MultiplicativeCipher(CipherText *);
OriginalText *Decrypt_AffineCipher(CipherText *);
OriginalText *Decrypt_VigenenceCipher(CipherText *);
OriginalText *Decrypt_VernamCipher(CipherText *);
OriginalText *Decrypt_OneTimePadCipher(CipherText *);
OriginalText *Decrypt_PlayFairCipher(CipherText *);
OriginalText *Decrypt_HillCipher(CipherText *);

void ConvertText(char *);
bool isLowerCharacter(char);
bool isUpperCharacter(char);
bool isAlphaCharacter(char);

bool isUpperCharacter(char C){
    if(C >= 65 && C <= 90){
        return true;
    }
    return false;
}
bool isLowerCharacter(char C){
    if(C >= 65 && C <= 90){
        return false;
    }
    return true;
}

bool isAlphaCharacter(char C){
    if((C >= 65 && C <= 90)&&(C >= 97 && C <= 122)){
        return true;
    }
    return false;
}

bool isAlphaString(char *String){
    for(int i=0;i<strlen(String);i++){
        if(!isAlphaCharacter(String[i])){
            return false;
        }
    }
    return true;
}

void ConvertText(char *String){
    for(int i=0;i<strlen(String);i++){
        if(isUpperCharacter(String[i])){
            String[i] -= 64;
        }else{
            String[i] -= 96;
        }
    }
}

CipherText *Encrypt_CeaserCipher(OriginalText *Original){
    CipherText *temp = (CipherText *)malloc(sizeof(CipherText));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    if(isAlphaString(Original->EncryptionKey) && Original->Message){
        ConvertText(temp->EncryptedMessage);

    }
    return temp;
}
// CipherText *Encrypt_MultiplicativeCipher(OriginalText *);
// CipherText *Encrypt_AffineCipher(OriginalText *);
// CipherText *Encrypt_VigenenceCipher(OriginalText *);
// CipherText *Encrypt_VernamCipher(OriginalText *);
// CipherText *Encrypt_OneTimePadCipher(OriginalText *);
// CipherText *Encrypt_PlayFairCipher(OriginalText *);
// CipherText *Encrypt_HillCipher(OriginalText *);
// OriginalText *Decrypt_CeaserCipher(CipherText *);
// OriginalText *Decrypt_MultiplicativeCipher(CipherText *);
// OriginalText *Decrypt_AffineCipher(CipherText *);
// OriginalText *Decrypt_VigenenceCipher(CipherText *);
// OriginalText *Decrypt_VernamCipher(CipherText *);
// OriginalText *Decrypt_OneTimePadCipher(CipherText *);
// OriginalText *Decrypt_PlayFairCipher(CipherText *);
// OriginalText *Decrypt_HillCipher(CipherText *);

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