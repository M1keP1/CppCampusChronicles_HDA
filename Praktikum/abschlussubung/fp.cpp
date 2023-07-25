#include "fp.h"
#include <iostream>
using std::string;
using namespace std;

Liwanze::Liwanze() : name{"noname"}, loc{Region::ndef} {}

Liwanze::Liwanze(const std::string& name, Region loc) {
    if (!name.empty()) {
        name = name;
    } else {
        name = "Unnamed";
    }
    loc = loc;
}

std::string Liwanze::get_name() const { return name; }

Liwanze::Region Liwanze::get_loc() const { return loc; }

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
