#ifndef CAMPING_H_H
#define CAMPING_H_H
#include"Plot_F.cpp"



class Camping
{
private:
    vector<Plot*> plots;
    string name{};
    int plot_id{};
public:
    Camping();
    Camping(string name):name(name){}
    void addPlot();
    void addPlot(Plot *plot);
    bool bookplot(int id,vector<string> guests,int from,int to);
    void display();
    void display_free();
    int get_plot_id();
    bool bookfreeplot(vector<string> guests,int from,int to);
    void createReminders(int tag);
};


#endif // CAMPING_H_H
