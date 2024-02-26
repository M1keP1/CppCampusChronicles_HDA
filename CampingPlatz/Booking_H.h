#ifndef BOOKING_H_H
#define BOOKING_H_H
#include<iostream>
using namespace std;

class Booking
{

private:

    string name{};
    int from{};
    int to{};
    vector<string>visitors;
    double cost{};
    bool payed{};


    int costpernight{};


public:
    Booking();
    Booking(int from,int to,int visitors,bool payed):from(from),to(to),visitors(visitors),payed(0){

    }
    void setpayed(bool b);
    bool get_payed();
    double totalcost();
    int get_from();
    int get_to();
    int get_visitors();




};

#endif // BOOKING_H_H
