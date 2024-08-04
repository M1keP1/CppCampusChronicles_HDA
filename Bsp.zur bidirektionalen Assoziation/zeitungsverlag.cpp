#include "zeitungsverlag.h"
#include "abonnent.h"
#include "zeitung.h"
#include <iostream>


/****************************************************
 * Destruktor fehlt noch !!!
 * *************************************************/


ZeitungsVerlag::ZeitungsVerlag() {

}

// Hauptschleife
void ZeitungsVerlag::dialog() {

    char eingabe;

    while (true){
        cout << endl;
        cout << "1: Zeitung anlegen" << endl;
        cout << "2: Abonnent anlegen" << endl;
        cout << "3: Zeitungen anzeigen" << endl;
        cout << "4: Abonnenten anzeigen" << endl;
        cout << "5: Zeitung bei Abonnent hinzufuegen" << endl;
        cout << "0: Programm beenden" << endl;

        cin >> eingabe;

        switch(eingabe){
        case '1':{         // Zeitung anlegen
            // ******************************** Zeitung anlegen ********************************
            Zeitung* pZeitung = new Zeitung();
            zeitungsListe.push_back(pZeitung);
            break;
        }

        case '2':{         // Abonnent anlegen
            // ******************************** Abonnent anlegen ********************************
            Abonnent* pAbonnent = new Abonnent();
            abonenntenListe.push_back(pAbonnent);
            break;
        }

        case '3':{         // Zeitungen anzeigen
            // ******************************** Zeitungen anzeigen ********************************
            if (zeitungsListe.size()==0){
                cout << "Noch keine Zeitung vorhanden" << endl;
                break;
            }

            // *********************************** wenn Zeitung viele Abonnenten erlaubt ***********************************
            for(unsigned int i = 0; i < zeitungsListe.size(); i++){
                cout << "Zeitung " << i << ": " << zeitungsListe[i]->getName() << endl;
                vector<Abonnent*> aboListe = zeitungsListe[i]->getAbonnenten();
                for(unsigned int j = 0; j < aboListe.size(); j++)
                    cout << "    Abonnent " << j << ": " << aboListe[j]->getName() << endl;
                cout << endl;
            }

            break;
}

        case '4':{         // Abonnenten anzeigen
            // ******************************** Abonnenten anzeigen ********************************
            if (abonenntenListe.size()==0){
                cout << "Noch keine Abonnent vorhanden" << endl;
                break;
            }

            for(unsigned int i = 0; i < abonenntenListe.size(); i++){
                cout << "Abonnent " << i << ": " << abonenntenListe[i]->getName() << endl;
                vector<Zeitung*> zeitungen = abonenntenListe[i]->getMeineZeitungen();
                for(unsigned int j = 0; j < zeitungen.size(); j++)
                    cout << "    Zeitung " << j << ": " << zeitungen[j]->getName() << endl;
                cout << endl;
            }
            break;
        }

        case '5':{         // Zeitung bei Abonnent hinzufuegen
            // ******************************** Zeitung bei Abonnent hinzufuegen ********************************

            Abonnent* a = getAbonnent();

            if(a == nullptr)
                cout << "Abonnent existiert nicht" << endl;
            else {
                Zeitung* z = getZeitung();
                if(z == nullptr)
                    cout << "Zeitung existiert nicht" << endl;
                else {
                    a->abonniere(z);
                    z->addAbonnent(a);
                    cout << "Zeitung " << z->getName() << " wurde von " << a->getName() << " abonniert!" << endl;
                }
            }
            break;
        }

        case '0':{         // Programm beenden
            return;
        }
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}


Abonnent* ZeitungsVerlag::getAbonnent(){
    string abonnent;
    cout << "Name des Abonnenten? ";
    cin >> abonnent;

    for (unsigned int i=0; i < abonenntenListe.size(); i++){
        if (abonenntenListe[i]->getName() == abonnent){
            return abonenntenListe[i];
        }
    }
    return nullptr;
}


Zeitung* ZeitungsVerlag::getZeitung(){
    string zeitung;
    cout << "Name der Zeitung? ";
    cin >> zeitung;

    for (unsigned int i=0; i < zeitungsListe.size(); i++){
        if (zeitungsListe[i]->getName() == zeitung){
            return zeitungsListe[i];
        }
    }    
    return NULL;
}
