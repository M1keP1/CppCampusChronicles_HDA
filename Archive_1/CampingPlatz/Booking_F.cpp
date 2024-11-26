#include"Booking_H.h"

int Booking::get_from()
{
    return from;
}
int Booking::get_to()
{
    return to;
}
int Booking::get_visitors()
{
    return visitors.size();
}

double Booking::totalcost()
{
    return (to-from)*costpernight;
}

void Booking::setpayed(bool b)
{
    payed=b;
}
bool Booking::get_payed()
{
    return payed;
}
