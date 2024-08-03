#ifndef TERMIN_H
#define TERMIN_H
#include <string>
using namespace std;

enum Impfstoff{Biontech, Moderna, AstraZeneca, JohnsonJohnson};
static const char *enumStr[] = {"Biontech", "Moderna", "AstraZeneca", "JohnsonJohnson"};  // enum to string

class Termin
{
public:
    Termin(string patient, string datumUhrzeit, Impfstoff impfstoff);
    string getPatient() const;
    string getDatumUhrzeit() const;
    bool getGeloescht() const;
    void setGeloescht(bool value);
    Impfstoff getImpfstoff() const;
    bool operator<(const Termin& t);
private:
    string datumUhrzeit;
    string patient;
    bool geloescht = false;
    Impfstoff impfstoff;
};

#endif // TERMIN_H

