#ifndef TERMIN_H
#define TERMIN_H
#include <iostream>
#include <vector>

using namespace std;

enum class Impfstoff{
    Biontech, Moderna, AstraZeneca, JohnsonJohnson
};

class Termin
{
private:
    string datumUhrzeit;
    string termin_2;
    string patient;
    bool geloescht{false};
    Impfstoff vaccine;

public:
    Termin(string p,string d);
    Termin(string p,string d,Impfstoff vaccine);
    Termin(string p,string d,Impfstoff vaccine,string termin_2);
    string getPatient() const;
    void setGeloescht(bool newGeloescht);
    string getDatumUhrzeit() const;
    void setTermin_2(const string &newTermin_2);
    string getTermin_2() const;
    string getvaccine();
};

#endif // TERMIN_H
