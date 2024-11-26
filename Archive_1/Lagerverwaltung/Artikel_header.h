#ifndef ARTIKEL_HEADER_H
#define ARTIKEL_HEADER_H
#include<iostream>
#include<string>
using namespace std;


class Artikel
{
public:

    Artikel();
    Artikel(int artikelnummer,string bezeichnung,int anzahl,int gewicht):artikelnummer(),bezeichnung(),anzahl(),gewicht(){}
    int get_artikelnummer() const;
    string get_bezeichnung() const;
    int get_anzahl() const;
    int get_gewicht() const;
    bool get_flamm() const;

    void increase_anzahl();




private:
    int artikelnummer{};
    string bezeichnung{};
    int anzahl{};
    int gewicht{};
    bool flamm{};


};

#endif // ARTIKEL_HEADER_H
