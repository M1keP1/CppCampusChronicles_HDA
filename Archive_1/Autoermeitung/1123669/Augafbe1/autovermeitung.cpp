#include "autovermeitung.h"

autovermeitung::autovermeitung()
{

}

void autovermeitung::dialog(){

    // Variablen deklarieren
    char eingabe{};

        // dynamische Erstellung eines Mietwagens und in Vector schreiben
        mietwagen *m1=new mietwagen;
        fahrzeuge.push_back(m1);

        while (true){

        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout << "0: Programm beenden" << endl;

        cin >> eingabe;

        switch(eingabe){
        case '1':{         // Fahrzeug mieten

            int n{};
            string k{};
            int ab{};
            int bis{};
            cout<<"Buchungsnummer? ";
            cin>>n;
            cout<<"Kunde? ";
            getline(cin,k);
            cin>>k;
            cout<<"Abholdatum? ";
            cin>>ab;
            cout<<"Abgabedatum? ";
            cin>>bis;
            fahrt f1(n,k,ab,bis);
            m1->anmieten(f1);

        }
        break;

        case '2':{         // Fahrt anzeigen
            int n;
            cout<<"Buchungsnummer? ";
            cin>>n;
            m1->fahrtAnzeigen(n);

        }
        break;

        case '3':{         // Alle Fahrten anzeigen

            if(m1->getFahrtenbuch().empty())
            {
                cout<<"Mietwagen wurde noch nicht verliehen"<<endl;
            }
            else
            {
                m1->alleFahrtenAnzeigen();
            }
        }
        break;

        case '0':{         // Programm beenden
            return;
            break;
        }
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}

vector<mietwagen *> autovermeitung::getFahrzeuge() const
{
    return fahrzeuge;
}
