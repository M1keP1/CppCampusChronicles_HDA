#ifndef BOOKING_HEADER_H
#define BOOKING_HEADER_H

#include <iostream>
using namespace std;



class Booking
{

private:
    int from{};
    int to{};
    vector<string>visitors;
    double cost{};
    bool payed{};


public:
    Booking(int from,int to,vector<string>visitors,double costPerNight);
    Booking() : from(0), to(0), cost(0), payed(false) {}
    void setPayed();
    int get_from() const;
    int get_to() const;
    void set_from(int from);
    void set_to(int to);
    int get_visitors() const;
    bool get_paid() const;



};

#endif // BOOKING_HEADER_H
