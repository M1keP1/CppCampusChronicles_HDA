#include"Furniture_H.h"

string Furniture::name()
{
    return txt;
}

void Furniture::print()
{
    cout<<"Name of Furniture: "<<name()<<endl;
}
