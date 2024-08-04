#include "zeitungsverlag.h"

Zeitungsverlag::Zeitungsverlag() {}

void Zeitungsverlag::dialog()
{
    int eingabe;
    string paper,subs;
    while (true) {
        cout<<"1: Zeitung anlegen"<<endl;
        cout<<"2: Abonnent anlegen"<<endl;
        cout<<"3: Zeitungen anzeigen"<<endl;
        cout<<"4: Abonnenten anzeigen"<<endl;
        cout<<"5: Zeitung bei Abonnent hinzufuegen"<<endl;
        cout<<"0: Programm beenden"<<endl;
        cin>>eingabe;
        switch (eingabe) {
        case 1:{
            cout<<"Enter name of the paper";
            cin>>paper;
            Zeitung* z1=new Zeitung(paper);
            papers.push_back(z1);
        }
            break;
        case 2:{
            cout<<"Enter name of the subscription";
            cin>>subs;
            Abonnent* a1=new Abonnent(subs);
            subscriptions.push_back(a1);
        }
        break;
        case 3:{
            for (auto&x:papers) {
                cout<<x->getName()<<endl;
            }
        }
        break;
        case 4:{
            for (auto&x:subscriptions) {
                cout<<x->getName()<<endl;
            }
        }
        break;
        case 5:{
            cout<<"Name of paper?";
            cin>>paper;
            cout<<"Name of subscription?";
            cin>>subs;
            givezeitung(paper)->addAbonnent(giveaboonent(subs));
        }
        break;
        case 0:
            return;
        break;
        default:
            cout<<"Enter number between 0 and 5"<<endl;
            break;
        }
    }
}

Zeitung *Zeitungsverlag::givezeitung(string name)
{
    for (auto&x:papers) {
        if(x->getName()==name){
            return x;
        }
    }
    return nullptr;
}

Abonnent *Zeitungsverlag::giveaboonent(string name)
{
    for (auto&x:subscriptions) {
        if(x->getName()==name){
            return x;
        }
    }
    return nullptr;
}
