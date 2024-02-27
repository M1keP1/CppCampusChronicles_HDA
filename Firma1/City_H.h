#ifndef CITY_H_H
#define CITY_H_H
#include<iostream>

using namespace std;

class Human;
class Company;

class city
{
private:
    string name{};
    vector<Human*> inhabitants;
    vector<Company*> companies;
public:
    city();
    city(string name):name(name){}
    void addinhabitant(Human* inhabitant );
    void addcompany(Company* company);
    string get_name();


};

#endif // CITY_H_H
