#ifndef SILL_H #define SILL_H
#include <iostream>
using namespace std;
class sill
{
public:
    sill();
    ~sill();
    void push(int);
    int pop();
    void print();

private:
    struct sillnode
    {
        int item;
        sillnode *next;
        sillnode();
        sillnode(int, sillnode *);
    };
    sillnode *top;
};
#endif
