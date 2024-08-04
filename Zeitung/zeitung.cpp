#include "zeitung.h"



string Zeitung::getName() const
{
    return name;
}

Zeitung::Zeitung(string name):
    name(name)
{

}

void Zeitung::addAbonnent(Abonnent *abonnent)
{
    abonnenten.push_back(abonnent);
}
