#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
class myvector
{
    int sz;
    double *elem;
    int space;

public:
    myvector();
    explicit myvector(int);
    myvector(const myvector &);
    ~myvector();
    int size() const { return sz; };
    int capacity() const { return space; };
    double get(int) const; /// getter
    void set(int, double); // setter
    myvector &operator=(const myvector &);
    void reserve(int);
    void push_back(double);
    void resize(int);
};

#endif