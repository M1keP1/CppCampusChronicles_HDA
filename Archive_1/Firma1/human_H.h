//Created by Mihir on 28.02.2024

#ifndef HUMAN_H_H
#define HUMAN_H_H
#include "City_H.h"
#include<iostream>
using namespace std;

class Company;

enum class sex{
    attackhelicopter,
    pan,
    female,male


};

class Human
{
private:
    string name{};
    city* City;
    sex gender;
    Company* employer;
    int workdays{};

public:
    Human();
    Human(string name,sex gender,city* City):name(name),gender(sex::attackhelicopter),City(City){}
    void changeSex(sex newgender);
    void movetocity(city* newcity);
    void workat(Company* company);
    void printdata();
    string getname();
    string get_gendername();
    int virtual get_gehalt();
    Company* get_company();

};

#endif // HUMAN_H_H
