//Created by Mihir on 28.02.2024


#ifndef CITY_H_H
#define CITY_H_H
#include<iostream>
#include <vector>


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
    string get_human_name();


};

#endif // CITY_H_H
