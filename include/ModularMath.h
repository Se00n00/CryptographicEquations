#ifndef MODULARMATH_H
#define MODULARMATH_H

#include<stdlib.h>
#include<stdarg.h>
#include<stdbool.h>
#include<math.h>

/* modular: 
    moduliValue : Decimal Part,
    modulasValue : Mod Part
*/
struct modular{
    long long moduliValue;
    long long modulasValue;
};
typedef struct modular Modulus;

Modulus *ModularAddition(Modulus Mod1, Modulus Mod2);
Modulus *ModularSubtraction(Modulus Mod1, Modulus Mod2);
Modulus *ModularDivison(Modulus Mod1, Modulus Mod2);
Modulus *ModularMultiplication(Modulus Mod1, Modulus Mod2);
long long ModAddition(long long Number1, long long Number2, long long Modulus);
long long ModSubtraction(long long Number1, long long Number2, long long Modulus);
long long ModDivison(long long Number1, long long Number2, long long Modulus);
long long ModMultiplication(long long Number1, long long Number2, long long Modulus);
long long MultiEuclidAlgoriithm(int Count_Of_Numbers, long long Numbers[]);
long long EuclidAlgorithm(long long Num1, long long Num2);
long long ExtendedEuclidAlorithm(long long Number, long long Modulo);
long long MultipleModuli(int Count_Of_Moduli, Modulus Pairs[]);
long long MultiplicativeInverse(long long Number, long long Modulo);
Modulus *ModularMultiplicativeInverse(Modulus *);

Modulus *ModularAddition(Modulus Mod1, Modulus Mod2){
    Mod1.moduliValue %= Mod1.modulasValue;
    Mod2.moduliValue %= Mod2.modulasValue;

    Modulus *temp = (Modulus *)malloc(sizeof(Modulus));
    temp->moduliValue = 0;
    temp->modulasValue = 0;

    // If the Mod Values of both Input Don't Matches
    if(Mod1.modulasValue != Mod2.modulasValue){
        return temp;
    }

    temp->modulasValue = Mod1.modulasValue;
    temp->moduliValue = (Mod1.moduliValue + Mod2.moduliValue) % temp->modulasValue;

    return temp;
}

long long ModAddition(long long Number1, long long Number2, long long Modulus){
    Number1 %= Modulus;
    Number2 %= Modulus;

    return (Number1 + Number2) % Modulus;
}

Modulus *ModularSubtraction(Modulus Mod1, Modulus Mod2){
    Mod1.moduliValue %= Mod1.modulasValue;
    Mod2.moduliValue %= Mod2.modulasValue;

    Modulus *temp = (Modulus *)malloc(sizeof(Modulus));
    temp->moduliValue = 0;
    temp->modulasValue = 0;

    // If the Mod Values of both Input Don't Matches
    if(Mod1.modulasValue != Mod2.modulasValue){
        return temp;
    }

    temp->modulasValue = Mod1.modulasValue;
    temp->moduliValue = (Mod1.moduliValue - Mod2.moduliValue) % temp->modulasValue;

    return temp;
}

long long ModSubtraction(long long Number1, long long Number2, long long Modulus){
    Number1 %= Modulus;
    Number2 %= Modulus;

    return (Number1 - Number2) % Modulus;
}

Modulus *ModularDivison(Modulus Mod1, Modulus Mod2){
    Mod1.moduliValue %= Mod1.modulasValue;
    Mod2.moduliValue %= Mod2.modulasValue;

    Modulus *temp = (Modulus *)malloc(sizeof(Modulus));
    temp->moduliValue = 0;
    temp->modulasValue = 0;

    // If the Mod Values of both Input Don't Matches
    if(Mod1.modulasValue != Mod2.modulasValue){
        return temp;
    }

    temp->modulasValue = Mod1.modulasValue;
    temp->moduliValue = (Mod1.moduliValue / Mod2.moduliValue) % temp->modulasValue;

    return temp;
}

long long ModDivison(long long Number1, long long Number2, long long Modulus){
    Number1 %= Modulus;
    Number2 %= Modulus;

    return (Number1 / Number2) % Modulus;
}

Modulus *ModularMultiplication(Modulus Mod1, Modulus Mod2){
    Mod1.moduliValue %= Mod1.modulasValue;
    Mod2.moduliValue %= Mod2.modulasValue;

    Modulus *temp = (Modulus *)malloc(sizeof(Modulus));
    temp->moduliValue = 0;
    temp->modulasValue = 0;

    // If the Mod Values of both Input Don't Matches
    if(Mod1.modulasValue != Mod2.modulasValue){
        return temp;
    }

    temp->modulasValue = Mod1.modulasValue;
    temp->moduliValue = (Mod1.moduliValue * Mod2.moduliValue) % temp->modulasValue;

    return temp;
}

long long ModMultiplication(long long Number1, long long Number2, long long Modulus){
    Number1 %= Modulus;
    Number2 %= Modulus;

    return (Number1 * Number2) % Modulus;
}

/* Returns True if Inputs are relative prime, false otherwise */
bool IsRelativePrimes(long long Num1,long long Num2){
    return (EuclidAlgorithm(Num1,Num2) == 1)?true:false;
}

/* Returns the greatest common divisor of multiple number */
long long MultiEuclidAlgoriithm(int Count_Of_Numbers, long long Numbers[]){
    
    //Sorting All Collected Arguments : Bubble Sort
    for(int i=0; i<Count_Of_Numbers-1;i++){
        for(int j = 0;j<Count_Of_Numbers-i-1;j++){
            if(Numbers[j]>Numbers[j+1]){
                long long num = Numbers[j];
                Numbers[j] = Numbers[j+1];
                Numbers[j+1] = num;
            }
        }
    }

    //Calculate the gcd pair-wise
    long long GCD=0;
    long long num1 = Numbers[0], num2 = Numbers[1];
    for(int i=2; i<Count_Of_Numbers;i++){
        GCD = EuclidAlgorithm(num1 , num2);
        num2 = Numbers[i];
        num1 = GCD;
    }
    return GCD;
}

/* Returns the greatest common divisor of two number */
long long EuclidAlgorithm(long long Num1, long long Num2){
    
    // Swap two numbers if Num1 < Num2
    if(Num1 < Num2){
        long long temp = Num1;
        Num1 = Num2;
        Num2 = temp;
    }
    
    long long Remainder = Num1 % Num2;
    while(Remainder != 0){
        Num1 = Num2;
        Num2 = Remainder;
        Remainder = Num1 % Num2;
    }
    return Num2;
}

/* Returns (long long) Modular Inverse of given Integer with any Modular Value 
   If they are co-primes otherwise return -1 */
long long ExtendedEuclidAlorithm(long long Number, long long Modulo){

    if(!IsRelativePrimes(Number,Modulo)){
        return -1;
    }

    Number %= Modulo;
    long long Divisor = Number, Quotient, Remainder, Dividend = Modulo;
    long long T1 = 0,T2 = 1,T = 0;
    while(Divisor != 0){
        Quotient = Dividend/Divisor;
        Remainder = Dividend%Divisor;
        T = T1 - (T2*Quotient);

        Dividend = Divisor;
        Divisor = Remainder;

        T1 = T2;
        T2 = T; 
    }
    return (T1<0)?Modulo+T1:T1;
}

/* Returns the Integer that Would Satisfy the muliple modular Conditions
   Input: Count of Moduli pairs*/
long long MultipleModuli(int Count_Of_Moduli, Modulus Pairs[]){
    long long result = 0;
    long long M = 1;
    
    // Check if all are relative primes or not
    long long Moduli[Count_Of_Moduli];
    for(int i=0;i<Count_Of_Moduli;i++){
        Moduli[i] = Pairs[i].modulasValue;
    }
    if(MultiEuclidAlgoriithm(Count_Of_Moduli,Moduli) != 1){
        return -1;
    }

    // Calculate Multiple of all the moduli
    for(int i=0;i<Count_Of_Moduli;i++){
        M *= Pairs[i].modulasValue;
    }

    for(int i=0;i<Count_Of_Moduli;i++){
        long long CurrentM = M/Pairs[i].modulasValue;
        long long CurrentMInverse = ExtendedEuclidAlorithm(CurrentM,Pairs[i].modulasValue);
        result +=  CurrentM * CurrentMInverse * Pairs[i].moduliValue;
    }

    return result % M;
}

/* Return the Multiplicative Inverse of the Modulus */
Modulus *ModularMultiplicativeInverse(Modulus *Mod){
    Modulus *temp = (Modulus *)malloc(sizeof(Modulus));
    temp->moduliValue = -1;
    temp->modulasValue = Mod->modulasValue;

    if( IsRelativePrimes(Mod->moduliValue, Mod->modulasValue)){
        temp->moduliValue = (Mod->moduliValue, Mod->modulasValue);
        return temp;
    }
    return temp;
}

long long MultiplicativeInverse(long long Number, long long Modulo){
    if( IsRelativePrimes(Number, Modulo)){
        return ExtendedEuclidAlorithm(Number, Modulo);
    }
    return -1;
}
#endif