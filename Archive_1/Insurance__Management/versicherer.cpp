#include "versicherer.h"
#include "lvschein.h"
#include "kfzschein.h"
#include <iostream>

Versicherer::Versicherer()
{

}


void Versicherer::dialog()
{
    while (true){
        char eingabe;
        cout << "1: Versicherung anlegen" << endl;
        cout << "2: Versicherungsdetails ausgeben" << endl;
        cout << "3: Alle Versicherungsdetails ausgeben" << endl;
        cout << "4: Versicherung loschen" << endl;
        cout << "5: versicherung Anpassen"<<endl;
        cin >> eingabe;
        switch(eingabe){
        case '1':{         // Versicherung anlegen


            string vTyp, vName, nName;
            int sNummer;

            cout << "ScheinNummer? ";
            cin>>sNummer;
            if(nummerpruefen(sNummer)==false)
            {
                cout << "Vorname? ";
                cin >>vName;
                cout << "Nachname? ";
                cin >> nName;

                while(true){
                    cout << "K fuer KFZ-Versicherung oder L fuer Lebensversicherung? ";
                    cin >> vTyp;

                    if (vTyp == "K" || vTyp == "k"){
                        KFZSchein* kfzSchein = new KFZSchein(sNummer, vName, nName); // dynamische KFZ-Versicherung
                        versicherungen.push_back(kfzSchein);
                        cout << "KFZ-Versicherung wurde angelegt" << endl << endl;
                        break;
                    }
                    else if (vTyp == "L" || vTyp == "l"){
                        LVSchein* lvSchein = new LVSchein(sNummer, vName, nName); // dynamische Lebensversicherung
                        versicherungen.push_back(lvSchein);
                        cout << "Lebensversicherung wurde angelegt" << endl << endl;
                        break;
                    }
                    else{
                        cout << "Ungueltige Eingabe" << endl;
                        cin.ignore(256,'\n');  //entfernt bis zu 256 Zeichen aus dem Eingabestream
                    }
                }

            }
        }
        break;

        case '2':{         // Versicherungsdetails ausgeben
            int sNummer;
            cout << "ScheinNummer? ";
            cin >> sNummer;
            bool found = false;
            for(unsigned int i=0; i < versicherungen.size(); i++){
                if (versicherungen[i]->getScheinNr() == sNummer){
                    versicherungen[i]->anzeigen();
                    found = true;
                    break;
                }
            }
            if (found==false)
                cout << "Versicherungsschein existiert nicht" << endl;
        }
        break;
        case '3':
        {
            for(auto& x:versicherungen)
            {
                x->anzeigen();
                cout<<"----------------------------------------"<<endl;
            }
            break;
        };


        case '4':
        {
            int vsn{};
            int pos{0};
            bool found{false};
            cout<<"Enter Number to be deleted"<<endl;
            cin>>vsn;
            for(auto& x:versicherungen)
            {

                if(x->getScheinNr()==vsn)
                {
                    delete x;                        // Objekt zerstören
                    versicherungen.erase(versicherungen.begin()+pos);
                    cout<<"Deleted x"<<endl;
                    found=true;
                }
                pos++;

            }
            if(found==false)
            {
                cout<<"Nummer not found"<<endl;
            }
            break;

        };
        case '5':
        {
            int vsr{};
            cout<<"Enter vsn"<<endl;
            cin>>vsr;
            for(auto& x:versicherungen)
            {
                if(x->getScheinNr()==vsr)
                {
                x->anpassen();
                }
            }
            cout<<"Number doesnt exist"<<endl;
        };

        case '0':         // Programm beenden
            break;

        default:
            cout << "Ungueltige Eingabe" << endl;
            return;
        }
    }
}

bool Versicherer::nummerpruefen(int sNummer)
{
    for(auto& x:versicherungen)
    {
        if(x->getScheinNr()==sNummer)
        {
            cout<<"Number is already Insured !!"<<endl;
            return true;
        }
    }
    return false;
}

Versicherer::~Versicherer()
{
    for(auto& x:versicherungen)
    {
        delete x;
    }
    versicherungen.clear();
    cout <<"TSchau kakao"<<endl;
}



