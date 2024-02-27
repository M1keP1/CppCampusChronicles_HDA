#include"City_H.h"

void city:: addinhabitant(Human* inhabitant)
{
    inhabitants.push_back(inhabitant);
}
void city::addcompany(Company* company)
{
    companies.push_back(company);
}
string city::get_name()
{
    return name;
}
