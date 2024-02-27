#include"human_H.h"
#include"Company_H.h"

void Human::changeSex(sex newgender)
{
    gender=newgender;
}

void Human::movetocity(city* newcity)
{
    City=newcity;
}
void Human::workat(Company* company)
{
    employer=company;
}
void Human::printdata()
{
    cout<<"---=Here are yoyr details=---"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"City: "<<City->get_name()<<endl;
    cout<<"Gender: "<<get_gendername()<<endl;
    cout<<"Company: "<<employer->get_name()<<endl;
}

//add get_gender name function that returns string based on enum switch
