#ifndef ZEITUNGSVERLAG_H
#define ZEITUNGSVERLAG_H
#include"abonnent.h"

class Zeitungsverlag
{
private:
    vector<Abonnent*>subscriptions;
    vector<Zeitung*> papers;
public:
    Zeitungsverlag();
    void dialog();
    Zeitung *givezeitung(string name);
    Abonnent *giveaboonent(string name);
};

#endif // ZEITUNGSVERLAG_H
