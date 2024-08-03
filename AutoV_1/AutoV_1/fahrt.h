#ifndef FAHRT_H
#define FAHRT_H
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class Fahrt
{
private:
    int nummer;
    string kunde;
    int abholdatum;
    int abgabedatum;
    double mietkosten;
public:
    Fahrt(int n,string k, int ab, int bis);
    void anzeigen();
    int getNummer() const;
    int getAbholdatum() const;
    int getAbgabedatum() const;
    double getMietkosten() const;
    void setMietkosten(double newMietkosten);
};

#endif // FAHRT_H
