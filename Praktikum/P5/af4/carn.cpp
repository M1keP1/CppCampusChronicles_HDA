#include "carn.h"

#include <iostream>
#include <string>
using namespace std;
using std::string;


Car::Car(string n) : name{n}{}      //constructor for class car

Car::Car() : Car(noname) {}     //default constructor

Van::Van() : doors{0}, mileage{0} {}

Van::Van(string n ,int door,int mil) : Car{n}, doors{door},mileage{mil} {}

int Van::getdoors() const{ return doors;}
int Van::getmileage() const{ return mileage;}
void Van::print() const
{
    cout << "van" << <<"mit"<<getdoors()<<"doors"<< getmileage()<<endl;
}

Sportscar::Sportscar():horsepower{0} {}
Sportscar::Sportscar(string n, int h): Car{n}, horsepower{h} {}

int Sportscar::gethorsepower() const {return horsepower;}
void Sportscar::print() const
{
    cout << "sc" << <<"mit"<<gethorsepower()<<endl;
}

Suv::Suv():rooftop{false}, cruisecontrol_at{0} {};

Suv::Suv(string n, int h, bool b, int ctrl) : Sportscar{n,h},rooftop{b} , cruisecontrol_at{ctrl} {};

bool Suv::getrooftop() const{return rooftop;};

int Suv::getcruisevalue() const{return cruisecontrol_at;};

void Suv::print() const
{
    cout << "suv" << getcruisevalue()<<"mit"<<getrooftop()<<endl;
}

Luxurycar::Luxurycar():has_bar{false}{}
Luxurycar::Luxurycar(string n,bool b):Car{n},has_bar{b}{}

void Luxurycar::print() const
{
    cout << "lc" << has_bar<<"bar"<<endl;
}

bool Luxurycar::get_bar() const{ return has_bar;}

Strechlimo::Strechlimo():seats{0} {}
Strechlimo::Strechlimo(string n,bool b,int s): Luxurycar{n,b},seats{s}{}

void Strechlimo::print() const
{
    cout << "sl" << seats()<<"mit"<<get_bar()<<endl;
}
