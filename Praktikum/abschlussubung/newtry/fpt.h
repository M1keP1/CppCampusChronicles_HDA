#ifndef fpt.h
#define fpt.h

#include <iostream>
#include <string>
#include <vector>
using std::string;
using namespace std;


class Liwanze 
{

    public:
    Liwanze();
    
    enum class Region
    {
        ndef=1,
        amer,
        apac,
        emea

    };

    Liwanze(const std::string& name, Region loc = Region::ndef);
    string get_name() const;
    Region get_loc() const;

    void add_Liwanze() const;

    void print();


    private:

    string name{};
    Region loc;

};




#endif
