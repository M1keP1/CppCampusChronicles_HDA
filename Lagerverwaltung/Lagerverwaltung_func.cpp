#include "Lagerverwaltung_header.h"



bool Lagerverwaltung::lagerErweitern(double maxGewicht)
{
    Lagerplatz newLagerplatz(maxGewicht);

    for(const auto& lagerplatz : platzen )
    {
        if (lagerplatz.get_platz_id()==newLagerplatz.get_platz_id())
        {
            return false;
        }
    }

    platzen.push_back(newLagerplatz);

    return true;
}



bool Lagerverwaltung::einlagernNachId(int id,Artikel& artikel)
{
    cout <<"Err:: This fucntion doesnt work yet"<<endl;

    for( auto& lagerplatz: platzen)
    {
        if(lagerplatz.get_platz_id()==id)
        {
            if(lagerplatz.einlagern(artikel))
            {
                return true;
            }

        }
    }

    return false;
}

/*bool Lagerverwaltung::einlagern(const Artikel& artikel)
{
    int newanzahl{};
    if(artikel.get_artikelnummer()==artikel.get_artikelnummer())
    {
        artikel.increase_anzahl();
        return true;
    }
    else(einlagern())

    return false;
}*/
double Lagerverwaltung::get_total_gewicht()
{
    double total_gewicht{};
    for(const auto& lagerplatz:platzen)
    {
        total_gewicht+= lagerplatz.get_gewicht();
    }
    return total_gewicht;
}

double Lagerverwaltung::get_total_kapazitat()
{
    double total_kapazitat{};
    for(const auto& lagerplatz:platzen)
    {
        total_kapazitat+= lagerplatz.get_kapazitat();
    }
    return total_kapazitat;
}

void Lagerverwaltung::inventur()
{



    cout << "------Inventur-------"<<endl;
    cout<<">>Anzahl der Lagerplatz:: "<< platzen.size() <<endl;
    cout<<">>Gesamtgewicht aller eingelagerten Artikel:: "<< get_total_gewicht()<< endl;
    cout<<">>Maximal Gewichtskapazitat aller lagerplatz:: "<< get_total_kapazitat()<<endl;
    for(const auto& lagerplatz:platzen)
    {
        lagerplatz.platz_inventur();
    }
}
