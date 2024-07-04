#include "seat.h"

bool Seat::ticket_bought()
{
    return booked;
}
void Seat::set_bought()
{
    booked=true;
}
void Seat::set_reihe(int r)
{
    reihe=r;
}
void Seat::set_sitz(int s)
{
    sitz=s;
}
