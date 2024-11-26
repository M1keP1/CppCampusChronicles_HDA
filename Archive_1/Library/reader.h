#ifndef READER_H
#define READER_H
#include"book.h"


class Reader
{
private:
    string name{};
    string adresse{};
public:
    Reader();
    Reader(string name,string adresse):name(name),adresse(adresse){}

};

#endif // READER_H
