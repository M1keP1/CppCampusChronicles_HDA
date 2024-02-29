#ifndef COPY_H
#define COPY_H
#include"reader.h"

class Copy
{
private:
    int Regal{};
    Book *book;
    Copy *copy;
    Reader *leser{nullptr};
public:
    Copy();
    Copy(int Regal,Book *book):Regal(Regal),book(book){}
    void set_regal(int n);
    int get_regal();
    Book* get_Book();
    Reader* get_Leser();
    void set_Leser(Reader* leser);




};

#endif // COPY_H
