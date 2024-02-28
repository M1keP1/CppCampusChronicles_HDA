#ifndef TABLE_H_H
#define TABLE_H_H

#include "Furniture_H.h"

class Table : public Furniture
{
private:
    int length{};
    int width{};
    int height{};
public:
    Table();
    Table(string name, int length, int width, int height) : Furniture(name) {
        if (length < 0) {
            cout << "Length cannot be negative" << endl;
        }
        else if (length > 0) {
            this->length = length;
        }
        if (width < 0) {
            cout << "Width cannot be negative" << endl;
        }
        else if(width>=length) {
            cout<<"Width cannot be more than lenght"<<endl;
        }
        if (width > 0 && width <= length) {
            this->width = width;
        }

        if (height < 0) {
            cout << "Length cannot be negative" << endl;
        }
        if (height > 0) {
            this->height = height;
        }
        else {
            this->height = 80;
        }
    }


    void print();
};

#endif // TABLE_H_H
