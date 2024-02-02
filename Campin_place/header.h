#ifndef HEADER_H
#include <iostream>
using namespace std;



class Booking
{

private:
    int from{};
    int to{};
    vector<string>visitors;
    double cost{};
    bool payed{};


public:
    Booking(int from,int to,vector<string>visitors,double costPerNight);
    Booking() : from(0), to(0), cost(0), payed(false) {}
    void setPayed();
    int get_from();
    int get_to();


};

class Plot:public Booking
{
public:
    Plot(int id,double size,double costPerNight);
    Plot():id(0),size(0.0),costPerNight(0.0){}
    bool bookingPossible(int from,int to,int visitors);
    void book(const Booking& b);



private:
    int id{};
    double size{};
    double costPerNight{};
    vector<Booking> bookings;


};

class Camping: public Plot
{
public:
    Camping(string name);
    Camping(): name(){}
    void addPlot();
    void addPLot(Plot* plot);
    bool bookPLot(int id,vector<string>guests,int from,int to);
    bool bookPlot(vector<string>guests,int from,int to);
    void display();
    void display(int from,int to);
    void createReminders(int today);

private:
    vector<Plot*>plots;
    string name{};



};

#endif // HEADER_H
