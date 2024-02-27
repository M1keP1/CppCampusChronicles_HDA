#ifndef DEVICE_H_H
#define DEVICE_H_H
#include<iostream>
using namespace std;

class Device
{
private:
    string name{};
public:
    Device();
    Device(string name):name(name){}
    string get_name();
    void set_name(string newname);


};

#endif // DEVICE_H_H
