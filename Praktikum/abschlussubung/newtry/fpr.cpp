#include <iostream>
#include <string>
#include <vector>
#include "fpt.h"

using std::string;
using namespace std;


Liwanze::Liwanze(): name{"noname"}, loc{Region::ndef}{}

std::string Liwanze::get_name() const {return name;}

Liwanze::Region Liwanze::get_loc() const { return loc;}

void Liwanze::print() 
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Location: ";
    switch (loc)
    {
    case Region::ndef:
        std::cout << "Not defined";
        break;
    case Region::amer:
        std::cout << "America";
        break;
    case Region::apac:
        std::cout << "Asia-Pacific";
        break;
    case Region::emea:
        std::cout << "EMEA (Europe, Middle East, and Africa)";
        break;
    }
    std::cout << std::endl;
}

bool Liwanze::connects(string connectsto)
{
    for(int i{0};i<connects_to.size();i++)
    {
        if (connectsto == connects_to.at(i)){return true;}
    }
}

bool Liwanze::connected(string connectsfrom)
{
    for(int i{0};i<connects_from.size();i++)
    {
        if (connectsfrom == connects_from.at(i)){return true;}
    }
}

void Liwanze::init_connections()
{
    
}

void Liwanze::print_tierone()
{

}

bool Liwanze::addconn_to(string)
{

}

bool Liwanze::addconn_from(string)
{

}
