#include "kfzschein.h"



KFZSchein::KFZSchein(int sNummer, string vName, string nName):
    Vschein(sNummer,vName,nName)
{
    cout << "KFZ-Kennzeichen?"<<endl;
    cin.ignore(10,'\n');
    getline(cin, kfzKennzeichen);
    cout<< "Jahr ?"<<endl;
    cin >>vBegin;

}

void KFZSchein::anzeigen()
{
    Vschein::anzeigen();
    cout << "KFZ-Versicherung " << kfzKennzeichen << " seit " << vBegin << endl;
}

