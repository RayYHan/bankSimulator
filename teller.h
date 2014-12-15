#ifndef TELLER_H
#define TELLER_H

#include<iostream>
#include<time.h>
#include<stdlib.h>

struct teller
{
    teller();
    teller(int l, int t1, int t2);
    ~teller();
    teller(const teller &other);
    bool onDuty(int t);
    void occupy();
    void vacate();
    bool occupied();
private:
    int lunch_, tea_1, tea_2;
    bool occupied_;

};

#endif // TELLER_H
