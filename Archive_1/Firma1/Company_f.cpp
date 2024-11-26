//Created by Mihir on 28.02.2024

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
int Company::calculate_expense()
{
    for(auto& h2:employees)
    {
        totalexpense+=h2->get_gehalt();
    }
    return 0;
}

int Company::get_employees()
{


    return employees.size();
}

