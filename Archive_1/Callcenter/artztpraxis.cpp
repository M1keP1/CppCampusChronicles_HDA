#include "artztpraxis.h"

string Artztpraxis::getName() const
{
    return name;
}

Artztpraxis::Artztpraxis() {}

Artztpraxis::Artztpraxis(string name):
    name(name)
{
    cout<<"Arztpraxis"<<name<<"angelegt"<<endl;
}

void Artztpraxis::terminAnlegen(string patient, string datumUhrzeit,Impfstoff vaccine )
{
    if(vaccine==Impfstoff::Biontech||vaccine==Impfstoff::Moderna||vaccine==Impfstoff::AstraZeneca){
        string termin_2;
        cout<<"Enter termin 2"<<endl;
        cin>>termin_2;
        Termin t1{patient,datumUhrzeit,vaccine,termin_2};
        cout<<"Termin with name"<<patient<<"is created"<<endl;
        return;
    }
    for (auto&x:terminliste) {
        if(x.getDatumUhrzeit()==datumUhrzeit){
            cout<<"Termin with this same time already exits. Enter new time "<<endl;
            cin>>datumUhrzeit;
            Termin t1{patient,datumUhrzeit,vaccine};
            terminliste.push_back(t1);
            return;
        }
    }

    Termin t1{patient,datumUhrzeit,vaccine};
    terminliste.push_back(t1);
}

void Artztpraxis::terminLoeschen(string patient)
{
    for (unsigned int i = 0; i < terminliste.size(); i++){
        if(terminliste[i].getPatient() == patient){
            terminliste.erase(terminliste.begin()+i);
            terminliste[i].setGeloescht(false);
            cout<< "Termin with name "<<patient<<"is delted"<<endl;
            return;
        }
    }
    cout<<"There is no termin with this name"<<endl;
}

void Artztpraxis::anzeigen()
{
    cout<<"Artztpraxis"<<name<<endl;
    for (auto&x:terminliste) {
        cout<<x.getPatient()<<" "<<x.getDatumUhrzeit()<<x.getvaccine();

       /* if(vaccine==Impfstoff::Biontech||vaccine==Impfstoff::Moderna||vaccine==Impfstoff::AstraZeneca){
            cout<<x.getPatient()<<" "<<x.getTermin_2()<<x.getvaccine();
            return;
        }*/
    }
    return;
}


