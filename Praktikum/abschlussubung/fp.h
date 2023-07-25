#ifndef fp.h
#define fp .h

#include <iostream>
using std::string;
using namespace std;

class Liwanze
{
public:
    
    
    enum class Region {
        ndef,
        amer,
        apac,
        emea
    };
    Liwanze();
    Liwanze(const std::string& name, Region loc = Region::ndef);
    string get_name() const;
    Region get_loc() const;
    void print() ;


private:
    string name{};
    Region loc;
};

#endif