#ifndef CAMPING_HEADER_H
#define CAMPING_HEADER_H
#include "Plot_header.h"

class Camping: public Plot
{
public:
    Camping(string name);
    Camping(): name(){}
    ~Camping();
    void addPlot();
    void addPlot(Plot* plot);
    bool bookPlot(int id,vector<string>guests,int from,int to);
    bool bookPlot(vector<string>guests,int from,int to);
    void display();
    void display(int from,int to);
    void createReminders(int today);
    int get_id();
    int PlotId{1};

private:
    vector<Plot*>plots;
    string name;
    int id;

};

#endif // CAMPING_HEADER_H
