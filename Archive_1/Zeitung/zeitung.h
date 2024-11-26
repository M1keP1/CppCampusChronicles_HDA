#ifndef ZEITUNG_H
#define ZEITUNG_H
#include<iostream>
#include<vector>

using namespace std;
class Abonnent;

class Zeitung
{
private:
    string name;
    vector<Abonnent*> abonnenten;
public:
    Zeitung(string name);
    void addAbonnent(Abonnent* abonnent);
    string getName() const;
};

#endif // ZEITUNG_H
