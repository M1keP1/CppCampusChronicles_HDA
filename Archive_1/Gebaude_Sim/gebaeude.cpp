#include "gebaeude.h"
Gebaeude::Gebaeude()
{

}



vector<Wohnung *> Gebaeude::getWohnungsListe() const
{
    return wohnungsListe;
}

void Gebaeude::setWohnungsListe(const vector<Wohnung *> &newWohnungsListe)
{
    wohnungsListe = newWohnungsListe;
}


void Gebaeude::dialog()
{
    Wohnung* w = new Wohnung();
    wohnungsListe.push_back(w);
    int eingabe{};
    bool flag{true};

    while(flag)
    {
        cout<<"-------------------------------------------"<<endl;
        cout<<"1: Zimmer hinzufuegen"<<endl;
        cout<<"2: Moebel hinzufuegen"<<endl;
        cout<<"3: Zimmer anzeigen"<<endl;
        cout<<"0: Programm beenden"<<endl;
        cin>>eingabe;

        switch(eingabe)
        {
        case 1:
        {
            int zimmerNummer;
            cout<<"New zimmerNummer huh?"<<endl;
            cin>>zimmerNummer;
            //---------------------------------------------
            Zimmer* zobj = new Zimmer(zimmerNummer);
            w->zimmerHinzufuegen(zobj);

            break;

        };
        case 2:
        {
            int what_zimmer{};
            cout<<"New Furniture huh?"<<endl;
            cin>>what_zimmer;
            //---------------------------------------------
            w->moebelHinzufuegen(what_zimmer);

            break;

        };
        case 3:
        {
            int what_zimmer{};
            cout<<"Which zimmer"<<endl;
            cin>>what_zimmer;
            //---------------------------------------------
            w->zimmerAnzeigen(what_zimmer);

            break;
        };
        case 0:
        {
            flag=false;
            break;
        };
        default:
        {
            cout<<"What the sigma?"<<endl;
        };


        };
    }


}
