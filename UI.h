

#ifndef LAB9_10POO_UI_H
#define LAB9_10POO_UI_H
#include "service.h"
#include "ElementNotFoundException.h"
#include "InvalidCodeExc.h"
#include "NrNaturalExc.h"

class UI {
private:
    Service service;
public:
    UI(const Service &service)
    {
        this->service = service;
    }

    int menu()
    {
        this->service.initializareFisier();
        while (true)
        {
            cout << "1. Adauga un meniu" << endl;
            cout << "2. Afiseaza intregul meniu" << endl;
            cout << "3. Elimina un meniu" << endl;
            cout << "4.Modifica" << endl;
            cout << "5.Afiseaza comenzile mai mari decat" << endl;
            cout << "6.Suma de comenzi" << endl;
            cout << "7.Elimina comenzi mai mici decat" << endl;
            cout << "0. Iesire" << endl;
            cout << "Dati o optiune: "<<endl;
            int opt = 0;
            cin >> opt;
            switch (opt) {
                case 1:
                {
                    try
                    {
                        int id, comenzi;
                        char *mancare = new char[15];
                        NrNatural nrNatural(0);
                        cout << "Dati id: ";
                        cin >> id;
                        nrNatural.validare(id);
                        cout << "Dati un fel de mancare: ";
                        cin >> mancare;
                        cout << "Dati nr de comenzi: ";
                        cin >> comenzi;
                        nrNatural.validare(comenzi);
                        this->service.adaugareService(id, mancare, comenzi);
//                    this->service.adaugareService(1,"friptura",20);
//                    this->service.adaugareService(2,"cartofi", 30);
                    }
                    catch(InvalidCodeException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                    catch(ElementNotFoundException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                this->service.copiereFisier();
                    break;
                }
                case 2:
                {
                    this->service.afisareService();
                    break;
                }
                case 3:
                {

                        try {
                            int id;
                            NrNatural nrNatural(0);
                            cout << "Dati id ul de sters: ";
                            cin >> id;
                            nrNatural.validare(id);

                            this->service.eliminareDupaId(id);
                        }
                        catch (InvalidCodeException exception) {
                            cout << exception.what() << endl;
                        }
                        catch (ElementNotFoundException exception) {
                            cout << exception.what() << endl;
                        }


                    this->service.copiereFisier();
                    break;
                }
                case 4:
                {
                    try {
                        int id;
                        NrNatural nrNatural(0);
                        cout << "Dati id ul de modificat: ";
                        cin >> id;
                        nrNatural.validare(id);
                        int comenzi;
                        char *mancare = new char[15];
                        cout << "Dati un fel nou de mancare: ";
                        cin >> mancare;
                        cout << "Dati nr comenzi nou: ";
                        cin >> comenzi;
                        nrNatural.validare(comenzi);
                        this->service.modificare(id, mancare, comenzi);
                        cout << "modificare cu succes" << endl;
                    }
                    catch(InvalidCodeException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                    catch(ElementNotFoundException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                    this->service.copiereFisier();
                    break;
                }
                case 5:
                {
                    int comenzi;
                    cout<<"dati un nr:";
                    cin>>comenzi;
                    service.afiseazaDupaNrCom(comenzi);
                    break;
                }
                case 6:
                {
                    cout<<"suma totala este:"<<service.sumaComenzi();
                    cout<<endl;
                    break;
                }
                case 7:
                {
                    try {
                        int comenzi;
                        NrNatural nrNatural(0);
                        cout << "Dati nr: ";
                        cin >> comenzi;
                        nrNatural.validare(comenzi);
                        this->service.eliminareDupaComenzi(comenzi);
                    }
                    catch(InvalidCodeException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                    catch(ElementNotFoundException exception)
                    {
                        cout<<exception.what()<<endl;
                    }
                    this->service.copiereFisier();
                    break;
                }
                default:
                    cout << "sper ca v-a placut!" << endl;
                    return 0;
            }
        }
    }
};




#endif //LAB9_10POO_UI_H
