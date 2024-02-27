#include"dimmablelight_H.h"

void dimmablelight::increase(double amount)
{
    Light::set_brightnes(get_brightness()+amount);
}
void dimmablelight::decrease(double amount)
{
     Light::set_brightnes(get_brightness()-amount);
}
void dimmablelight::max()
{
     set_brightnes(1.0);
}
void dimmablelight::min()
{
     set_brightnes(0.0);
}
