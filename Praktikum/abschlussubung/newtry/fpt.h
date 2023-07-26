#ifndef FPT H
#define FPT H

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
    void init_connections(vector<Liwanze> &vL);
    void make_conn(string,string,Liwanze);
    void add_Liwanze();
    
    


    private:

    string name{};
    Region loc;

    vector <string> connects_to;
    vector <string>connects_from;


};




#endif
