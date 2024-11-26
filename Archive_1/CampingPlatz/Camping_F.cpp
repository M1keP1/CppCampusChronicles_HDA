#include"Camping_H.h"


int global_id{0};

void Camping::addPlot()
{
    int i;
    double sz;
    double cpn;
    int s;
    vector<feature> fe;
    cout<<"Enter Id: "<<endl;
    cin>>i;
    cout<<"Enter Size: "<<endl;
    cin>>sz;
    cout<<"Enter cost per night: "<<endl;
    cin>>cpn;
    cout<<"Enter features:0-Power,1-Water,2-Riverside "<<endl;
    cin>>s;
    switch(s)       //also needs a loop here to take in multiple inputs
    {
    case 0:
        fe.push_back(feature::power);
    case 1:
        fe.push_back(feature::water);
    case 2:
        fe.push_back(feature::riverside);
    default:
        cout<<"No features added"<<endl;


    }


    Plot *p = new Plot(global_id++,sz,cpn,fe);


}

void Camping::addPlot(Plot *plot)
{
    plots.push_back(plot);
}

bool Camping::bookplot(int id, vector<string>guests,int from,int to)
{
    for(auto& p0:plots)
    {
        if(p0->get_id()==id && p0->bookingPossible(from,to,guests.size(),p0->get_features())==1)
        {
            p0->increase_anazhl_buchungen();
            //something here that books
            return true;
        }
    }
    return false;
}

int Camping::get_plot_id()
{
    return plot_id;
}

void Camping::display()
{
    for(auto& p2: plots)
    {
        cout<<"Plot id: "<<p2->get_id()<<endl;
        cout<<"Size : "<<p2->get_size()<<endl;
        cout<<"Anzahl der buchungen : "<<p2->get_anzahl_buchung()<<endl;
    }
}
void Camping::display_free()
{
    if(true)// add condition here to check if it is free
    {
        for(auto& p2: plots)
        {
            cout<<"Plot id: "<<p2->get_id()<<endl;
            cout<<"Size : "<<p2->get_size()<<endl;
            cout<<"Anzahl der buchungen : "<<p2->get_anzahl_buchung()<<endl;
        }
    }
}
bool Camping::bookfreeplot(vector<string>guests,int from,int to)
{
    for(auto& p0:plots)
    {
        if(true && p0->bookingPossible(from,to,guests.size(),p0->get_features())==1)
        { //add another condition here to check if its free
            p0->increase_anazhl_buchungen();
            //something here that books
            return true;
        }
    }
    return false;
}

void Camping::createReminders(int tag){



    //add loop here that loops through bookings to check if it is already payed or not and also the to<tag
        {
            cout<<"Plot id: "<<endl;
            cout<<"Size : "<<endl;
            cout<<"Anzahl der buchungen : "<<endl;
        }


}
