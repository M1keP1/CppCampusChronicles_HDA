#include "callcenter.h"

Callcenter::Callcenter() {}

void Callcenter::dialog()
{
    char eingabe;
    string p,d,vaccine,praxis;
    Impfstoff v1;
    while (true) {
        cout<<"1: Termin anlegen"<<endl;
        cout<<"2: Termin loeschen"<<endl;
        cout<<"3: Arztpraxis anlegen"<<endl;
        cout<<"4: Terminuebersicht"<<endl;
        cout<<"0: Programm beenden"<<endl;


        cin>>eingabe;


        switch (eingabe) {
        case '1':{
            cout<<"Enter name of Patient";
            cin>>p;
            cout<<"Arztpraxis?"<<endl;
            cin>>praxis;
            for (auto&x:praxises) {
                if(x.getName()==praxis){
                    cout<<"Enter date of appointment";
                    cin>>d;
                    cout<<"Impfstoff (1: Biontech, 2: Moderna, 3: Astra Zeneca, 4: Johnson&Johnson)?"<<endl;
                    cin>>vaccine;
                    v1=strtoenum(vaccine);
                    x.terminAnlegen(p,d,v1);
                    break;
                }
                else {
                    cout<<"Praxis dosen't exits"<<endl;
                }

            }
                break;
        }

        case '2':{
            cout<<"Enter name of Patient";
            cin>>p;
            cout<<"Enter name of praxis"<<endl;
            cin>>praxis;
            for (auto&x:praxises) {
                if(x.getName()==praxis){
                    x.terminLoeschen(p);
                    break;
                }
                cout<<"Praxis not found"<<endl;
            }

           /*artztpraxis.terminLoeschen(p);*/
             break;
        }
        case '3':{
            cout<<"Enter the name of the praxis"<<endl;
            cin>>praxis;
            Artztpraxis a1{praxis};
            praxises.push_back(a1);
            break;
        }
        case '4':{
            for(auto&x:praxises){
                x.anzeigen();
            }
            break;
        }

        case '0':{
            return;
        }
        break;
        default:{

            cout<<"Enter a valid input"<<endl;
        }
        break;


        }
    }
}

Impfstoff Callcenter::strtoenum(string vaccine)
{
    if(vaccine=="Biontech"){
        return Impfstoff::Biontech;
    }
    else if (vaccine=="Moderna") {
        return Impfstoff::Moderna;
    }
    else if (vaccine=="AstraZeneca") {
        return Impfstoff::Moderna;
    }
    else {
        return Impfstoff::JohnsonJohnson;
    }
}
