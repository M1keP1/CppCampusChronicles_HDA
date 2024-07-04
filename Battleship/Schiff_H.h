//Created by Mihir on 29.02.2024
#ifndef SCHIFF_H_H
#define SCHIFF_H_H
#include<iostream>
using namespace std;

enum class Status
{
    unbeschadigt,
    getroffen,
    versenkt
};


enum class Direction
{
    Nord,
    Ost,
    West
};

class Schiffteil
{
private:
    int m_reihe{};
    int m_spalte{};
    Status m_status;

public:
    Schiffteil();
    inline void setReihe(int newReihe)
    {
        m_reihe = newReihe;
    }

    Schiffteil(int reihe,int spalte,Status status):m_reihe(reihe),m_spalte(spalte),m_status(status){}

    int get_reihe();
    int get_spalte();
    Status get_status();
    void set_status(Status stat);

    void setReihe(int newReihe);
};

#endif // SCHIFF_H_H
