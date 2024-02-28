
//Created by Mihir on 28.02.2024

#ifndef SPECIALEMPLOYEE_H_H
#define SPECIALEMPLOYEE_H_H

#include "human_H.h"


class company;
class consulter : public Human
{
public:
    int get_gehalt();
    int generateRandomNumber(int min,int max);
private:
};
class manager : public Human
{
private:
public:
    int get_gehalt();
};

#endif // SPECIALEMPLOYEE_H_H
