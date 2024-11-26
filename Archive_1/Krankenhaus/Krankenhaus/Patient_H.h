//Created by Mihir on 28.02.2024
#ifndef PATIENT_H_H
#define PATIENT_H_H
#include<iostream>
#include<vector>
using namespace std;

enum class diagnose{
    simulant=2,
    infektion=14,
    fraktur=72,
    geheilt=0
};
class Patient{

private:
    string vorname{};
    string nachname{};
    string geschlecht{};
    string geburt{};
    int dauer{};

    diagnose diagnosetyp;
    static int last_id;
    int id{};



public:
    Patient();
    Patient(string vorname,string nachname,diagnose simulant):vorname(vorname),nachname(nachname),diagnosetyp(simulant){
        last_id++;
        id=last_id;
    }

    void display();
    string get_vorname();
    string get_nachname();
    string get_geschlecht();
    void set_diagnostyp(diagnose newdiagnose);
    void set_new_dauer(int newdauer);
    int get_dauer();
    int set_dauer(diagnose diagnosetyp);
    static int get_last_id()
    {
        return last_id;
    }
    int get_id()
    {
        return id;
    }
    string get_diagnosis_name();



};


class Krankenhaus
{
private:
    int bett{};
    vector<Patient> patients;
    int healed_patients();
    int krank_patients();


public:

    void addPatient(Patient pn);
    Patient get_patients();
    void time(vector<Patient>p0,int tagen_verpasst);
    void removePatient();
    int get_bett();
    void diagnos_updater();
    void get_healedpatient();
};

#endif // PATIENT_H_H
