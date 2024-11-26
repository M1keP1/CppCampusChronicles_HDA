#include "abonnent.h"



string Abonnent::getName() const
{
    return name;
}

Abonnent::Abonnent(string name):
    name(name)
{

}

void Abonnent::abonniere(Zeitung &zeitung)
{
    meineZeitung = &zeitung;
}
