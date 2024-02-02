#ifndef PLOT_HEADER_H
#define PLOT_HEADER_H
#include "Booking_header.h"

class Plot:public Booking
{
public:
    Plot(int id,double size,double costPerNight);
    Plot():id(0),size(0.0),costPerNight(0.0){}
    bool bookingPossible(int from,int to,int visitors);
    void book(const Booking& b);

    int get_id();
    void set_id(int id);

    double get_size();
    void set_size(double size);

    double get_costPerNight();
    void set_costPerNight(double costPerNight);




private:
    int id{};
    double size{};
    double costPerNight{};
    vector<Booking> bookings;


};

#endif // PLOT_HEADER_H
