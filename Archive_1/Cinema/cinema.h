#ifndef CINEMA_H
#define CINEMA_H
#include"book.h"


class Cinema
{
private:
    int id{0};
    string sitzco{};
    int reihe{};
    int platz{};
    Seat* seat;

    vector<Seat*>seats;
    vector<Book*>bookings;
public:
    Cinema();
    Cinema(int reihe,int platz):reihe(reihe),platz(platz)
    {
        for(int i=1;i<=reihe;i++)
        {
            for(int j=1;j<=platz;j++)
            {
                Seat* n=new Seat(id++,i,j,false,0.0);
                seats.push_back(n);
            }
        }
    }
    Cinema(string sitzco):sitzco(sitzco)
    {
        for(int i=1;i<=sitzco.size();i++)
        {
            Seat* n=new Seat(id++,i,sitzco[i],false,0.0);
            seats.push_back(n);
        }
    }
    void booking(string name,int date,Seat * seat);



};

#endif // CINEMA_H
