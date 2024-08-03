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
    cout<<"kost?";
    cin>>tagespreis;
    cout<<"--> Fahrzeug "<<marke<<" mit kennzeichen "<<kennzeichen<<" , "<<sitze<<" Sitzen "<<" und"<<tagespreis <<" tagegspreis"<<" wurde aufgenommen"<<endl;
}

void mietwagen::anmieten(fahrt f)
{
    if(verfuegbarkeitPruefen(f))
    {
    fahrtenbuch.push_back(f);
    cout<<"Fahrt "<<f.getNummer()<<" erfolgreich angelegt"<<endl;
    }
    else
    {
    cout<<"Buchung wegen Ueberschneidung nicht erfolgt!"<< endl ;
    }

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

bool mietwagen::nummerPruefen(int nummer)
{
    for(auto x:fahrtenbuch)
    {
        if(nummer==x.getNummer())
        {
            return true;

        }
    }
    cout<<"Buchungsnummer ist schon vergeben, bitte neu eingeben!"<<endl;
    return false;
}

bool mietwagen::fahrtloeschen(int nummer)
{
    int pos{0};
    for(auto x: fahrtenbuch)
    {
        if(nummer==x.getNummer())
        {
            fahrtenbuch.erase(fahrtenbuch.begin()+ pos);
            return true;
        }
        pos++;
    }
    cout << "Buchungsnummer nicht gefunden" << endl;
    return false;

}

bool mietwagen::verfuegbarkeitPruefen(fahrt f)
{
    for(auto x:fahrtenbuch)
    {
        if(f.getAbgabedatum()>x.getAbgabedatum() && f.getAbgabedatum()< x.getAbholdatum())
        {
            return false;
        }
        if(f.getAbholdatum()>x.getAbholdatum()&& f.getAbholdatum() < f.getAbgabedatum())
        {
            return false;

        }
        if(x.getAbholdatum()<f.getAbholdatum() && x.getAbholdatum()>f.getAbgabedatum())
        {
            return false;
        }
    }
    return true;
}

void mietwagen::fahrzeugAnzeigen()
{
    cout<<"Marke : "<<marke<<" Kennzeichen : "<<kennzeichen <<endl;

}

string mietwagen::getMarke() const
{
    return marke;
}

string mietwagen::getKennzeichen() const
{
    return kennzeichen;
}

int mietwagen::berechneTage(int datum)
{
    string date = to_string(datum);

    int day = stoi(date.substr(6,2));
    int month = stoi(date.substr(4,2));
    int year = stoi(date.substr(0,4));
    year = (year-2023)*365;

    int total = 0;
    static int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i=1; i < month; i++)
        total += length[i];
    total += day;
    total += year;
    return (total);
}

double mietwagen::getTagespreis() const
{
    return tagespreis;
}

double mietwagen::gesamtUmsatz()
{

}
