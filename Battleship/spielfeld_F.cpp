#include "spielfeld_H.h"

void Spielfeld::ausgeben()
{
    for (int x = 0; x < leinwand.size(); ++x) {
        for (int y = 0; y < leinwand[x].size(); ++y) {
            std::cout << leinwand[x][y] << " ";
        }
        std::cout << std::endl;
    }
}
void Spielfeld::spielen()
{
    int ships_sinked{0};
    bool gameover{false};
    while(gameover==false)
    {
        int xo{};
        int yo{};
        ausgeben();
        cout<<"Enter x ordinates"<<endl;
        cin>>xo;
        cout<<"Enter y ordinates"<<endl;
        cin>>yo;
        for(auto& d:ships)
        {
            if(d.belegt(xo,yo))
            {
                cout<<"Ship Found"<<endl;
                d.beschuss(xo,yo);
                leinwand[xo][yo]='%';
            }
            else
            {
                leinwand[xo][yo]='X';
            }
        }
        cout<<"Ship not found"<<endl;
        for(auto& s:ships)
        {
            if(s.get_status()==Status::versenkt)
            {
                ships_sinked++;
            }
        }
        if(ships_sinked==ships.size())
        {
            gameover=true;
        }
    }

}
