
#include "header.h"




player::player(const std::string &n):name(n){}

void player::set_name(const std::string &n)
{
    name=n;
}

std::string player::get_name()
{
    return name;
}

int player::get_price_money()
{
    return pricemoney;
}
void player::set_pricemoney(int change)
{
    pricemoney+=change;
}

int generateRandomNumber(int min, int max)
{
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(min, max); // Define the range

    return distr(gen); // Generate the random number
}

void play(int guess,int mode,int amount,player &obj)
{
    switch(mode)
    {
    case 'f':
        if(generateRandomNumber(1,36)%2==0&&guess%2==0)
        {
            cout <<"Congrats you won!!!"<<endl;
            obj.set_pricemoney(amount);
        }
        else
        {
            cout<<"U got scammed"<<endl;
            obj.set_pricemoney(-amount);
        }


        break;
    case 's':
        if(generateRandomNumber(0,36)%3 == guess%3)
        {
            cout <<"Congrats you won!!!"<<endl;
            obj.set_pricemoney(2*amount);
        }
        else
        {
            cout<<"U got scammed"<<endl;
            obj.set_pricemoney(-amount);
        }


        break;

    case 'z':

        if(generateRandomNumber(0,36)==guess)
        {
            cout <<"Congrats you won!!!"<<endl;
            obj.set_pricemoney(guess*obj.get_price_money());
        }
        else
        {
            cout<<"U got scammed"<<endl;
            obj.set_pricemoney(-amount);
        }

        cout << obj.get_price_money();


        break;

    default:
        cout<<"Enter valid mode"<<endl;
        break;
    }


}
//function to check existing users





