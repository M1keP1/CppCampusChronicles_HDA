#include "library.h"
#include<cmath>
int regal_nummer{};
void Library::add_book(Book* book,int anzahl)
{


    books.push_back(book);
    for(int i=1;i<=anzahl;i++)
    {
        if(copies.size()/books_in_regal<=1)
        {
            regal_nummer=1;
        }

        Copy* n= new Copy(regal_nummer,book);
        copies.push_back(n);
        n->set_regal(ceil(copies.size()/books_in_regal));
        regal_nummer=n->get_regal();

    }
}

void Library::registerReader(Reader* reader)
{
    readers.push_back(reader);
}
int Library::searchBook(string isb)
{
    int books_besetzt{};
    for(auto& b2:books)
    {
        if(b2->get_isbn()==isb)
        {
            return -1;
        }
    }
    for(auto& c1:copies)
    {
        if(c1->get_Book()->get_isbn()==isb && c1->get_Leser()==nullptr)
        {


            cout<<c1->get_regal();
        }


    }
    return -2;
}

bool Library::lendBook(string isb,Reader* reader)
{
    for(auto& c3:copies)
    {
        for(auto& r1:readers)
            {

                if(c3->get_Book()->get_isbn()==isb && r1==reader)
                {
                    c3->set_Leser(reader);
                    return true;
                }
            }
    }
    return false;
}

