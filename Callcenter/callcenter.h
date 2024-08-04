#ifndef CALLCENTER_H
#define CALLCENTER_H
#include"artztpraxis.h"

class Callcenter
{
private:
    Artztpraxis artztpraxis;
    vector<Artztpraxis> praxises;
public:
    Callcenter();
    void dialog();
    Impfstoff strtoenum(string vaccine);
};

#endif // CALLCENTER_H
