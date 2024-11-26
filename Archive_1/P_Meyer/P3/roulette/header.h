#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <random>
using namespace std ;



class player
{
private:

    int pricemoney{10000};
    std::string name{};

public:
    player(const std::string &n);


    void set_name(const std::string &n);
    std::string get_name();
    int get_price_money();
    void set_pricemoney(int change);


};


#endif // HEADER_H
