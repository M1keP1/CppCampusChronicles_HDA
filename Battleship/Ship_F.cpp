#include"Ship_H.h"

Status Schiff::get_status()
{
    int blocks_damaged{0};

    //this function iterates through the vector containg the ship blocks and returns status accordinglt based on ship blocks condition
    for(auto& l1:laenge)
    {
        if(l1.get_status()==Status::getroffen)
        {
            blocks_damaged++;
        }

    }
    if(blocks_damaged==laenge.size())
    {
        return Status::versenkt;
    }
    else if(blocks_damaged==0)
    {
        return Status::unbeschadigt;
    }
    else
    {
        return Status::getroffen;
    }

}
int Schiff::get_ship_length()
{
    return ship_length;
}

bool Schiff::belegt(int reihe,int spalte)
{
    for(auto& l2: laenge)
    {
        if(l2.get_reihe()==reihe && l2.get_spalte()==spalte)
        {
            return true;

        }
    }
    return false;
}
bool Schiff::beschuss(int reihe,int spalte)
{
    for(auto& l3: laenge)
    {
        if(l3.get_reihe()==reihe && l3.get_spalte()==spalte)
        {
            cout<<"Schiffsteil gefunden"<<endl;
            cout<<"Attacked!!!"<<endl;
            l3.set_status(Status::getroffen);
            if(get_status()==Status::versenkt)
            {
                return true;
            }


        }
    }
    return false;
}
void  Schiff::zeichne(vector<vector<char>> & leinwand) {

        for (int i = 0; i < get_ship_length(); ++i)
            {
                leinwand[ship_reihe+i][ship_spalte + i] = '#';
            }


}









