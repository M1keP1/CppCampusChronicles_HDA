#include "mietwagen.h"



Mietwagen::Mietwagen()
{

    cout<<"marke ?"<<endl;
    cin>>marke;
    cin.ignore();
    cout<<"Kennzeichen ?"<<endl;
    /*cin>>kennzeichen;*/
    getline (cin,kennzeichen);
    cout<<"Sitze ?"<<endl;
    cin>>sitze;
    cout<<"tagespreis ?"<<endl;
    cin>>tagespreis;
    cout<<"Fahrzeug"<<marke<<"mit KFZ-Kennzeichen"<<kennzeichen<<"und"<<sitze<<
     "Sitzen wurde aufgenommen mit Tages preis "<<fixed<<setprecision(2)<<tagespreis<<endl;

}

void Mietwagen::anmieten(Fahrt f)
{
    if(verfuegbarkeitPruefen(f)==true){
        fahrenbuch.push_back(f);
    }
    else{
        cout<<"Ubershcneidung"<<endl;
    }
}

void Mietwagen::fahrtAnzeigen(int nummer)
{
    for (auto&x:fahrenbuch) {
        if(x.getNummer()==nummer){
            x.anzeigen();
        }
        else{
            cout<<"Fahrt existiert nicht"<<endl;
        }
    }
}

void Mietwagen::alleFahrtenAnzeigen()
{
    for (auto&x:fahrenbuch) {
        if(fahrenbuch.size()>0){
            x.anzeigen();
            cout<<"----------------------------------------"<<endl;
        }
        else{
            cout<<"der Mietwagen noch nicht verliehen wurde."<<endl;
        }
    }
}

bool Mietwagen::nummerPruefen(int nummer)
{

    for(unsigned int i = 0; i < fahrenbuch.size(); i++){
        if(fahrenbuch[i].getNummer()==nummer){
            cout<<"Buchungsnummer ist schon vergeben, bitte neu eingeben!"<<endl;
            return false;
            break;
        }
    }
    return true;

}

bool Mietwagen::fahrtLoeschen(int nummer)
{
    for(unsigned int i = 0; i < fahrenbuch.size(); i++){
        fahrenbuch.erase(fahrenbuch.begin()+i);
        return true;
    }

    return false;
}

bool Mietwagen::verfuegbarkeitPruefen(Fahrt f)
{
    for(auto&x:fahrenbuch){
        if(x.getAbgabedatum()>=f.getAbgabedatum()&& x.getAbholdatum()<=f.getAbgabedatum() ){
            return false;
        }
        else if (x.getAbgabedatum()>=f.getAbholdatum()&&x.getAbholdatum()<=f.getAbholdatum()) {
            return false;
        }

        else if (f.getAbgabedatum()>x.getAbholdatum()&& f.getAbholdatum()<x.getAbholdatum()) {
            return false;
        }
    }
    return true;
}

void Mietwagen::fahrzeugAnzeigen()
{
    cout<<"Marke is "<<marke;
    cout<<" Kennzeichen ist "<<kennzeichen<<endl;
}

int Mietwagen::berechneTage(int datum)
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


