#include"Light_H.h"

void Light::on()
{
    state=1;
}
void Light::off()
{
    state=0;
}
void Light::toggle()
{
    if(state==1)
    {
        off();
    }
    else
        on();
}
bool Light::getState()
{
    return state;
}

void Light::set_brightness(double new_brightness)
{
    brightness=new_brightness;
}
double Light::get_brightness()
{
    return brightness;
}
double Light::get_power_consumption()
{
    return power_consumption;
}
