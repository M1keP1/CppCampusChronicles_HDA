#ifndef SEAT_H
#define SEAT_H
#include<iostream>
using namespace std;


class Seat
{
private:
    int nummer{};
    int reihe{};
    int sitz{};
    bool booked{false};
    double preis{};

public:
    Seat();
    Seat(int nummer,int reihe,int sitz,bool booked,double preis):nummer(nummer),reihe(reihe),sitz(sitz),booked(booked),preis(preis){}
    bool ticket_bought();
    void set_bought();
    void set_reihe(int r);
    void set_sitz(int s);
};

#endif // SEAT_H
