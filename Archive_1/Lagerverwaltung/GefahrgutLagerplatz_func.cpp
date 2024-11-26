    #include "gefahrgutLagerplatz_header.h"


bool GefahtgutLagerplatz::einlagern(Artikel& artikel)
{
    bool flammartikel{0};

    if(artikel.get_flamm()==1 && flammartikel==1)
    {
        return false;
    }
    else if(artikel.get_flamm()==1 && flammartikel==0)
    {
        if(artikel.get_gewicht()<=get_max_gewicht())
        {
            artikeln.push_back(artikel);
            return true;
        }
    }
    return true;

}
