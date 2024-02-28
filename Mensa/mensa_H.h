#ifndef MENSA_H_H
#define MENSA_H_H
#include<iostream>
using namespace std;

class Meal
{
private:
    string name{};
    double price{};
    bool is_vegan{};
public:
    Meal();
    Meal(string name,double price,bool is_vegan):name(name),price(price),is_vegan(is_vegan){}
    void printgericht()
    {
        cout<<"Name of gericht: "<<name<<endl;
        cout<<"Price of gericht: "<<price<<endl;
        cout<<"Is Vegan?: "<<is_vegan<<endl;
    }

};

#endif // MENSA_H_H
