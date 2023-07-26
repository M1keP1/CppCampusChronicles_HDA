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
    for(const auto& ct: connects_to)
    {
        if (connectsto == ct){return true;}
    }
}

bool Liwanze::connected(string connectsfrom)
{
    for(const auto& cf: connects_from)
    {
        if (connectsfrom == cf){return true;}
    }
}


bool Liwanze::addconn_to(string to)
{
    if (connects(to)== false){connects_to.push_back(to);return true;}

    return false;
}

bool Liwanze::addconn_from(string from)
{
    if(connected(from)== false){connects_from.push_back(from);return true;}

    return false;
}

void make_conn(string x,string y,vector<Liwanze> &vL)
{
    int xi{0};
    int yi{0};
    int ct{1};

    for (const auto& z : vL)
    {
        if (x==z.get_name()){xi=ct;}
        if (y==z.get_name()){yi=ct;}
        ct++;
    }

    vL.at(xi).addconn_to(vL.at(yi).get_name());
    vL.at(yi).addconn_from(vL.at(xi).get_name());

}
    
void Liwanze::init_connections(vector<Liwanze>&vL)
{
    
    
}
void add_Liwanze()
{

}



void Liwanze::print_tierone()
{

}