#include <iostream>
#include <string>
#include <cmath>

bool isCube(int num)
{

    bool decision=false;

    int sub= std::pow(num,1/3);
    if(static_cast<int>(sub)%1==0)
    {
        decision=true;
    }
    

    return decision;
}

float userInput()
{
    float inp;
    std::cout << "Enter a number"<< std::endl;
    std::cin >> inp;
    return inp;
}

void cubesUntil(int until)
{
    int n=1;
    while(n<=until)
    {
        if(isCube(n))
        {
            std::cout << "The number " << n << "is a Cube" << std::endl;

        }
    }
}

int main()
{
    isCube(9);

    return 0;
}

