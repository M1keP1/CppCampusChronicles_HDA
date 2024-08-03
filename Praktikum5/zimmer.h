#ifndef ZIMMER_H
#define ZIMMER_H
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Zimmer
{
public:
    Zimmer(int z);
    void addMoebel();
    void moebelAnzeigen();

    int getZimmerNummer() const;

    vector<string> getMoebelListe() const ;

private:
    int zimmerNummer;
    vector<string>moebelListe;

};

#endif // ZIMMER_H
