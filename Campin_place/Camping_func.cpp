#include "Camping_header.h"

Camping::Camping(string name):name(name)
{

}

Camping::~Camping()
{
    for(auto plot: plots)
    {
        delete plot;
    }
    plots.clear();
}

int Camping::get_id()
{
    return id;
}

void Camping::addPlot()
{
    string plot_name{};
    double plot_size{};
    double cstPerNight{};

    cout<<"----->> Add Plot Function started"<<endl;
    cout<<">>Please Enter a name for your Plot"<<endl;
    cin >> plot_name;
    cout<<">>Please Enter size of your Plot"<<endl;
    cin>>plot_size;

    cout<<">>Please enter cost per night"<<endl;
    cin>>cstPerNight;


    cout<<">>Please Enter a 4 digit unique id for your booking "<<endl;         // modify segment to check for uniqe id
    cin>>id;

    Plot* plot = new Plot(PlotId++,plot_size,cstPerNight);




}


void Camping::addPlot(Plot* plot)
{
    plots.push_back(plot);
}

void Camping::display(int from,int to)
{
    cout<< " Your booking id : " << get_id()  << endl;
    cout<< "Size of your place : "<< get_size() <<endl;
    cout<< "Bookings : " <<  endl;
    get_bookings();
}



