//Created by Mihir on 28.02.2024
#ifndef SHIP_H_H
#define SHIP_H_H
#include"Schiff_F.cpp"

class Schiff
{
private:
    vector<Schiffteil>laenge;
    int ship_reihe{};
    int ship_spalte{};
    int ship_length{};
    Direction ship_direction{};
public:
    Schiff();
    Schiff(int reihe,int spalte,int lange,Direction direction):ship_reihe(reihe),ship_spalte(spalte),ship_length(lange),ship_direction(direction){

        Schiffteil s1(reihe,spalte,Status::unbeschadigt);
        laenge.push_back(s1);    } //add a loop here that increases spalte on the basis of lange and sets it to unbeschadight
    Status get_status();
    bool belegt(int reihe,int spalte);
    bool beschuss(int reihe,int spalte);
    void zeichne(vector<vector<char>>& field);
    int get_ship_length();



};


#endif // SHIP_H_H
