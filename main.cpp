#include <iostream>
using namespace std;

#include "teste.h"
#include "repo.h"
#include "RepoFile.h"
#include "service.h"
#include "UI.h"




int main() {
    cout<<"Meniu de restaurant"<<endl;
    allTests();
    //Repo repo;
    RepoFile rf("meniu.txt");
    Service service(rf);
    UI ui(service);
    ui.menu();
    return 0;
}
