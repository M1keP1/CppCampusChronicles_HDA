#include "Plot_header.h"

Plot::Plot(int id,double size,double costPerNight):id(id),size(size),costPerNight(costPerNight)
{

}

int Plot::get_id()
{
    return id;
}

double Plot::get_size()
{
    return size;
}

double Plot::get_costPerNight()
{
    return costPerNight;
}

void Plot::get_bookings()
{

    cout << "ERR: I cant do this "<<endl;
    //something here to print out bookings
}

void Plot::set_id(int id)
{
    id=id;
}
void Plot::set_size(double size)
{
    size=size;
}
void Plot::set_costPerNight(double costPerNight)
{
    costPerNight=costPerNight;
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

    if(bookingPossible(b.get_from(),b.get_to(),get_visitors()) && get_paid()) //add function call here to check if a booking is possible
    {
        bookings.push_back(b);
    }
}


