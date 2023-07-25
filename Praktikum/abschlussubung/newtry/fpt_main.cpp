#include "fpt.h"
#include "fpr.cpp"
#include <iostream>
using std::string;
using namespace std;

void add_Liwanze(vector<Liwanze> &vL)
{
    while (true)
    {
        string newname{};
        int newRegion{};

        cout << "Enter name: ";
        getline(cin, newname);
        if (newname == "Q")
        {
            break;
        }

        // Name checker loop which checks the vector for pre-existing names
        bool found = false;
        for (const auto &liwanze : vL)
        {
            if (liwanze.get_name() == newname)
            {
                cout << "Found user with the same name." << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            vL.emplace_back(Liwanze(newname, Liwanze::Region::ndef));
            break;
        }
    }
}

int main()try
{
    vector<Liwanze> vL{
        Liwanze("Joey", Liwanze::Region::amer),
        Liwanze("Johnny", Liwanze::Region::amer),
        Liwanze("DeeDee", Liwanze::Region::amer),
        Liwanze("Tommy", Liwanze::Region::emea),
        Liwanze("Suzy", Liwanze::Region::apac),
        Liwanze("Sheena", Liwanze::Region::amer)};

    

    return 0;
}
catch( ... ) 
{
    cerr << "Unbekannte Ausnahme" << endl;
    return -1;
}




// Code snippet to add region (Disfunctional)
/*
cout << "Region (0 = ndef, 1 = amer, 2 = emea, 3 = apac) ";
cin >> newRegion;
Liwanze::Region loc;
switch (newRegion)
{
case 0:
    loc = Region::ndef;
    break;
case 1:
    loc = Region::amer;
    break;
case 2:
    loc = Region::apac;
    break;
case 3:
    loc = Region::emea;
    break;
default:
    loc = Region::ndef;
    break;
}
*/