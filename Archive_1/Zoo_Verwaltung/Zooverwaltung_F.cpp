#include"Zooverwaltung_H.h"

int Id{0};

bool Zooverwaltung::aufnehmen_nachID(int id,Herde& hn)
{
    for(auto& g1:gehegen)
    {
        if(g1.get_ID()==id && (hn.get_anzahl_t()+g1.get_actual_capacity())<=g1.get_max_capacity())
        {
            g1.get_herd().push_back(hn);
            cout<<"----Herd object added to "<<id<<" ----"<<endl;

            return true;
        }
    }
    return false;
}
//Could have also used aufnehmen in the function above with conditional statements but didnt for asthetic reasons

void Zooverwaltung::zooErweitern(int Platz,bool raubtier)
{
    cout<<"----ZooErweitern function called----"<<endl;
    Gehege* n=new Gehege(Id++,Platz,raubtier);
    //gehegen.push_back(Gehege(Id++,Platz,raubtier));
}

bool Zooverwaltung::aufnehmen(Herde& herde)
{

    for (auto& x : gehegen) {
        for(auto&z:x.get_herd()){
            if (z.get_Bezeichnung() == herde.get_Bezeichnung() && z.get_anzahl_t()+herde.get_anzahl_t()<=z.get_platzbedarf() && z.get_anzahl_t()+x.get_actual_capacity()<=x.get_max_capacity()) {  //checks for possible platzbedarf and max capacity conflicts
                herde.increase_anzahl();
                cout<<"----Same animal detected inside "<<x.get_ID()<<",anzahl increased----"<<endl;
                return true;
            } else if(z.get_anzahl_t()+x.get_actual_capacity()<=x.get_max_capacity()) {
                x.get_herd().push_back(herde);
                cout<<"----No identicals detected,new herd formed----"<<endl;
                return true;
            }
            else
            {
                cout<<"----Herd not accepted,possibly because of platz insufficiency----"<<endl;
                return false;
            }
        }
    }
    return false;

}

int Zooverwaltung::get_gesamt_actual_capacity(){    //loops through gehegen and return actual gesamt capacity
    int t{0};
    for (auto& x: gehegen){
        t+=x.get_actual_capacity();
    }
    return t;
}

int Zooverwaltung::get_gesamt_max_capacity(){       //loops through gehegen and return actual max capacity
    int l{0};
    for (auto& x: gehegen){
        l+=x.get_max_capacity();
    }
    return l;
}
int Zooverwaltung:: get_gesamt_platzbedarf(){       //loops through gehegen and herds and returns total platz bedarf
    int k{0};
    for(auto& g3:gehegen)
    {

        for(auto& h3: g3.get_herd())
        {
            k+=h3.get_platzbedarf();
        }

    }
    return k;
}

void Zooverwaltung::inventur()
{
    cout<<"----Inventur Function called----"<<endl;
    cout<<"Size of gehege: "<<gehegen.size()<<endl;
    cout<<"Total Platzbedarf: "<<get_gesamt_platzbedarf()<<endl;
    cout<<"Total Remaining Capacity: "<<get_gesamt_max_capacity()-get_gesamt_actual_capacity()<<endl;
    for(auto& g3:gehegen)
    {
        cout<<"Gehege ID: "<<g3.get_ID()<<endl;
        cout<<"Actual Capacity: "<<g3.get_actual_capacity()<<endl;
        for(auto& h3: g3.get_herd())
        {
            cout<<"----"<<endl;
            cout<<"Herds inside :: "<<endl;

            cout<<"Name of herd: "<<h3.get_Bezeichnung()<<endl;
            cout<<"animals inside: "<<h3.get_anzahl_t()<<endl;

        }

    }
}
vector<Gehege> Zooverwaltung::get_gehege()
{
    return gehegen;
}


