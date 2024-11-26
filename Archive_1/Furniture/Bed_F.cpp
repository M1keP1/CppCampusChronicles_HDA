#include"Bed_H.h"

void Bed::print()
{
    print();
    switch(size)
    {
    case sz::single:
        cout<<"Single Bed"<<endl;

    case sz::doble:
        cout<<"Double Bed"<<endl;
    case sz::king:
        cout<<"King size Bed"<<endl;

    case sz::superking:
        cout<<"Superking size bed"<<endl;

    case sz::queen:
        cout<<"Queen size bed"<<endl;

    default:
        cout<<"ERR"<<endl;

    }
}



