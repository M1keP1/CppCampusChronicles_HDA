//a
/*
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

map<string, string> weekdayMap
{

        {"Mo", "Montag"},
        {"Di", "Dienstag"},
        {"Mi", "Mittwoch"},
        {"Do", "Donnerstag"},
        {"Fr", "Freitag"},
        {"Sa", "Samstag"},
        {"So", "Sonntag"}

};

bool isValidWeekday(const string& weekday)
{
    for(const auto&pair : weekdayMap)
    {
        const string& shortName = pair.first;
        const string& longName = pair.second;

        if(weekday == longName || weekday == shortName)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    map<string, vector<int>> weekdaysData;
    int rejectedCount {0};

    try {
        while(true)
        {
            string weekday;
            int value;

            cout << "Wochentag-Wert-Paare eingeben (z.B. Montag -2): ";
            cin >> weekday;

            //zum beenden des Programms
            if (weekday =="q" || weekday == "Q")
            {
                break;
            }

            //Gültigkeit des Wochentags überprüfen
            if(!isValidWeekday(weekday))
            {
                cerr << "Fehler: Ungültiger Wochentag. Wert wird ignoriert." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignoriert restliche zeile
                rejectedCount++;  //zählt rejectedCount
                continue;
            }

        cin >> value;

            //Speichern des Werts in Container
            string shortWeekday;
            for (const auto& pair : weekdayMap)
            {
                const string& weekdayKey {pair.first};
                if (weekday == weekdayKey || weekday == weekdayMap.at(weekdayKey))
                {
                    shortWeekday = weekdayKey;
                    break;

                }
            }

        weekdaysData[shortWeekday].push_back(value);
        }

        //Ausgabe der Werteliste und die Durschnittswerte
        for (const auto& pair : weekdaysData)
        {
            const string& shortWeekday {pair.first};
            const vector<int>& values {pair.second};

            cout << "Werte für " << shortWeekday << "/" << weekdayMap.at(shortWeekday) << ": ";
            for (int value : values)
            {
                cout << value << " ";
            }

            //Berechnen und ausgeben des Durschnittswertes
            if (!values.empty())
            {
                double sum {0};
                for (int value : values)
                {
                    sum += value;
                }

                double average { sum / values.size()};
                cout << "\nDurschnittswert: " << average;

            }
            cout << endl;
        }

    //ausgabe anzahl abgelehnter Werte
    cout << "Anzahl der abgelehnten Werte: " << rejectedCount << endl;


    }
    catch (const exception& e)
    {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;

}
 */

//b

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

