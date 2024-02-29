#include "cinema.h"

int bookings_id{0};
void Cinema::booking(string name,int date,Seat * seat)
{
    Book* n=new Book(bookings_id++,name,date,seat);
    bookings.push_back(n);
}
