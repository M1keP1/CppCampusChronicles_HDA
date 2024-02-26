#include "Herde_H.h"

string Herde:: get_Bezeichnung()
{
    return Bezeichnung;
}

int Herde:: get_anzahl_t()
{
    return anzahl_t;
}
int Herde:: get_platzbedarf()
{
    return platzbed_t;
}
void Herde :: increase_anzahl()
{
    anzahl_t+=1;
}
