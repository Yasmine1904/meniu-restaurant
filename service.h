

#ifndef LAB9_10POO_SERVICE_H
#define LAB9_10POO_SERVICE_H

#include "repo.h"
#include "RepoFile.h"
#include "entitate.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "ElementNotFoundException.h"
#include "InvalidCodeExc.h"
#pragma once



class Service {
private:
    //Repo repo;
    RepoFile repo;
public:
    Service() {
        this->repo = RepoFile();
    }

    Service(const RepoFile &repo)  {
        this->repo = repo;
    }

    ~Service() {};

    void adaugareService(int id, char* mancare, int comenzi) {
        this->repo.adauga(id,mancare,comenzi);
    }

    vector<Meniu> getAllService() {
        return this->repo.getAll();
    }

    void afisareService() {
        vector<Meniu> lista = getAllService();
        Afis(lista);
    }

    void Afis(vector<Meniu> lista) {
        if (lista.size() == 0) cout << "Lista dupa criteriu este goala!" << endl << endl;
        for (int i = 0; i < lista.size(); i++) {
            cout << lista[i];
//            cout << endl;
        }
    }
    void eliminareDupaId(int id)
    {   int ok=0;
        vector<Meniu> lista= getAllService();
//        vector<Meniu> nou;
        for(int i=0;i<lista.size();i++)
            if(id==lista[i].getId())   //cu !=
            {
//                nou.push_back(lista[i]);
//                repo.setAll(nou);
                repo.sterge(i);
                ok=1;
            }
        if(ok==0)
            throw ElementNotFoundException("id-ul nu exista");

//        this->repo.sterge(id-1);
    }
    void modificare(int id, const char* mancare, int comenzi)
    {
        int ok=0;
        vector<Meniu> lista= getAllService();
        for(int i=0;i<lista.size();i++)
            if(id==lista[i].getId()) {
                this->repo.actualizeaza(i, mancare, comenzi);
                ok=1;
            }
        if (ok==0);
            throw ElementNotFoundException("id-ul nu exista");

    }
    void afiseazaDupaNrCom(int comenzi)
    {
        vector<Meniu> lista= getAllService();
        vector<Meniu> nou;
        for(int i=0;i<lista.size();i++)
            if(lista[i].getComenzi()>comenzi)
                nou.push_back(lista[i]);
        Afis(nou);
    }
    int sumaComenzi()
    {
        vector<Meniu> lista= getAllService();
        vector<Meniu> nou;
        int s=0;
        for(int i=0;i<lista.size();i++)
            s+=lista[i].getComenzi();
        return s;
    }
    void eliminareDupaComenzi(int comenzi)
    {
        vector<Meniu> lista= getAllService();
        vector<Meniu> nou;
        for(int i=0;i<lista.size();i++)
            if(comenzi<=lista[i].getComenzi())
                nou.push_back(lista[i]);
        Afis(nou);

    }
    void initializareFisier()
    {
        this->repo.setUP();
    }

    void copiereFisier()
    {
        this->repo.setIN(getAllService());
    }

};


#endif //LAB9_10POO_SERVICE_H
