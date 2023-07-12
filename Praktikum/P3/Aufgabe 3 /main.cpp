//a


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Name_values.h"

using namespace std;



int main() try
{
    vector<Name_values> week{
            Name_values("Montag", "Mo"),
            Name_values("Dienstag", "Di"),
            Name_values("Mittwoch", "Mi"),
            Name_values("Donnerstag", "Do"),
            Name_values("Freitag", "Fr"),
            Name_values("Samstag", "Sa"),
            Name_values("Sonntag", "So")
    };

    string weekday;
    int value;
    int rejectedCount = 0;

    cout << "Wochentag-Wert Paare eingeben (z.B. Montag 23). Eingabe beenden mit 'q':" << endl;

    while (true)
    {
        cin >> weekday;

        // Beenden, wenn 'q' eingegeben wurde
        if (weekday == "q" || weekday == "Q")
        {
            break;
        }

        // Eingabe des Werts
        cin >> value;

        bool found = false;

        for (Name_values& nv : week)
        {
            if (nv.get_name() == weekday || nv.get_abbreviation() == weekday)
            {
                nv.add_value(value);
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Ungültiger Wochentag: " << weekday << endl;
            rejectedCount++;
        }
    }

    cout << "----------------------" << endl;

    // Ausgabe der Werte für jeden Wochentag und Durchschnittswert
    for (const Name_values& nv : week)
    {
        nv.print_all();
    }

    cout << "Anzahl der abgelehnten Wochentage: " << rejectedCount << endl;

    return 0;
}

catch( std::exception& e ) {
    cerr << "Ausnahme" << e.what() << endl;
    return -2;
}


catch( ... ) {
    cerr << "Unbekannte Ausnahme" << endl;
    return -1;
}

