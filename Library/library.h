#ifndef LIBRARY_H
#define LIBRARY_H
#include"copy.h"


class Library
{
private:
    vector<Book*> books;
    vector<Copy*> copies;
    vector<Reader*> readers;
    const int books_in_regal{} ;

public:
    Library();
    Library(int booksregal):books_in_regal(booksregal){}
    void add_book(Book *book,int anzahl);
    void registerReader(Reader* reader);
    int searchBook(string isb);
    bool lendBook(string isb,Reader* reader);
};

#endif // LIBRARY_H
