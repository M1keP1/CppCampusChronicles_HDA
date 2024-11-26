#ifndef AUTOVERMEITUNG_H
#define AUTOVERMEITUNG_H

#include "mietwagen.h"



class autovermeitung
{
public:

    autovermeitung();
    ~autovermeitung()
    {
        for(auto x:fahrzeuge)
        {
            delete x;


        }
        fahrzeuge.clear();
        cout<<"Hasta la vista!"<<endl;
    }


    void dialog();

    vector<mietwagen *> getFahrzeuge() const;
    bool mietwagenSuchen(int i);

private:
    vector<mietwagen*> fahrzeuge;



};

#endif // AUTOVERMEITUNG_H
