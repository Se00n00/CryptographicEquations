#ifndef SUBSTITUTIONCIPHERS_H
#define SUBSTITUTIONCIPHERS_H

#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "ModularMath.h"

struct originaltext_string{
    char *Message;
    char *EncryptionKey;
};
struct ciphertext_string{
    char *EncryptedMessage;
    char *EncryptionKey;
};

struct originaltext_int{
    char *Message;
    int EncryptionKey;
};
struct ciphertext_int{
    char *EncryptedMessage;
    int EncryptionKey;
};

struct originaltext_dual{
    char *Message;
    int Multiplier_EncryptionKey;
    int Adder_EncryptionKey;
};
struct ciphertext_dual{
    char *EncryptedMessage;
    int Multiplier_EncryptionKey;
    int Adder_EncryptionKey;
};

typedef struct originaltext_string OriginalText_S;
typedef struct ciphertext_string CipherText_S;
typedef struct originaltext_int OriginalText_I;
typedef struct ciphertext_int CipherText_I;
typedef struct originaltext_dual OriginalText_D;
typedef struct ciphertext_dual CipherText_D;

CipherText_I *Encrypt_CeaserCipher(OriginalText_I *);
CipherText_I *Encrypt_MultiplicativeCipher(OriginalText_S *);
CipherText_D *Encrypt_AffineCipher(OriginalText_D *);
CipherText_S *Encrypt_VigenenceCipher(OriginalText_S *);
CipherText_S *Encrypt_VernamCipher(OriginalText_S *);
CipherText_S *Encrypt_OneTimePadCipher(OriginalText_S *);
CipherText_S *Encrypt_PlayFairCipher(OriginalText_S *);
OriginalText_I *Decrypt_CeaserCipher(CipherText_I *);
OriginalText_I *Decrypt_MultiplicativeCipher(CipherText_I *);
OriginalText_D *Decrypt_AffineCipher(CipherText_D *);
OriginalText_S *Decrypt_VigenenceCipher(CipherText_S *);
OriginalText_S *Decrypt_VernamCipher(CipherText_S *);
OriginalText_S *Decrypt_OneTimePadCipher(CipherText_S *);
OriginalText_S *Decrypt_PlayFairCipher(CipherText_S *);
OriginalText_S *Decrypt_HillCipher(CipherText_S *);

void ScaleDownString(char *);
void ScaleUpString(char *);
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

void ScaleDownString(char *String){
    for(int i=0;i<strlen(String);i++){
        if(isUpperCharacter(String[i])){
            String[i] -= 64;
        }else{
            String[i] -= 96;
        }
    }
}

void ScaleUpString(char *String){
    for(int i=0;i<strlen(String);i++){
        String[i] += 64;
    }
}

CipherText_I *Encrypt_CeaserCipher(OriginalText_I *Original){
    CipherText_I *temp = (CipherText_I *)malloc(sizeof(CipherText_I));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->EncryptedMessage);

    // Encrypt
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        temp->EncryptedMessage[i] += temp->EncryptionKey;
        temp->EncryptedMessage[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);

    return temp;
}

CipherText_I *Encrypt_MultiplicativeCipher(OriginalText_I *Original){
    CipherText_I *temp = (CipherText_I *)malloc(sizeof(CipherText_I));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->EncryptedMessage);

    // Encrypt
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        temp->EncryptedMessage[i] *= temp->EncryptionKey;
        temp->EncryptedMessage[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);
    
    return temp;
}

CipherText_D *Encrypt_AffineCipher(OriginalText_D *Original){
    CipherText_D *temp = (CipherText_D *)malloc(sizeof(CipherText_D));
    temp->EncryptedMessage = Original->Message;
    temp->Adder_EncryptionKey = Original->Adder_EncryptionKey;
    temp->Multiplier_EncryptionKey = Original->Multiplier_EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->Adder_EncryptionKey == NULL && Original->Multiplier_EncryptionKey) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->EncryptedMessage);

    // Encrypt
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        temp->EncryptedMessage[i] += temp->Adder_EncryptionKey;
        temp->EncryptedMessage[i] *= temp->Multiplier_EncryptionKey;
        temp->EncryptedMessage[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);
    
    return temp;
}

CipherText_S *Encrypt_VigenenceCipher(OriginalText_S *Original){
    CipherText_S *temp = (CipherText_S *)malloc(sizeof(CipherText_S));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->EncryptedMessage);
    ScaleDownString(temp->EncryptionKey);

    // Encrypt
    int j = 0;
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        if(j == strlen(temp->EncryptionKey)) j = 0;
        temp->EncryptedMessage[i] += temp->EncryptionKey[j];
        temp->EncryptedMessage[i] /= 26;
        j++;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

CipherText_S *Encrypt_VernamCipher(OriginalText_S *Original){
    CipherText_S *temp = (CipherText_S *)malloc(sizeof(CipherText_S));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->EncryptedMessage);
    ScaleDownString(temp->EncryptionKey);
    
    // Encrypt
    int j = 0;
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        if(j == strlen(temp->EncryptionKey)) j = 0;
        temp->EncryptedMessage[i] ^= temp->EncryptionKey[j];
        temp->EncryptedMessage[i] /= 26;
        j++;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

CipherText_S *Encrypt_OneTimePadCipher(OriginalText_S *Original){
    CipherText_S *temp = (CipherText_S *)malloc(sizeof(CipherText_S));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL) return temp;

    // If Length of Original Text Does not equals to the Key, Return the Ciphertext as it is
    if(strlen(temp->EncryptedMessage) != strlen(temp->EncryptionKey)) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->EncryptedMessage);
    ScaleDownString(temp->EncryptionKey);

    // Encrypt
    for(int i=0;i<strlen(temp->EncryptedMessage);i++){
        temp->EncryptedMessage[i] += temp->EncryptionKey[i];
        temp->EncryptedMessage[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->EncryptedMessage);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

CipherText_S *Encrypt_PlayFairCipher(OriginalText_S *Original){
    CipherText_S *temp = (CipherText_S *)malloc(sizeof(CipherText_S));
    temp->EncryptedMessage = Original->Message;
    temp->EncryptionKey = Original->EncryptionKey;

    // If Original Text contains null values, Return the Ciphertext as it is
    if(Original->Message == NULL && Original->EncryptionKey == NULL)return temp;

    ScaleDownString(Original->Message);
    ScaleUpString(Original->Message);

    char Matrix[5][5];
    int k = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(k <strlen(Original->Message));
            Matrix[i][j] = Original->Message[k];
        }
    }
}

OriginalText_I *Decrypt_CeaserCipher(CipherText_I *Encrypted){
    OriginalText_I *temp = (OriginalText_I *)malloc(sizeof(OriginalText_I));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->Message);

    for(int i=0;i<strlen(temp->Message);i++){
        temp->Message[i] -= temp->EncryptionKey;
        temp->Message[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);

    return temp;
}

OriginalText_I *Decrypt_MultiplicativeCipher(CipherText_I *Encrypted){
    OriginalText_I *temp = (OriginalText_I *)malloc(sizeof(OriginalText_I));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->Message);

    // Get the Multiplicative Inverse of Encryption Key
    temp->EncryptionKey = MultiplicativeInverse(temp->EncryptionKey, 26);
    if(temp->EncryptionKey == -1) return temp;

    // Decrypt
    for(int i=0;i<strlen(temp->Message);i++){
        temp->Message[i] *= temp->EncryptionKey;
        temp->Message[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);

    return temp;
}

OriginalText_D *Decrypt_AffineCipher(CipherText_D *Encrypted){
    OriginalText_D *temp = (OriginalText_D *)malloc(sizeof(OriginalText_D));
    temp->Message = Encrypted->EncryptedMessage;
    temp->Adder_EncryptionKey = Encrypted->Adder_EncryptionKey;
    temp->Multiplier_EncryptionKey = Encrypted->Multiplier_EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->Adder_EncryptionKey == NULL && Encrypted->Multiplier_EncryptionKey == NULL) return temp;

    // Scale the Values of Message between 0 - 26
    ScaleDownString(temp->Message);

    // Get the Multiplicative Inverse of Encryption Key
    temp->Multiplier_EncryptionKey = MultiplicativeInverse(temp->Multiplier_EncryptionKey, 26);
    if(temp->Multiplier_EncryptionKey == -1) return temp;

    // Decrypt
    for(int i=0;i<strlen(temp->Message);i++){
        temp->Message[i] -= temp->Adder_EncryptionKey;
        temp->Message[i] *= temp->Multiplier_EncryptionKey;
        temp->Message[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);

    return temp;
}

OriginalText_S *Decrypt_VigenenceCipher(CipherText_S *Encrypted){
    OriginalText_S *temp = (OriginalText_S *)malloc(sizeof(OriginalText_S));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->Message);
    ScaleDownString(temp->EncryptionKey);

    // Decrypt
    int j = 0;
    for(int i=0;i<strlen(temp->Message);i++){
        if(j == strlen(temp->EncryptionKey)) j = 0;
        temp->Message[i] -= temp->EncryptionKey[j];
        temp->Message[i] /= 26;
        j++;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

OriginalText_S *Decrypt_VernamCipher(CipherText_S *Encrypted){
    OriginalText_S *temp = (OriginalText_S *)malloc(sizeof(OriginalText_S));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->Message);
    ScaleDownString(temp->EncryptionKey);

    // Decrypt
    int j = 0;
    for(int i=0;i<strlen(temp->Message);i++){
        if(j == strlen(temp->EncryptionKey)) j = 0;
        temp->Message[i] ^= temp->EncryptionKey[j];
        temp->Message[i] /= 26;
        j++;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

OriginalText_S *Decrypt_OneTimePadCipher(CipherText_S *Encrypted){
    OriginalText_S *temp = (OriginalText_S *)malloc(sizeof(OriginalText_S));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;

    // If Length of CipherText Does not equals to the Key, Return the Oringinal Text as it is
    if(strlen(temp->Message) != strlen(temp->EncryptionKey)) return temp;

    // Scale the Values of Message & EncryptionKey between 0 - 26
    ScaleDownString(temp->Message);
    ScaleDownString(temp->EncryptionKey);

    // Decrypt
    for(int i=0;i<strlen(temp->Message);i++){
        temp->Message[i] -= temp->EncryptionKey[i];
        temp->Message[i] /= 26;
    }

    // Scale the values back to the UpperCase Values
    ScaleUpString(temp->Message);
    ScaleUpString(temp->EncryptionKey);

    return temp;
}

OriginalText_S *Decrypt_PlayFairCipher(CipherText_S *Encrypted){
    OriginalText_S *temp = (OriginalText_S *)malloc(sizeof(OriginalText_S));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;
}

OriginalText_S *Decrypt_HillCipher(CipherText_S *Encrypted){
    OriginalText_S *temp = (OriginalText_S *)malloc(sizeof(OriginalText_S));
    temp->Message = Encrypted->EncryptedMessage;
    temp->EncryptionKey = Encrypted->EncryptionKey;

    // If CipherText contains null values, Return the Original Text as it is
    if(Encrypted->EncryptedMessage == NULL && Encrypted->EncryptionKey == NULL) return temp;
}

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