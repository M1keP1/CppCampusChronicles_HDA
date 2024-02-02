#include "Booking_header.h"

Booking::Booking(int from, int to, vector<string> visitors, double costPerNight)
    : from(from), to(to), visitors(visitors), cost(costPerNight), payed(false)
{
    cost= (from-to)*costPerNight;
}

int Booking::get_from() const
{
    return from;
}

int Booking::get_to() const
{
    return to;
}

void Booking::set_from(int from)
{
    from=from;
}

int Booking::get_visitors() const
{
    return visitors.size();
}

bool Booking::get_paid() const
{
    return payed;
}
