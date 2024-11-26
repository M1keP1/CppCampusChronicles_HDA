#include "autovermietung.h"

vector<Mietwagen *> autovermietung::getFahrzeuge() const
{
    return fahrzeuge;
}

int autovermietung::mietwagensuche()
{
    int g;
    cout<<"Enter Index"<<endl;
    cin>>g;
    for (int t = 0; t < fahrzeuge.size(); ++t) {
        if(g==t){
            fahrzeuge[t]->fahrzeugAnzeigen();
            return g;
        }
    }
    cout<<"Nicht gefunden"<<endl;
    return -1;
}

void autovermietung::dialog()
{
    int nummer,index;
    string kunde;
    int abhol;
    int abgabe;
    Mietwagen* p1=new Mietwagen();
    fahrzeuge.push_back(p1);
    char eingabe;

    bool t{true};


    while (t==true){

        cout << "1: Fahrzeug mieten" << endl;
        cout << "2: Fahrt anzeigen" << endl;
        cout << "3: Alle Fahrten anzeigen" << endl;
        cout <<"4: Fahrzeug loeschen"<<endl;
        cout<<"5: Fahrzeug hinzufuegen"<<endl;
        cout <<"6: Alle Fahrzeuge ausgeben"<<endl;
        cout << "0: Programm beenden" << endl;

        cin >> eingabe;

        switch(eingabe){
        case '1':{         // Fahrzeug mieten

            index = mietwagensuche();
            if(index == -1)
                break;

            cout << "Buchungsnummer? ";
            cin >> nummer;
            if(!fahrzeuge[index]->nummerPruefen(nummer))
                break;

            cout << "Kunde (Nachname,Vorname)? ";
            cin >> kunde;
            cout << "Abholdatum (yyyymmtt)? ";
            cin >> abhol;
            cout << "Abgabedatum (yyyymmtt)? ";
            cin >> abgabe;
            if(abhol>abgabe){
                cout << "Abholdatum liegt vor dem Abgabedatum: Buchung wird abgebrochen" << endl;
                break;
            }
            Fahrt f1(nummer, kunde, abhol, abgabe);
            fahrzeuge[index]->anmieten(f1);
        }
        break;

        case '2':{             // Fahrt anzeigen
            index=mietwagensuche();
            if(mietwagensuche()==-1)
                break;
            int b;
            cout<<"Buchungsnummer?"<<endl;
            cin>>b;
            fahrzeuge[index]->fahrtAnzeigen(b);
            break;

        }


        case '3':{         // Alle Fahrten anzeigen
            index=mietwagensuche();
            if(mietwagensuche()==-1)
                break;
            fahrzeuge[index]->alleFahrtenAnzeigen();
            break;
        }

        case '4':{         // Alle Fahrten loeshcen
            int n;
            cout<<"Buchungsnummer ?"<<endl;
            cin>>n;
            if(p1->fahrtLoeschen(n)) {
                cout<<"Buchungsnummer "<<n<<"wurde geloescht"<<endl;
                break;
            }
            cout<<"Buchungsnummer"<<n<<"Existiert nicht"<<endl;
            break;
        }

        case '5':{        //Fahrzeug hinfuegen
            cout<<"Neues Fahrzeug:"<<endl;
            Mietwagen* p2=new Mietwagen();
            fahrzeuge.push_back(p2);
            break;
        }

        case '6':{         // Alle Fahrten loeshcen
            for (auto&x:fahrzeuge) {
                x->fahrzeugAnzeigen();
                x->alleFahrtenAnzeigen();
            }
            break;
        }


        case '0':{
            cout<<"Program ended"<<endl;
            t = false;
            /*return;*/
            break;
        }
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }

}

autovermietung::autovermietung() {}

autovermietung::~autovermietung()
{
    for (auto&x:fahrzeuge) {
        delete x;
    }
    fahrzeuge.clear();
    cout<<"Hasta la vista"<<endl;
}
