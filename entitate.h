

#ifndef LAB9_10POO_ENTITATE_H
#define LAB9_10POO_ENTITATE_H
#include <iostream>
using namespace std;

class Meniu{

private:
    int id, comenzi;
    char* mancare;
public:
    Meniu();
    Meniu(int id,char* mancare,int comenzi);
    Meniu(const Meniu &c);
    ~Meniu();
    int getId();
    int getComenzi();
    char* getMancare();
    void setId(int s);
    void setComenzi(int z);
    void setMancare(char *n);
    Meniu& operator=(const Meniu &p);
    bool operator==(const Meniu &p);
    friend ostream& operator<<(ostream& os, const Meniu& c)
    {
        os<<"id: "<<c.id<<" "<<"mancare: "<<c.mancare<<" "<<"comenzi: "<<c.comenzi<<endl;
        return os;
    }
};


#endif //LAB9_10POO_ENTITATE_H
