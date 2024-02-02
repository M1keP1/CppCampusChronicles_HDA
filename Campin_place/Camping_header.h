#ifndef CAMPING_HEADER_H
#define CAMPING_HEADER_H
#include "Plot_header.h"

class Camping: public Plot
{
public:
    Camping(string name);
    Camping(): name(){}
    void addPlot();
    void addPlot(Plot* plot);
    bool bookPlot(int id,vector<string>guests,int from,int to);
    bool bookPlot(vector<string>guests,int from,int to);
    void display();
    void display(int from,int to);
    void createReminders(int today);

private:
    vector<Plot*>plots;
    string name;

};

#endif // CAMPING_HEADER_H
