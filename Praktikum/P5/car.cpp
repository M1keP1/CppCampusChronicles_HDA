#include <iostream>
#include "car.h"
#include <string>
using namespace std;

car::car(string n) : name{n}, next{last} { last = this; }
car::car() : car{noname} {}
string car::get_name() const { return name; }
car *car::get_next() const { return next; }
car *car::get_last() const { return last; }
car *car::sget_last() { return last; }

car *car::last{nullptr};

Van::Van() : doors{0}, mileage{0} {}
Van::Van(string n, int dor, int mil) : car{n}, doors{dor}, mileage{mil} {}
int Van::getdoors() const
{
  return doors;
}
int Van::getmileage() const
{
  return mileage;
}
void Van::print() const
{
  cout << "Van " << get_name() << " mit " << getdoors() << " Türen und ";
  cout << getmileage() << " mileage";
}

sportscar::sportscar() : horsepower{0} {}
sportscar::sportscar(string n, int h) : car{n}, horsepower{h} {}
int sportscar::gethorsepower() const { return horsepower; }
void sportscar::print() const
{
  std::cout << "Sportwagen " << get_name() << " mit " << horsepower << " PS";
}

suv::suv() : rooftop{false}, cruisecontrol_at{0} {};

suv::suv(string n, int h, bool b, int ctrl) : sportscar{n, h}, rooftop{b}, cruisecontrol_at{ctrl} {};
bool suv::getrooftop() const { return rooftop; };
int suv::getcruisevalue() const { return cruisecontrol_at; };
void suv::print() const
{
  std::cout << "Suv " << get_name() << " mit " << gethorsepower() << " PS"
            << " , cuise control is available at " << getcruisevalue();
  rooftop ? cout << "mit rooftop" : cout << "ohne rooftop";
}
Luxurycar::Luxurycar() : has_bar{false} {}
Luxurycar::Luxurycar(string n, bool b) : car{n}, has_bar{b} {}

void Luxurycar::print() const
{
  cout << "Luxuskarosse " << get_name();
  has_bar ? cout << " mit" : cout << " ohne";
  cout << " Cocktailbar";
}
bool Luxurycar::get_bar() const
{
  return has_bar;
}

Stretchlimo::Stretchlimo() : seats{0} {}
Stretchlimo::Stretchlimo(string n, bool b, int s) : Luxurycar{n, b}, seats{s} {}
void Stretchlimo::print() const
{
  cout << "Stretch-Limousine " << get_name() << " mit " << seats << " Sitzen";
  get_bar() ? cout << " und" : cout << ", ohne";
  cout << " Cocktailbar";
}
