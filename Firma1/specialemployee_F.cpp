#include"specialemployee_H.h"
#include"Company_H.h"
#include<random>



int consulter::get_gehalt()
{

    return generateRandomNumber(150000,250000);
}
 int manager::get_gehalt()
{
    int geh{};
    geh= get_company()->get_employees() *5;
    return geh ;
}
int consulter::generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
}
