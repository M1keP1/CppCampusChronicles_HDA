#include <iostream>
#include "car.h"
#include "car.cpp"
using namespace std;
int main()
{
    sportscar c1{"Porsche 911", 390};
    sportscar c2{};
    Luxurycar c3{"Bentley Continental", true};
    sportscar c4{"Lamborghini Huracan Biturbo", 640};
    Stretchlimo c5{"Mercedes E500 Umbau", true, 6};
    Stretchlimo c6{"Ford Lincoln Town", true, 8};
    suv s6{"creta", 70, true, 80};
    Van{"omni", 5, 30};

    for (car *pc{car::sget_last()}; pc != nullptr; pc = pc->get_next()) // Listenanfang ohne Objekt braucht die static Methode
    {
        pc->print();
        cout << endl;
    }
    cout << endl;
    return 0;
}
