

#include "teste.h"
#include "entitate.h"
#include "repo.h"
#include "service.h"
#include "RepoFile.h"
#include <cassert>
#include <cstring>


void testeMeniu()
{
    Meniu meniu(1,"friptura", 3);

    assert(meniu.getId()==1);
    assert(meniu.getComenzi()==3);
    assert(strcmpi(meniu.getMancare(),"friptura")==0);


    meniu.setId(15);
    assert(meniu.getId()==15);
   // char mancare[]="friptura"; si n devine mancare
    meniu.setMancare((char*)"friptura");
    assert(strcmpi(meniu.getMancare(),"friptura")==0);
    meniu.setComenzi(6);
    assert(meniu.getComenzi()==6);
}

void testeRepo()
{
    Repo repo;

    repo.adauga(1,"friptura", 3);
    assert(repo.getSize()==1);

    repo.sterge(0);
    assert(repo.getSize()==0);
}

void testeRepoFile()
{
    RepoFile repo;

    repo.adauga(1,"friptura", 3);
    assert(repo.getSize()==1);

    repo.sterge(0);
    assert(repo.getSize()==0);
}

void testeService()
{
    Service service;

    service.adaugareService(1,"friptura", 3);
    vector<Meniu> lista = service.getAllService();
    assert(lista.size()==1);

    assert(service.sumaComenzi()==3);

    service.eliminareDupaId(1);
    vector<Meniu> lista1 = service.getAllService();
    assert(lista1.size()==0);


}



void allTests()
{
    cout<<" "<<endl;
    cout<<"incep testele...";
    testeMeniu();
    testeRepo();
    testeService();
    testeRepoFile();
    cout<<"toate testele sunt bune!!"<<endl;
}


