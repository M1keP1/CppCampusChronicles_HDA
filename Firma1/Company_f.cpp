#include"Company_H.h"


void Company::addLocation(city* Location)
{
    locations.push_back(Location);
}
void Company::employ(Human* employee)
{
    employees.push_back(employee);
}
string Company::get_name()
{
    return name;
}
