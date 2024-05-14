

#ifndef LAB9_10POO_INVALIDCODEEXC_H
#define LAB9_10POO_INVALIDCODEEXC_H

#include "stdexcept"
#include <iostream>
using namespace std;

class InvalidCodeException:public invalid_argument{
private:
    char* mesaj;
public:
    InvalidCodeException(char *msg): invalid_argument(msg), mesaj(msg){
    }

    char* what()
    {
        return mesaj;
    }
};

#endif //LAB9_10POO_INVALIDCODEEXC_H
