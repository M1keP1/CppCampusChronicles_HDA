//
// Created by APPLE on 06.06.23.
//

#include "Name_values.h"
void Name_values::print_all() const {
cout << "Werte für " << abbreviation << " (" << name << "): ";
for (int value : values)
{
cout << value << " ";
}
cout << endl;
}