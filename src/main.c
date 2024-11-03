#include<stdio.h>
#include "TranspositionCiphers.h"
#include "KeyHandler.h"
#include "ModularMath.h"

int main(){
    // char Message[] = "GeeksforGeeks";
    // char Key2[] = "This is Key2";
    // // RailFenceEncryption(Message, 3);
    // int id1 = AddToKeyList(Message);
    // int id2 = AddToKeyList(Key2);
    // DisplayKeyList();
    // printf("Key:: %s\tId:: %d",GetKeyFromKeyList(id2),GeyIdFromKeyList(Key2));
    // DeleteFromKeyList(id2);
    // DisplayKeyList();

    printf("%d ",ExtendedEuclidAlorithm(3, 11));
}