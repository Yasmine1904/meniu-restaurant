
#ifndef LAB9_10POO_NRNATURALEXC_H
#define LAB9_10POO_NRNATURALEXC_H
#include "InvalidCodeExc.h"

class NrNatural{
private:
    int nr;
public:
    NrNatural(int nrDat):nr(nrDat){}

    void validare(int nrDat)
    {
        if(nrDat<nr)
            throw InvalidCodeException("Numarul trebuie sa fie natural");
    }
};

#endif //LAB9_10POO_NRNATURALEXC_H
