#ifndef BED_H_H
#define BED_H_H
#include"Furniture_H.h"

enum class sz{
    single,doble,queen,king,superking
};

class Bed :public Furniture
{
private:
    sz size;
public:
    Bed();
    Bed(string name,sz size):Furniture(name),size(size){}
    void print();

};


#endif // BED_H_H
