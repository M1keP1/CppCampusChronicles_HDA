#include "callcenter.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

Callcenter::Callcenter()  // Aufgabe 5: Konstruktor mit Lesen aus Datei
{
    einlesen();
}

Callcenter::~Callcenter()  // Aufgabe 5: Destruktor mit Schreiben in Datei
{
    speichern();
}


void Callcenter::dialog(){
    char eingabe;
    string name, datumUhrzeit, nameArztPraxis;
    Impfstoff impfstoff=Biontech;
    char impfstoffKennz;
    cout << "Willkommen im Callcenter!" << endl;

    bool running = true;

    while(running){
        cout << "1: Termin anlegen" << endl;
        cout << "2: Termin loeschen" << endl;
        cout << "3: Arztpraxis anlegen" << endl;
        cout << "4: Uebersicht" << endl;
        cout << "5: Stornierte Termine" << endl;   // Aufgabe 5: Menüpunkt ergänzt
        cout << "6: Speichern" << endl;            // Aufgabe 5: Menüpunkt ergänzt
        cout << "0: Programm abbrechen" << endl;
        cin >> eingabe;

        switch(eingabe){
        case '1':{  // Menü "Termin anlegen" **************
            cout << "Nachname,Vorname (ohne Leerzeichen)? ";
            cin >> name;

            cout << "Arztpraxis? ";
            //cin >> nameArztPraxis;
            cin.ignore(100,'\n');
            getline(cin, nameArztPraxis);  // umgesetzt mit getline um auch Leerzeichen einzulesen
            int indexArztpraxis = findeArztpraxis(nameArztPraxis);
            if (indexArztpraxis == -1){
                cout << "Arztpraxis existiert nicht. Bitte neu eingeben." << endl;
                break;
            }

            cout << "Impfstoff? (1: Biontech, 2: Moderna, 3: Astra Zeneca, 4: Johnson&Johnson)? ";
            cin >> impfstoffKennz;
            if (impfstoffKennz == '1')
                impfstoff = Biontech;
            else if (impfstoffKennz == '2')
                impfstoff = Moderna;
            else if (impfstoffKennz == '3')
                impfstoff = AstraZeneca;
            else if (impfstoffKennz == '4')
                impfstoff = JohnsonJohnson;

            cout << "Termin 1: (DD.ff.YYYY:HHff)? ";
            cin >> datumUhrzeit;
            arztpraxen[indexArztpraxis].terminAnlegen(name, datumUhrzeit, impfstoff);

            if (impfstoff != JohnsonJohnson){  // 2. Termin
                cout << "Termin 2: (DD.ff.YYYY:HHff)? ";
                cin >> datumUhrzeit;
                arztpraxen[indexArztpraxis].terminAnlegen(name, datumUhrzeit, impfstoff);
                cout << "Termine fuer " << name << " angelegt" << endl;
             }
             else
                cout << "Termin fuer " << name << " angelegt" << endl;
             break;
        }

        case '2':{  // Menü "Termin loeschen" **************
            cout << "Name? ";
            cin >> name;

            cout << "Arztpraxis? ";
            cin.ignore(100,'\n');
            getline(cin, nameArztPraxis);  // umgesetzt mit getline um auch Leerzeichen einzulesen
            int indexArztpraxis = findeArztpraxis(nameArztPraxis);
            if (indexArztpraxis == -1){
                cout << "Arztpraxis existiert nicht. Bitte neu eingeben." << endl;
                break;
            }

            if (!arztpraxen[indexArztpraxis].terminLoeschen(name))
                cout << "Kein Termin gefunden fuer diesen Namen gefunden "<< endl;
            break;
        }

        case '3':{  // Menü "Arztpraxis anlegen" **************
            cout << "Name der Praxis? ";
            cin.ignore(100,'\n');
            getline(cin, nameArztPraxis);  // umgesetzt mit getline um auch Leerzeichen einzulesen

            int indexArztpraxis = findeArztpraxis(nameArztPraxis);
            if(indexArztpraxis == -1){  // prüfen, ob Arztpraxis schon vorhanden ist
                arztpraxen.push_back(Arztpraxis(nameArztPraxis));
                cout << "Praxis " << nameArztPraxis << " angelegt" << endl;
            }
            else
                cout << "Praxis " << nameArztPraxis << " schon vorhanden" << endl;
        }
            break;

        case '4':{  // Menü "Übersicht anzeigen" **************
            uebersichtAusgeben(false);  // false = gültige Termine ausgeben  --> Aufgabe 5: bool-Parameter ergänzt **************************
            break;
        }

   // AUFGABE 5: Menüpunkt "Stornierte Termine" ergänzt **********************************
        case '5':{  // Menü "Stornierte Termine" **************
            uebersichtAusgeben(true);  // true = gelöschte Termine ausgeben  --> Aufgabe 5: bool-Parameter ergänzt **************************
            break;
        }

   // AUFGABE 6: Menüpunkt "Speichern" ergänzt **********************************
        case '6':{
            speichern();
            break;
        }

        case '0':
            running = false;
            break;
        default:
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}


int Callcenter::findeArztpraxis(string name){   // Aufgabe 3d: Funktion findeArztpraxis ergänzt
    for (unsigned int i=0; i < arztpraxen.size();i++){
        if (arztpraxen[i].getName() == name)
            return i;
    }
    return -1;
}

void Callcenter::uebersichtAusgeben(bool storniert){   // Aufgabe 5: bool storniert, um storniert oder gültige Termine auszugeben
    vector<Termin> terminListe;

    for (unsigned int i=0; i < arztpraxen.size(); i++){
        terminListe = arztpraxen[i].getTermine();
        sort(terminListe.begin(),terminListe.end());      // operator< von Termin überladen werden (siehe Termin.h)

        cout << "------------------------------------------------------------------" << endl;
        cout << arztpraxen[i].getName() << endl;
        for (auto& t : terminListe){
            if (t.getGeloescht()){          // ist dieser Termin gelöscht?
                if(storniert){              // sollen nur die stornierten ausgegeben werden?
                    cout << "  " << t.getPatient() << "\t" << t.getDatumUhrzeit() << "\t" << enumStr[t.getImpfstoff()] << " --> storniert" << endl;
                }
                continue;
            }
            else{                           // dieser Termin ist nicht gelöscht
                if(!storniert){             // Termin ist nicht gelöscht
                    cout << "  " << t.getPatient() << "\t" << t.getDatumUhrzeit() << "\t" << enumStr[t.getImpfstoff()] << endl;
                }
            }
        }
    }
    cout << "------------------------------------------------------------------" << endl;
}


// --------------- Aufgabe 5 --------------- //
void Callcenter::speichern(){

    ofstream ziel;
    ziel.open("..\\Impfzentrum.txt", ios::in);

    if (!ziel) {
        cerr << "Datei kann nicht geoeffnet werden!\n";
        exit(-1);
    }

    vector<Termin>terminListe;
    for (unsigned int i=0; i < arztpraxen.size(); i++){            // for-Schleife zum speichern aller Artzpraxen
        ziel << arztpraxen[i].getName() << endl;                   // schreiben des Praxisnamens in die Zieldatei
        terminListe = arztpraxen[i].getTermine();                  // Termine der Arztpraxis in terminliste holen
        //sort(terminListe.begin(),terminListe.end());               // operator< von Termin überladen werden (siehe Termin.h)

        for (unsigned int j = 0; j < terminListe.size(); j++){     // for-Schleife zum speichern aller Termine einer Artzpraxis
            ziel << terminListe[j].getPatient() << " " << terminListe[j].getDatumUhrzeit()
                 << " " << terminListe[j].getImpfstoff() << " " << terminListe[j].getGeloescht() << endl;       // Wortweise schreiben in Datei
        }
    }

    ziel.close();   // Datei schließen
}


// --------------- Aufgabe 5 --------------- //
void Callcenter::einlesen(){

    ifstream quelle;
    quelle.open("..\\Impfzentrum.txt", ios::in);

    if (!quelle) {
        cerr << "Datei kann nicht geoeffnet werden!\n";
        exit(-1);
    }

    string arzt;
    string name;
    string termin;
    string impfstoff;
    string geloescht;
    int i = -1;

    while (quelle >> name){                                  // einlesen des string name
        int found = name.find("Dr.");                        // prüfen, ob es sich um eine Arztparxis handelt --> The position of the first character of the first match
        if (found==0){                                       // wenn erstes Wort "Dr." am Anfang
            quelle >> arzt;                                  // 2. Wort einlesen --> Arztname
            arztpraxen.push_back(Arztpraxis("Dr. "+arzt));   // in Arztpraxen ergänzen
            quelle >> name;                                  // nächstes Wort einlesen --> Patientenname
            i++;
        }

        quelle >> termin;
        quelle >> impfstoff;
        quelle >> geloescht;
        arztpraxen[i].terminAnlegen(name, termin, static_cast<Impfstoff>(stoi(impfstoff)),(geloescht == "1"));  // Termin in Terminliste des Arztes eintragen

    }
    quelle.close();   // Datei schließen
}
