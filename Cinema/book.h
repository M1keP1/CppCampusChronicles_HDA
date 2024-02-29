#ifndef BOOK_H
#define BOOK_H
#include"seat.h"


class Book
{
private:
    int booked_id{};
    string name{};
    int date{};
    Seat* seat;

public:
    Book();
    Book(int id,string name,int date,Seat* seat):booked_id(id),name(name),date(date),seat(seat){}
    void addBooking(string name,int date,Seat * seat);
};

#endif // BOOK_H
