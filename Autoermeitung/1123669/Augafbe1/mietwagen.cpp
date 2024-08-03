#include "mietwagen.h"

mietwagen::mietwagen()
{
    cout<<"Neues Fahrzeug: "<<endl;
    cout<<"Automarke? ";
    cin>>marke;
    cout<<"KfZ-Kennzeichen? ";
    cin>>kennzeichen;
    cout<<"Sitze? ";
    cin>>sitze;
    cout<<"--> Fahrzeug "<<marke<<" mit kennzeichen "<<kennzeichen<<" und "<<sitze<<" Sitzen qurde aufgenommen"<<endl;
}

void mietwagen::anmieten(fahrt f)
{
    fahrtenbuch.push_back(f);
    cout<<"Fahrt "<<f.getNummer()<<" erfolgreich angelegt"<<endl;
}

void mietwagen::fahrtAnzeigen(int nummer)
{
    for(auto x: fahrtenbuch)
    {
        if(nummer==x.getNummer())
        {

            x.anzeigen();
        }
        else
        {
            cout<<"Fahrt existiert nicht"<<endl;
        }

    }
}

void mietwagen::alleFahrtenAnzeigen()
{
    for(auto x:fahrtenbuch)
    {
        cout<<"------------------------------"<<endl;
        x.anzeigen();
    }
}

vector<fahrt> mietwagen::getFahrtenbuch() const
{
    return fahrtenbuch;
}
