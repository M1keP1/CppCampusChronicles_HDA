#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

class myvector
{
    int sz;           // Size of the vector
    double *elem;     // Pointer to the dynamically allocated array
    int space;        // Capacity of the vector

public:
    myvector();       // Default constructor
    explicit myvector(int);    // Constructor with size parameter explicit typ
    myvector(const myvector &);   // Copy constructor
    ~myvector();     // Destructor
    
    int size() const { return sz; };   // Getter for the size of the vector
    int capacity() const { return space; };   // Getter for the capacity of the vector
    double get(int) const;   // Getter for accessing the value at a specific index
    void set(int, double);   // Setter for modifying the value at a specific index
    myvector &operator=(const myvector &);   // Assignment operator overloading
    void reserve(int);   // Reserves memory for a specified capacity
    void push_back(double);   // Adds a new element to the back of the vector
    void resize(int);   // Resizes the vector to a new size

};

#endif
