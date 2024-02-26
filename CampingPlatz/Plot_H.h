#ifndef PLOT_H_H
#define PLOT_H_H
#include"Booking_H.h"

enum class feature{
    power,water,riverside
};

class Plot
{
private:
    int id{};
    double size{};
    double costpernight{};
    int anzahl_buchung{};
    vector<Booking> bookings;
    vector<feature>features;
public:
    Plot();
    Plot(int id,double size,double costpernight,vector<feature>features):id(id),size(size),costpernight(costpernight),features(features){}
    bool bookingPossible(int from,int to,int visitors,vector<feature>fer);
    void book(Booking b);
    int get_id();
    double  get_size();
    int get_anzahl_buchung();
    void increase_anazhl_buchungen();
    vector<feature> get_features();
};

#endif // PLOT_H_H
