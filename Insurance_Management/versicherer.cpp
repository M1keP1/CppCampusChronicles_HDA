#include "versicherer.h"
#include "lvschein.h"
#include "kfzschein.h"

Versicherer::Versicherer()
{

}

void Versicherer::dialog()
{
    while(true)
    {

        cout<<"1: Versicherung anlegen"<<endl;
        cout<<"2: Versicherungsdetails ausgeben"<<endl;
        cout<<"0: Programm beenden"<<endl;
        int choice{};
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            int vsn{};
            string vname{};
            string nname{};
            cout<<"Versicherungsscheinnummer?"<<endl;
            cin>>vsn;
            cout<<"Vorname?"<<endl;
            cin>>vname;
            cout<<"Nachname?"<<endl;
            cin>>nname;
            char choice2{};
            cout<<"Enter K for kfz versicherung and L fot lebensversicherung"<<endl;
            cin>>choice2;
            switch(choice2)
            {
            case 'K':
            {
                KFZSchein* kfz1 = new KFZSchein(vsn,vname,nname);
                versicherungen.push_back(kfz1);
                cout<<"Success: ADDED KFZ"<<endl;
                break;
            };
            case 'L':
            {
                LVSchein* lv1 = new LVSchein(vsn,vname,nname);
                versicherungen.push_back(lv1);
                cout<<"Success: ADDED LV"<<endl;
                break;
            };
            default:
            {
                cout<<"Enter Correct input"<<endl;
                continue;
            };
            }



            break;
        }
        case 2:
        {
            bool found{false};
            int vsn{};
            cout<<"Enter VSNummer"<<endl;
            cin>>vsn;
            for(auto &x:versicherungen)
            {
                if(x->getScheinNr()==vsn)
                {
                    x->anzeigen();
                    found = true;
                }
            }
            if(found==false)
            {
                cout<<"Not found !!"<<endl;
            }
            break;
        };
        case 0:
        {
            break;
        };
        default:
        {
            continue;
        };
        }
    }
}
