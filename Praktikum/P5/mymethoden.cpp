#include <iostream>
#include "myvector.h"
myvector::myvector() : sz{0}, elem{nullptr} {}
myvector::myvector(int s) : sz{s}, space{s}, elem{new double[s]} {}
myvector::myvector(const myvector &other) : sz{other.sz}, space{other.space}, elem{new double[other.sz]}
{
    for (int i{0}; i < other.sz; i++)
    {
        elem[i] = other.elem[i];
    }
}
myvector::~myvector()
{
    delete[] elem;
}
myvector &myvector::operator=(const myvector &other)
{
    if (this == &other)
        return *this;
    if (other.sz <= space)
    {
        for (int i{}; i < other.sz; i++)
        {
            elem[i] = other.elem[i];
            sz = other.sz;
            return *this;
        }
    }
    double *p{new double[other.sz]};
    for (int i{}; i < other.sz; i++)
    {
        p[i] = other.elem[i];
    }
    delete[] elem;
    elem = p;
    sz = other.sz;
    return *this;
}
double myvector::get(int n) const
{
    return elem[n];
}
void myvector::set(int n, double v)
{
    elem[n] = v;
}
void myvector::reserve(const int newspace)
{
    if (newspace <= space)
        return;
    double *p{new double[newspace]};
    for (int i{0}; i < sz; i++)
    {
        p[i] = elem[i];
    }
    delete[] elem;
    elem = p;
    space = newspace;
}

void myvector::push_back(double d)
{

    if (space == 0)
    {
        reserve(8);
    }
    else
    {
        if (sz == space)
        {
            reserve(space * 2);
        }
    }

    elem[sz] = d;
    ++sz;
}
void myvector::resize(const int newsize)
{
    reserve(newsize);
    for (int i{sz}; i < newsize; i++)
    {
        elem[i] = 3.0;
    }
    sz = newsize;
}
