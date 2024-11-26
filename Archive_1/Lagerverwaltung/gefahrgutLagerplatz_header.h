#ifndef GEFAHRGUTLAGERPLATZ_HEADER_H
#define GEFAHRGUTLAGERPLATZ_HEADER_H
#include "lagerplatz_func.cpp"

class GefahtgutLagerplatz : public Lagerplatz
{
private:
    bool entflammbar{};
public:
    bool einlagern(Artikel& artikel) override;


};

#endif // GEFAHRGUTLAGERPLATZ_HEADER_H
