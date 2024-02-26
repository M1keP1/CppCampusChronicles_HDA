#include"Gehege_H.h"

bool Gehege::aufnehmen(Herde& hn)
{

    if(hn.get_anzahl_t()<= getPlatz() && hn.get_anzahl_t()<=hn.get_platzbedarf() && raubtier==false)
    {
        herds.push_back(hn);
        return true;
    }

    return false;
}

int Gehege::get_actual_capacity()
{
    for(auto& h1:herds)
    {
        actual_capacity+=h1.get_anzahl_t();
    }
    return actual_capacity;
}

int Gehege::getPlatz()

{
    //not used
    return max_capacity-get_actual_capacity();
}
int Gehege:: get_ID()
{
    return ID;
}
int Gehege:: get_max_capacity()
{
    return max_capacity;
}
vector<Herde> Gehege::get_herd()
{
    return herds;
}
bool Gehege::get_raubtier()
{
    return raubtier;
}
void Gehege::set_raubtier()
{
    raubtier=1;
}

