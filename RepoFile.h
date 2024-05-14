

#ifndef LAB9_10POO_REPOFILE_H
#define LAB9_10POO_REPOFILE_H


#pragma once
#include "Repo.h"
#include <vector>
#include <cstring>
#include <fstream>


class RepoFile: public Repo{
private:
    char fisier[20];
public:
    RepoFile():Repo()
    {
        strcpy(this->fisier, "");
    }
    RepoFile(char* t):Repo()
    {
        strcpy(this->fisier, t);
    }
    ~RepoFile(){
    }
    void setUP();
    void setIN(vector<Meniu> lista);
};
#endif //LAB9_10POO_REPOFILE_H
