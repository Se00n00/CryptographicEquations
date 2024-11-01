#ifndef MODULARMATH_H
#define MODULARMATH_H


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