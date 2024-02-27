#ifndef HUMAN_H_H
#define HUMAN_H_H
#include "City_H.h"
#include<iostream>
using namespace std;

class Company;

enum class sex{
    attackhelicopter,
    pan


};

class Human
{
private:
    string name{};
    city* City;
    sex gender;
    Company* employer;

public:
    Human();
    Human(string name,sex gender,city* City):name(name),gender(sex::attackhelicopter),City(City){}
    void changeSex(sex newgender);
    void movetocity(city* newcity);
    void workat(Company* company);
    void printdata();
    string get_gendername();

};

#endif // HUMAN_H_H
