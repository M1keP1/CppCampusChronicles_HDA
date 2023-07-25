#include "fpt.h"
#include "fpr.cpp"
#include <iostream>
using std::string;
using namespace std;

int main()
{

    vector<Liwanze> vL 
    {
        Liwanze("Joey",Liwanze::Region::amer),
        Liwanze("Johnny",Liwanze::Region::amer),
        Liwanze("DeeDee",Liwanze::Region::amer),
        Liwanze("Tommy",Liwanze::Region::emea),
        Liwanze("Suzy",Liwanze::Region::apac),
        Liwanze("Sheena",Liwanze::Region::amer)


    };
}