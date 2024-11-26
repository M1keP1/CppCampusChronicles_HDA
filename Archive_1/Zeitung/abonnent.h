#ifndef ABONNENT_H
#define ABONNENT_H
#include"zeitung.h"

class Abonnent
{
private:
    string name;
    Zeitung* meineZeitung;
public:
    Abonnent(string name);
    void abonniere(Zeitung& Zeitung);
    string getName() const;
};

#endif // ABONNENT_H
