//
// Created by APPLE on 06.06.23.
//

#ifndef AUFGABE_3__NAME_VALUES_H
#define AUFGABE_3__NAME_VALUES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Name_values
{
public:
    Name_values() = default;
    Name_values(const string& name, const string& abbreviation)
            : name(name), abbreviation(abbreviation)
    {
    }

    void add_value(int value)
    {
        values.push_back(value);
    }

    void print_all() const;

    string get_name() const
    {
        return name;
    }

    string get_abbreviation() const
    {
        return abbreviation;
    }

private:
    string name;
    string abbreviation;
    vector<int> values;
};


#endif //AUFGABE_3__NAME_VALUES_H
