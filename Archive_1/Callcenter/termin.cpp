#include "termin.h"

string Termin::getPatient() const
{
    return patient;
}

void Termin::setGeloescht(bool newGeloescht)
{
    geloescht = newGeloescht;
}

string Termin::getDatumUhrzeit() const
{
    return datumUhrzeit;
}

void Termin::setTermin_2(const string &newTermin_2)
{
    termin_2 = newTermin_2;
}

string Termin::getTermin_2() const
{
    return termin_2;
}

string Termin::getvaccine()
{
    switch (vaccine) {
    case Impfstoff::Biontech:
        return"Bionetch";
        break;
    case Impfstoff::AstraZeneca:
        return"AstraZeneca";
        break;
    case Impfstoff::JohnsonJohnson:
        return"JohnsonJohnson";
        break;
    case Impfstoff::Moderna:
        return"Moderna";
        break;
    default:
        break;
    }
}

Termin::Termin(string p, string d):
    datumUhrzeit(d),
    patient(p)

{
    cout<<"Termin with name is created:"<<p<<endl;

}

Termin::Termin(string p, string d, Impfstoff vaccine):
    datumUhrzeit(d),
    patient(p),
    vaccine(vaccine)

{
    cout<<"Termin with name is created:"<<p<<endl;

}

Termin::Termin(string p, string d, Impfstoff vaccine, string termin_2):
    datumUhrzeit(d),
    patient(p),
    vaccine(vaccine),
    termin_2(termin_2)
{

}
