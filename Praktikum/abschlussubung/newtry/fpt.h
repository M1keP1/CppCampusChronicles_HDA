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

    bool connects(string);
    bool connected(string);
    void print_tierone();
    bool addconn_to(string);
    bool addconn_from(string);
    void init_connections();
    


    private:

    string name{};
    Region loc;

    vector <string> connects_to;
    vector <string>connects_from;


};




#endif
