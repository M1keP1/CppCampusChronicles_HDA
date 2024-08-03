#include "gebaeude.h"

Gebaeude::Gebaeude() {}

Gebaeude::~Gebaeude() {
    for (unsigned int i = 0; i < wohnungsliste.size(); i++)
        delete wohnungsliste[i];   // dynamisches Objekt vernichten
    wohnungsliste.clear();         // aus Vector nehmen
    cout << "Alle Wohnungen geloescht" << endl;
}

void Gebaeude::dialog()
{
    Wohnung* p1=new Wohnung();
    wohnungsliste.push_back(p1);

    bool t{true};
    char c;
    int k;

    while (t==true) {
        cout<<"1: Zimmer hinzufuegen"<<endl;
        cout<<"2: Moebel hinzufuegen"<<endl;
        cout<<"3: Zimmer anzeigen"<<endl;
        cout<<"0: Program beenden"<<endl;
        cin>>c;
        switch (c) {
        case '1':{
            cout<<"Please enter zimmerNUmmer"<<endl;
            cin>>k;
            Zimmer* Z1=new Zimmer(k);
            p1->zimmerHinzufuegen(Z1);
            break;}
        case '2':{
            cout<<"Please enter zimmerNUmmer"<<endl;
            cin>>k;
            p1->moebelHinzufuegen(k);
            break;}
        case '3':{
            cout<<"Please enter zimmerNUmmer"<<endl;
            cin>>k;
            p1->zimmerAnzeigen(k);
            break;}
        case '0':{
            cout<<"Program ended"<<endl;
            t = false;
            break;}
        default:
            cout<<"Please enter a value between 0 and 3"<<endl;
            break;
        }
    }
}
