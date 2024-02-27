#ifndef COMPANY_H_H
#define COMPANY_H_H
#include"human_H.h"
enum class sector{

};

class Company
{


private:
    string name{};
    sector sectortyp;
    vector<city*> locations;
    vector<Human*> employees;

public:

    Company();
    Company(string name):name(name){}
    void addLocation(city* location);
    void employ(Human* employee);
    string get_name();
};


#endif // COMPANY_H_H
