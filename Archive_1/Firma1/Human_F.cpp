//Created by Mihir on 28.02.2024

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
int Human::get_gehalt()
{
    if(get_gendername()=="Female")
    {
        return workdays*100;
    }
    else if(get_gendername()=="attackhelicopter")
    {
        return workdays*400;
    }
    else if(get_gendername()=="pan")
    {
        return 0;
    }
    else if(get_gendername()=="male")
    {
        return workdays*1000;
    }

    return 0;
}
string Human::getname()
{
    return name;
}
Company* Human::get_company()
{
    return employer;
}

//add get_gender name function that returns string based on enum switch
