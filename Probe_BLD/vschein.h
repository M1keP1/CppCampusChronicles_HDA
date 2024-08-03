#ifndef VSCHEIN_H
#define VSCHEIN_H
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Vschein
{
public:
    Vschein(int scheinNummer,string vorname,string nachname);
    virtual void anzeigen()=0;
    int getScheinNummer() const;
    virtual  ~Vschein();
    virtual void anpassen();
private:
    int scheinNummer;
    string vorname;
    string nachname;
    double monatsbeitrag;

};

#endif // VSCHEIN_H
