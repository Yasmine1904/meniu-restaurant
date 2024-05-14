

#ifndef LAB9_10POO_REPO_H
#define LAB9_10POO_REPO_H
#include <vector>
#include "entitate.h"
#include "ElementNotFoundException.h"
#include "InvalidCodeExc.h"
#pragma once

class Repo{
private:
    vector<Meniu> Meniuri;
public:
    Repo()
    {
        this->Meniuri.reserve(0);
    }

    ~Repo()
    {
        this->Meniuri.clear();
    }


    int getSize()
    {
        return this->Meniuri.size();
    }

    void adauga(int id, char* mancare, int comenzi)
    {
//        Meniu meniu(id,mancare,comenzi);
//        Meniuri.push_back(meniu);
        int ok=0;
        Meniu meniu(id,mancare,comenzi);
        vector<Meniu> lista = getAll();
        for(int i=0;i<lista.size();i++)
            if(id==lista[i].getId())
                ok=1;
        if(ok==0)
            Meniuri.push_back(meniu);
        else
            throw ElementNotFoundException("id-ul exista deja in meniu");
    }


    void actualizeaza(int index, const char* mancare, int comenzi) {
        if (index < 0 || index >= Meniuri.size()) {
            cout << "Indexul este invalid!" << endl;
            return;
        }

        Meniuri[index].setMancare((char*)mancare);
        Meniuri[index].setComenzi(comenzi);
    }

    void sterge(int pos)
    {
//        Meniuri.erase(Meniuri.begin()+pos);
        if(Meniuri.cbegin()+pos == Meniuri.end())
            throw ElementNotFoundException("pozitia nu exista");
//            cout<<"poz nu exista"<<endl;
        else
            Meniuri.erase(Meniuri.cbegin()+pos);

    }

    void setAll(vector<Meniu> nou)
    {
        swap(this->Meniuri,nou);
    }


    vector<Meniu> getAll()
    {
        return this->Meniuri;
    }

};


#endif //LAB9_10POO_REPO_H
