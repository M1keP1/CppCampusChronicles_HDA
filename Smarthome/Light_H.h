#ifndef LIGHT_H_H
#define LIGHT_H_H
#include"Device_H.h"

class Light : public Device
{
private:
    double power_consumption{};
    double brightness{};
    bool state{};
public:
    Light();
    Light(string name,double power_consumption,double brightness):Device(name),power_consumption(power_consumption),brightness(brightness){}
    void on();
    void off();
    void toggle();
    bool getState();
    double get_power_consumption();
    void set_brightnes(double new_brightness);
    double get_brightness();

};

#endif // LIGHT_H_H
