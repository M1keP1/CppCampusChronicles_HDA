#ifndef VSCHEIN_H
#define VSCHEIN_H
#include <iostream>
#include <string>
using namespace std;



class Vschein
{
public:
    Vschein(int sNummer,string vName,string nName);
    virtual void anzeigen();
    int getScheinNr();

    int getScheinNummer() const;
    void setScheinNummer(int newScheinNummer);

    string getVorname() const;
    void setVorname(const string &newVorname);

    string getNachname() const;
    void setNachname(const string &newNachname);

private:
    int scheinNummer{};
    string vorname{};
    string nachname{};
};

#endif // VSCHEIN_H
