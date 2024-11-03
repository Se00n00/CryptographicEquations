#ifndef MODULARMATH_H
#define MODULARMATH_H
#include<stdarg.h>
int MultiEuclidAlgoriithm(int Count_Of_Numbers, ...);
int EuclidAlgorithm(int Num1, int Num2);
int ExtendedEuclidAlorithm(int Integer, int Modulo);

//Returns the greatest common divisor of multiple number
int MultiEuclidAlgoriithm(int Count_Of_Numbers, ...){
    va_list args;
    va_start(args, Count_Of_Numbers);

    //Collect all Arguments
    int ARGS[Count_Of_Numbers];
    for(int i=0;i<Count_Of_Numbers;i++){
        ARGS[i] = va_arg(args,int);
    }
    va_end(args);

    //Sorting All Collected Arguments : Bubble Sort
    for(int i=0; i<Count_Of_Numbers-1;i++){
        for(int j = 0;j<Count_Of_Numbers-i-1;j++){
            if(ARGS[j]>ARGS[j+1]){
                int num = ARGS[j];
                ARGS[j] = ARGS[j+1];
                ARGS[j+1] = num;
            }
        }
    }

    //Calculate the gcd pair-wise
    int GCD=0;
    int num1 = ARGS[0];
    int num2 = ARGS[1];
    for(int i=2; i<Count_Of_Numbers;i++){
        GCD = EuclidAlgorithm(num1 , num2);
        num2 = ARGS[i];
        num1 = GCD;
    }
    

    return GCD;
}
//Returns the greatest common divisor of two number
int EuclidAlgorithm(int Num1, int Num2){
    
    // Swap two numbers if Num1 < Num2
    if(Num1 < Num2){
        int temp = Num1;
        Num1 = Num2;
        Num2 = temp;
    }
    
    int Remainder = Num1 % Num2;
    while(Remainder != 0){
        Num1 = Num2;
        Num2 = Remainder;
        Remainder = Num1 % Num2;
    }
    return Num2;
}
// int Multiplicative(int )
int ExtendedEuclidAlorithm(int Integer, int Modulo){

    //Q D D R T1 T2 T
    Integer %= Modulo;
    int Divisor = Integer;
    int Quotient, Remainder;
    int Dividebend = Modulo;
    int T1 = 0;
    int T2 = 1;
    int T = 0;
    while(Divisor != 0){
        Quotient = (int)Dividebend/Divisor;
        Remainder = (int)Dividebend%Divisor;
        T = T1 - (T2*Quotient);

        Dividebend = Divisor;
        Divisor = Remainder;

        T1 = T2;
        T2 = T; 
    }
    return T1;
}
#endif