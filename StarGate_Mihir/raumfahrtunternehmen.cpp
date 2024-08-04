#include "raumfahrtunternehmen.h"

raumfahrtunternehmen::raumfahrtunternehmen()
{

}

raumfahrtunternehmen::~raumfahrtunternehmen()
{
    for(auto& x:gleiterListe)
    {
        delete x;
    }
    gleiterListe.clear();
    cout<<"Ich bin groot!!"<<endl;
}

void raumfahrtunternehmen::dialog()
{
    unsigned int gleiterIndex = 0;
    raumgleiter *pRaumgleiter = new raumgleiter;
    gleiterListe.push_back(pRaumgleiter);
    while(true)
    {
        int choice{};
        cout<<"1: Raumflug hinzufuegen"<<endl;
        cout<<"2: Passagier buchen"<<endl;
        cout<<"3: Raumflug anzeigen"<<endl;
        cout<<"4: Alle Fluge anzeigen"<<endl;
        cout<<"5: Fracht buchen"<<endl;
        cout<<"6: Raumgleiter Hinzufuegen"<<endl;
        cout<<"0: Program beenden"<<endl;

        cin>>choice;
        switch(choice)
        {
        case 1:{

            string d{};
            double da;
            string z{};

            cout<<"Abflug (TT.MM.YYYY:hhmm)?: ";
            cin>>d;
            cout<<"Reiseziel? :";
            cin>>z;
            cout<<"reisedauer in Tagen : ";
            cin>>da;
            raumflug *r1=new raumflug(0,d,z,da);
            pRaumgleiter->flugHinzufuegen(r1);
            cout<<"Raumflug "<<r1->getFlugnummer()<<" erfolgreich angelegt"<<endl;
        }
        break;
        case 2:{
            int fn;
            cout<<"Flugnummer? : ";
            cin>>fn;
            pRaumgleiter->passagierBuchen(fn);

        }
        break;
        case 3:{
            int fn{};
            cout<<"Flugnummer? : ";
            cin>>fn;
            pRaumgleiter->flugAnzeigen(fn);
        }
        break;
        case 4:{
            pRaumgleiter->alleFluegeanzeigen();
        }
        break;
        case 5:{
            int fn;
            cout<<"Flugnummer? : ";
            cin>>fn;
            pRaumgleiter->frachtBuchen(fn);
        }
        break;
        case 6:{
            gleiterIndex=gleiterListe.size();
            raumgleiter *r2=new raumgleiter;
            gleiterListe.push_back(r2);
            cout<<"Raumgleiter added"<<endl;


        }
        break;
        case 0:{
            return;

        }

        default:
        {
            cout<<"Enter valid input"<<endl;
        }
        break;
        }
    }
}

int raumfahrtunternehmen::berechnerDauer()
{
    return 0;
}
