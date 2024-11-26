#ifndef FURNITURE_H_H
#define FURNITURE_H_H
#include<iostream>
using namespace std;

class Furniture
{
private:
    string txt{};
public:
    Furniture();
    Furniture(string txt){
        if(txt=="")
        {
            cerr<<"name cannot be empty"<<endl;
        }
        else
        {
            this->txt=txt;
        }
    }
    string name();

    void print();




};

#endif // FURNITURE_H_H
