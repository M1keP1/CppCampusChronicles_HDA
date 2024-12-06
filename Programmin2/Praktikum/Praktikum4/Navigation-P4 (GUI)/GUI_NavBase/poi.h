#ifndef POI_H
#define POI_H

#include "ort.h"
#include <string>

class PoI : public Ort
{
public:
    PoI(double lat, double lon, std::string name, std::string kat, std::string bem);
    void anzeigen() const override;

    std::string getKategorie() const;
    std::string getBemerkung() const;

private:
    std::string kategorie;
    std::string bemerkung;
};

#endif // POI_H
