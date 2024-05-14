

#ifndef LAB9_10POO_ELEMENTNOTFOUNDEXCEPTION_H
#define LAB9_10POO_ELEMENTNOTFOUNDEXCEPTION_H

#include "stdexcept"
#include <iostream>
using namespace std;

class ElementNotFoundException :
        public runtime_error{
private:
    char* message;
public:
    ElementNotFoundException(char* msg):
            runtime_error(msg), message(msg){
    }
    char* what(){
        return message;
    }

};

#endif //LAB9_10POO_ELEMENTNOTFOUNDEXCEPTION_H
