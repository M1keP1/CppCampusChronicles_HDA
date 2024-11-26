#include "Lagerplatz_header.h"

int Lagerplatz::get_platz_id() const
{
    return platz_id;
}


double Lagerplatz::get_kapazitat() const
{
    return kapazitat;
}

int Lagerplatz::get_max_gewicht() const
{
    return max_gewicht;
}

int Lagerplatz::get_gewicht() const
{
    int total_gewicht{};
    for(const auto& artikel: artikeln)
        {
        total_gewicht += artikel.get_gewicht();
        }
    return total_gewicht;
}

void Lagerplatz::set_platz_id()
{

}
void Lagerplatz::set_kapazitat()
{

}
void Lagerplatz::set_max_gewicht()
{

}

bool Lagerplatz:: einlagern( Artikel& artikel)
{


        if(artikel.get_flamm())
        {
            return false;
        }

        if(artikel.get_gewicht()<=max_gewicht)
        {
        artikeln.push_back(artikel);
            return true;
        }

            return false;
}
void Lagerplatz::platz_inventur() const
{
            for(const auto& artikel:artikeln)
            {
            cout << "Artikelnummer :: " << artikel.get_artikelnummer() <<endl;
            cout <<"Bezeichnung :: "<< artikel.get_bezeichnung()<<endl;
            cout <<"Anzahl :: "<< artikel.get_anzahl()<<endl;
            }
}
