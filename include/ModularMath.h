#ifndef MODULARMATH_H
#define MODULARMATH_H

#include<stdarg.h>
#include<stdbool.h>
#include<math.h>

// Euler Totent' Function
// Primality Test
// Fermat Factoring Method

// Primitive Roots


struct modulipairs{
    long long Modular;
    long long IntegerValue;
};
typedef struct modulipairs Moduli;

bool IsRelativePrimes(long long Num1,long long Num2);
bool IsPrimitiveRoot(long long Number1, long long Number2);
long long MultiEuclidAlgoriithm(int Count_Of_Numbers, long long Numbers[]);
long long EuclidAlgorithm(long long Num1, long long Num2);
long long ExtendedEuclidAlorithm(long long Number, long long Modulo);
long long MultipleModuli(int Count_Of_Moduli, Moduli Pairs[]);

/* Returns True if Inputs are relative prime, false otherwise */
bool IsRelativePrimes(long long Num1,long long Num2){
    return (EuclidAlgorithm(Num1,Num2) == 1)?true:false;
}


// [WOULD REQUIRE EULER TOTENT FUNCTION]
/* Returns True if Number1 is primitive root of Number2 */
// bool IsPrimitiveRoot(long long Number1, long long Number2){
    
//     bool isprimitiveroot = true;
//     int Number_Of_Co_primes = 0;
    

//     for(int i=1;i<Number2;i++){
//         if( IsRelativePrimes(i,Number2) ){
//             Number_Of_Co_primes++;
//         }
//     }
//     long long NumberModule[Number_Of_Co_primes];
//     // for(int )
//     return isprimitiveroot;
// }

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
long long MultipleModuli(int Count_Of_Moduli, Moduli Pairs[]){
    long long result = 0;
    long long M = 1;
    
    // Check if all are relative primes or not
    long long Moduli[Count_Of_Moduli];
    for(int i=0;i<Count_Of_Moduli;i++){
        Moduli[i] = Pairs[i].Modular;
    }
    if(MultiEuclidAlgoriithm(Count_Of_Moduli,Moduli) != 1){
        return -1;
    }

    // Calculate Multiple of all the moduli
    for(int i=0;i<Count_Of_Moduli;i++){
        M *= Pairs[i].Modular;
    }

    for(int i=0;i<Count_Of_Moduli;i++){
        long long CurrentM = M/Pairs[i].Modular;
        long long CurrentMInverse = ExtendedEuclidAlorithm(CurrentM,Pairs[i].Modular);
        result +=  CurrentM * CurrentMInverse * Pairs[i].IntegerValue;
    }

    return result % M;
}
#endif