#include "repoFile.h"
#include "entitate.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void RepoFile::setUP()
{
    ifstream f(this->fisier);
    char mancare[20];
    int id, comenzi;
    while (f>>id)
    {
        f>>mancare;
        f>>comenzi;
        this->adauga(id, mancare, comenzi);
    }
    f.close();
}
void RepoFile::setIN(vector<Meniu> lista)
{
    ofstream g(this->fisier);
    for(int i=0;i<lista.size();i++)
        g<<lista[i].getId()<<" "<<lista[i].getMancare()<<" "<<lista[i].getComenzi()<<endl;
}