#include <iostream>
#include "myvector.h"
#include "mymethoden.cpp"
int main()
{
    myvector v1{10};
    // std::cout<<"size: "<<v1.size();
       std::cout << std::endl;
       v1.push_back(110.0);
       v1.push_back(11.0);
       v1.push_back(1.0);

           // std::cout<<v1.size();

       myvector v2(v1);
           // v2.set(0,5.4);
       std::cout << std::endl;
           // std::cout<<v2.size();

       /*for(int i{0};i<v2.size();i++)
       {
           std::cout<<v2.get(i)<<std::endl;
       }*/

       myvector v3{}; // yaha value dekar puch
       v3 = v2;
       
       /*std::cout<<v3.size();
       for(int i{0};i<v3.size();i++)
       {
           std::cout<<v3.get(i)<<std::endl;
       }*/
       
       v3.resize(17);
       std::cout << v3.size() << std::endl;
       for (int i{0}; i < v3.size(); i++)
       {
           std::cout << v3.get(i) << std::endl;
    }
    return 0;
}
