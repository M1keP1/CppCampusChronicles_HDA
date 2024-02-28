#include"City_H.h"
#include"human_H.h"
class Human;

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
string city::get_human_name()
{
    string human_name{};
    for(auto& h3:inhabitants)
    {
        human_name=h3->getname();
        return human_name;
    }
    return "name error";

}
