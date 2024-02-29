#ifndef SPIELFELD_H
#define SPIELFELD_H
#include"Ship_H.h"


class Spielfeld
{
private:
    vector<Schiff>ships;
    vector<vector<char>>leinwand;




public:


    Spielfeld() {

        leinwand.assign(10,vector<char>(10, '.'));

        // Schiffe initialisieren

        for(auto& s:ships)
        {
            s.zeichne(leinwand);
        }
    }
    void ausgeben();
    void spielen();


};

#endif // SPIELFELD_H
