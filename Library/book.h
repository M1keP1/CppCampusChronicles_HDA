#ifndef BOOK_H
#define BOOK_H
#include<iostream>
using namespace std;

class Book
{
private:
    string ISBN{};
    string Titel{};
    string Author{};
public:
    Book();
    Book(string ISBN,string Titel,string Author):ISBN(ISBN),Titel(Titel),Author(Author){}
    string get_isbn();
};

#endif // BOOK_H
