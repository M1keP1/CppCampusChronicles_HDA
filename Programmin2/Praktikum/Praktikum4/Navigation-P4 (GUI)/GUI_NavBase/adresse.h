#ifndef ADRESSE_H
#define ADRESSE_H
#include "ort.h"
#include <string>

class Adresse : public Ort
{
public:
    Adresse(double lat, double lon, std::string name, std::string str, int nr, std::string p, std::string g);
    void anzeigen() const override;

    std::string getStrasse() const;
    int getHausnummer() const;
    std::string getPlz() const;
    std::string getGemeinde() const;

private:
    std::string strasse;
    int hausnummer;
    std::string plz;
    std::string gemeinde;
};

#endif // ADRESSE_H
