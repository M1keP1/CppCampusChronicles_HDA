//Created by Mihir on 27.02.2024
#include"Patient_H.h"

string Patient::get_vorname()
{
    return vorname;
}
string Patient::get_nachname()
{
    return nachname;
}
string Patient::get_geschlecht()
{
    return geschlecht;
}
int Patient::set_dauer(diagnose diagnosetyp)
{
    switch (diagnosetyp) {
    case diagnose::simulant:
        dauer = static_cast<int>(diagnose::simulant);
        break;
    case diagnose::infektion:
        dauer = static_cast<int>(diagnose::infektion);
        break;
    case diagnose::fraktur:
        dauer = static_cast<int>(diagnose::fraktur);
        break;
    case diagnose::geheilt:
        dauer = static_cast<int>(diagnose::geheilt);
        break;
    default:
        std::cout << "Unknown diagnosis." << std::endl;
        break;
    }

    return dauer;
}
int Patient::get_dauer()
{
    return dauer;
}
void Patient::set_new_dauer(int newdauer)
{
    dauer=newdauer;
}

void Patient::set_diagnostyp(diagnose newdiagnose)
{
    diagnosetyp=newdiagnose;
}

string Patient::get_diagnosis_name()
{
    switch (diagnosetyp) {
    case diagnose::simulant:
        return "Simulant";
    case diagnose::infektion:
        return "Infektion";
    case diagnose::fraktur:
        return "Fraktur";
    case diagnose::geheilt:
        return "Geheilt";
    default:
        return "Unknown diagnosis";
    }
}


void Patient::display()
{
    cout<<get_vorname();
    cout<<get_nachname();
    cout<<get_geschlecht();
    cout<<get_diagnosis_name();

}
int Patient:: last_id=100000;

int Krankenhaus:: get_bett()
{
    return bett;
}

void Krankenhaus:: addPatient(Patient pn)
{
    if(get_bett()!=0)
    {
        patients.push_back(pn);
    }

}

void Krankenhaus::removePatient()
{
    int pos{};
    for(auto& p2:patients)
    {

        if(p2.get_dauer()==0)
        {
            patients.erase(patients.begin()+pos);
        }
        pos++;
    }
}
void Krankenhaus:: time(vector<Patient> p0,int tagen_verpasst)
{
    for(auto& p1:p0)
    {
        if(p1.get_dauer()-tagen_verpasst<=0)
        {
            p1.set_diagnostyp(diagnose::geheilt);

        }
    }

}
void

