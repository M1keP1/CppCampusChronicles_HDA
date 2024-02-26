#include"Plot_H.h"




bool Plot::bookingPossible(int from,int to,int visitors,vector<feature>fer)
{
    for(auto& b1:bookings)
    {
        if(size>=4*visitors && b1.get_from()!=from && b1.get_to()!=to && true)//add condition here that checks if feaetures match or not
        {
            return true;
        }

    }
    return false;
}

void Plot::book(Booking b)
{

    if(bookingPossible(b.get_from(),b.get_to(),b.get_visitors(),get_features()))
    {
        bookings.push_back(b);
    }
}

int Plot::get_id()
{
    return id;
}
double Plot::get_size()
{
    return size;
}
int Plot::get_anzahl_buchung()
{
    return anzahl_buchung;
}
void Plot::increase_anazhl_buchungen()
{
    anzahl_buchung++;
}

vector<feature> Plot::get_features()
{
    return features;
}
