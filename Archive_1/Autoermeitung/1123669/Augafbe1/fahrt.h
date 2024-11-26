#ifndef FAHRT_H
#define FAHRT_H
#include<iostream>
using namespace std;
#include<vector>

class fahrt
{

public:
    fahrt(int n, string k, int ab, int bis);
    void anzeigen();
    int getNummer() const;
    void ask();

private:
    int nummer{};
    string kunde{};
    int abholdatum{};
    int abgabedatum{};

};

#endif // FAHRT_H
