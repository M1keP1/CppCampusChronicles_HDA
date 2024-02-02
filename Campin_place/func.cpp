#include "header.h"



Booking::Booking(int from, int to, vector<string> visitors, double costPerNight)
    : from(from), to(to), visitors(visitors), cost(costPerNight), payed(false)
{
    cost= (from-to)*costPerNight;
}



Plot::Plot(int id,double size,double costPerNight):id(id),size(size),costPerNight(costPerNight)
{

}


bool Plot::bookingPossible(int from,int to,int visitors)
{
    if(visitors*4<=size)
    {
        return true;
    }
    return false;
}

void Plot::book(const Booking& b)
{
    if(2>1) //add function call here to check if a booking is possible
    {
        //add segment here to add booking
    }
}

Camping::Camping(string name):name(name)
{

}

