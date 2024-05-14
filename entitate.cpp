

#include "entitate.h"
#include <iostream>
#include <cstring>


using namespace std;

Meniu::Meniu() {
    this->id=0;
    this->comenzi=0;
    this->mancare= nullptr;
}
Meniu::Meniu(const int id,char *mancare,const int comenzi) {
    this->mancare = new char[strlen(mancare) + 1];
    strcpy_s(this->mancare, strlen(mancare)+1, mancare);
    this->id = id;
    this->comenzi=comenzi;

}
Meniu::Meniu(const Meniu &c) {
    this->mancare = new char[strlen(c.mancare) + 1];
    strcpy_s(this->mancare, strlen(c.mancare)+1, c.mancare);
    this->id = c.id;
    this->comenzi=c.comenzi;

}
Meniu::~Meniu() {
    if (this->mancare){
        delete[] this->mancare;
        this->mancare = nullptr;
    }

}

int Meniu::getId() {
    return this->id;
}

int Meniu::getComenzi() {
    return this->comenzi;
}

char *Meniu::getMancare() {
    return this->mancare;
}

void Meniu::setId(int s) {
    this->id=s;
}

void Meniu::setComenzi(int z) {
    this->comenzi=z;
}

void Meniu::setMancare(char *n) {
    if (this->mancare){
        delete[] this->mancare;
    }
    this->mancare = new char[strlen(n) + 1];
    strcpy_s(this->mancare, strlen(n) + 1, n);
}

Meniu &Meniu::operator=(const Meniu &p) {
    this->setId(p.id);
    this->setComenzi(p.comenzi);
    this->setMancare(p.mancare);
    return *this;
}

bool Meniu::operator==(const Meniu &p) {
    return ((strcmp(this->mancare, p.mancare) == 0) && (this->id == p.id)&&(this->comenzi==p.comenzi));
}

