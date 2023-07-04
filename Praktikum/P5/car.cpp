#include <iostream>
#include "car.h"
#include <string>
using namespace std;

car::car(string n) : name{n}, next{last} { last = this; }
// Constructor for the car class. Initializes the name with the given value 'n'.
// Assigns the current object as the next object in the linked list of cars.
// Updates the 'last' pointer to point to the current object.

car::car() : car{noname} {}
// Default constructor for the car class. Calls the parameterized constructor
// with the value 'noname', which is a global constant defined outside the class.

string car::get_name() const { return name; }
// Getter function that returns the name of the car.

car *car::get_next() const { return next; }
// Getter function that returns the pointer to the next car in the linked list.

car *car::get_last() const { return last; }
// Getter function that returns the pointer to the last car in the linked list.

car *car::sget_last() { return last; }
// Static function that returns the pointer to the last car in the linked list.

car *car::last{nullptr};
// Static member variable that holds the pointer to the last car in the linked list. Initialized to nullptr.

Van::Van() : doors{0}, mileage{0} {}
// Default constructor for the Van class. Initializes the number of doors and mileage to 0.

Van::Van(string n, int dor, int mil) : car{n}, doors{dor}, mileage{mil} {}
// Parameterized constructor for the Van class. Initializes the name with the given value 'n'.
// Initializes the number of doors and mileage with the given values 'dor' and 'mil', respectively.

int Van::getdoors() const
{
  return doors;
}
// Getter function that returns the number of doors of the Van.

int Van::getmileage() const
{
  return mileage;
}
// Getter function that returns the mileage of the Van.

void Van::print() const
{
  cout << "Van " << get_name() << " mit " << getdoors() << " Türen und ";
  cout << getmileage() << " mileage";
}
// Prints the details of the Van, including its name, number of doors, and mileage.

sportscar::sportscar() : horsepower{0} {}
// Default constructor for the sportscar class. Initializes the horsepower to 0.

sportscar::sportscar(string n, int h) : car{n}, horsepower{h} {}
// Parameterized constructor for the sportscar class. Initializes the name with the given value 'n'.
// Initializes the horsepower with the given value 'h'.

int sportscar::gethorsepower() const { return horsepower; }
// Getter function that returns the horsepower of the sportscar.

void sportscar::print() const
{
  std::cout << "Sportwagen " << get_name() << " mit " << horsepower << " PS";
}
// Prints the details of the sportscar, including its name and horsepower.

suv::suv() : rooftop{false}, cruisecontrol_at{0} {};
// Default constructor for the suv class. Initializes the rooftop to false and cruisecontrol_at to 0.

suv::suv(string n, int h, bool b, int ctrl) : sportscar{n, h}, rooftop{b}, cruisecontrol_at{ctrl} {};
// Parameterized constructor for the suv class. Initializes the name with the given value 'n'.
// Initializes the horsepower with the given value 'h'.
// Initializes the rooftop with the given value 'b'.
// Initializes the cruisecontrol_at with the given value 'ctrl'.

bool suv::getrooftop() const { return rooftop; };
// Getter function that returns the value of rooftop for the suv.

int suv::getcruisevalue() const { return cruisecontrol_at; };
// Getter function that returns the value of cruisecontrol_at for the suv.

void suv::print() const
{
  std::cout << "Suv " << get_name() << " mit " << gethorsepower() << " PS"
            << " , cuise control is available at " << getcruisevalue();
  rooftop ? cout << "mit rooftop" : cout << "ohne rooftop";
}
// Prints the details of the suv, including its name, horsepower, availability of cruise control, and rooftop status.

Luxurycar::Luxurycar() : has_bar{false} {}
// Default constructor for the Luxurycar class. Initializes the has_bar to false.

Luxurycar::Luxurycar(string n, bool b) : car{n}, has_bar{b} {}
// Parameterized constructor for the Luxurycar class. Initializes the name with the given value 'n'.
// Initializes the has_bar with the given value 'b'.

void Luxurycar::print() const
{
  cout << "Luxuskarosse " << get_name();
  has_bar ? cout << " mit" : cout << " ohne";
  cout << " Cocktailbar";
}
// Prints the details of the Luxurycar, including its name and the presence of a cocktail bar.

bool Luxurycar::get_bar() const
{
  return has_bar;
}
// Getter function that returns the value of has_bar for the Luxurycar.

Stretchlimo::Stretchlimo() : seats{0} {}
// Default constructor for the Stretchlimo class. Initializes the number of seats to 0.

Stretchlimo::Stretchlimo(string n, bool b, int s) : Luxurycar{n, b}, seats{s} {}
// Parameterized constructor for the Stretchlimo class. Initializes the name with the given value 'n'.
// Initializes the has_bar with the given value 'b'.
// Initializes the seats with the given value 's'.

void Stretchlimo::print() const
{
  cout << "Stretch-Limousine " << get_name() << " mit " << seats << " Sitzen";
  get_bar() ? cout << " und" : cout << ", ohne";
  cout << " Cocktailbar";
}
// Prints the details of the Stretchlimo, including its name, number of seats, and the presence of a cocktail bar.
