//Created by Mihir on 28.02.2024

#ifndef COMPANY_H_H
#define COMPANY_H_H
#include"human_H.h"
#include <vector>
enum class sector{

};

class Company
{


private:
    string name{};
    sector sectortyp;
    vector<city*> locations;
    vector<Human*> employees;
    int totalexpense{};


public:

    Company();
    Company(string name):name(name){}
    void addLocation(city* location);
    void employ(Human* employee);
    string get_name();
    int calculate_expense();
    int get_employees();
};


#endif // COMPANY_H_H
