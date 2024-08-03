#include "versicherer.h"
#include"kfzschein.h"
#include"lvschein.h"
versicherer::versicherer() {}

versicherer::~versicherer()
{
    for (auto&x:versicherungen) {
        delete x;
        cout<<"Alle versichrungen geloescht"<<endl;
        cout<<"Bis bald"<<endl;
    }
    versicherungen.clear();
}

void versicherer::dialog()
{
    while (true){
        string vTyp, vName, nName;
        int sNummer;
        char eingabe;
        cout << "1: Versicherung anlegen" << endl;
        cout << "2: Versicherungsdetails ausgeben" << endl;
        cout << "3: Alle Versicherungsdetails anzeigen " << endl;
        cout << "4: Versicherung loeschen" << endl;
        cout << "5: Versicherung anpassen" << endl;
        cout << "0: Programm beenden" << endl;
        cin >> eingabe;
        switch(eingabe){
        case '1':{
            cout<<"Enter Versichrungs nummer, vorname und nachname"<<endl;
            cin>>sNummer;
            cin>>vName;
            cin>>nName;
            if(nummerPruefen(sNummer)){
                break;
            }
            else {
                cout<<"Versicherung existiert schon"<<endl;
            }
            while(true){
                cout << "K fuer KFZ-Versicherung oder L fuer Lebensversicherung? ";
                cin >> vTyp;
                if (vTyp == "K" || vTyp == "k"){
                    KFZSchein * p1=new KFZSchein(sNummer,vName,nName);
                    versicherungen.push_back(p1);
                    break;
                }
                else if (vTyp == "L" || vTyp == "l"){
                    LVSchein * p1=new LVSchein(sNummer,vName,nName);
                    versicherungen.push_back(p1);
                    cout<<"Versicherung LV mit "<<sNummer<<"Wurde erstellt"<<endl;
                    break;
                }
                else{
                    cout << "Ungueltige Eingabe" << endl;
                }
            }
        }
        break;
        case '2':{         // Versicherungsdetails ausgeben
            cout<<"Enter schein nummer"<<endl;
            cin>>sNummer;
            for(auto&x: versicherungen){
                if(x->getScheinNummer()==sNummer){
                    x->anzeigen();
                }
                else {
                    cout<<"Versicherungsschein existiert nicht"<<endl;
                }
            }
        }
        break;
        case '3':         // verischerungen anzeigen
                alleanzeigen();
            break;
        case '4':         // verischerungen loeschen
        {
            cout<<"Enter Number to be deleted"<<endl;
            cin>>sNummer;
            for (unsigned int i = 0; i < versicherungen.size(); i++) {
                if(versicherungen[i]->getScheinNummer()==sNummer){
                    versicherungen.erase(versicherungen.begin()+i);
                    cout<<"versichrungen delted with number"<<versicherungen[i]->getScheinNummer()<<endl;
                    break;
                }
                cout<<"Keine Versicherung zu dieser Nummer gefunden"<<endl;
            }
        };
            break;
        case '5':         // verischerungen anpassen
            cout<<"Enter versicherungs nummer";
            cin>>sNummer;
            for(auto&x: versicherungen){
                if(x->getScheinNummer()==sNummer){
                    x->anpassen();
                }
                else {
                    cout<<"Versicherungsschein existiert nicht"<<endl;
                }
            }
            break;
        case '0':       // Programm beenden
            return;
            break;
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }

}

void versicherer::alleanzeigen()
{
    for (auto&x:versicherungen) {
        x->anzeigen();
        cout<<"--------------------------"<<endl;
    }
}

bool versicherer::nummerPruefen(int sNummer)
{
    for (auto&x:versicherungen) {
        if(x->getScheinNummer()==sNummer){
            cout<<"Nummer already exits"<<endl;
            return true;
        }           
    }
     return false;
}
