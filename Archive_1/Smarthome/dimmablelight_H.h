#ifndef DIMMABLELIGHT_H_H
#define DIMMABLELIGHT_H_H
#include"Light_H.h"

class dimmablelight : public Light
{
private:
    double dimfactor{};
public:
    dimmablelight();
    dimmablelight(string name,double power_consumption,double brightness):Light(name,power_consumption,brightness){}
    void increase(double amount);
    void decrease(double amount);
    void max();
    void min();
    double getdimfactor();

};

#endif // DIMMABLELIGHT_H_H
