//Created by Mihir on 27.02.2024
#include <iostream>
#include <vector>
#include "Mensa_F.cpp"

using namespace std;
vector<Meal>namens;

void populate()
{

    Meal one("Wisswurst_mit_Wurzel",4.20,false);
    Meal two("Gebratener_Gemusereis",3.80,true);
    Meal three("Pizza_vier_kase",4.00,false);
    namens.push_back(one);
    namens.push_back(two);
    namens.push_back(three);
}
void add_Meal()
{

    string gerichtname{};
    double gerichtprice{};
    bool vegan{};
    cout<<"Enter Gericht name: "<<endl;
    cin>>gerichtname;
    cout<<"Enter price"<<endl;
    cin>>gerichtprice;
    cout<<"If it is vegan enter 'true' otherwise 'false'"<<endl;
    cin>>vegan;
    Meal newmeal(gerichtname,gerichtprice,vegan);
    namens.push_back(newmeal);
}


int main()
{
    int c{};

    cout << "Your bluetooth device has been connected" << endl;
    bool flag{true};
    vector<Meal>namens;
    populate();
    cout<<"Vector formed and populated"<<endl;
    while(flag==true)
    {
        char choice{};
        cout<<"A:Gericht anzeigen"<<endl;
        cout<<"B:Gericht eingeben"<<endl;
        cout<<"Q:Program ende"<<endl;
        cin>>choice;
        if(choice=='A' || choice=='a'){c=0;}
        else if(choice=='B' || choice=='b'){c=1;}
        else if(choice=='Q' || choice=='q'){c=2;}
        else{c=3;}
    switch(c)
    {
    case 0:
        for(auto& m1:namens)
        {
            m1.printgericht();
        }
        break;
    case 1:
        add_Meal();
        break;
    case 2:
        flag=false;
        break;
    default:
        cout<<"Invalid response"<<endl;
        break;

    }
    }
    return 0;
}
