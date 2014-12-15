#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

struct customer{
    customer(bool e = true);
    ~customer();
    customer(const customer &other);
    customer &operator=(const customer &other);
    int difficulty();
    bool loyalty();
    int waitTime();
    void timePassed();
    void beingServed();
    bool existence();

private:
    int difficulty_, waitTime_;
    bool loyalty_;
    bool existence_;

    friend
    bool operator==(const customer &c1, const customer &c2);
};

#endif // CUSTOMER_H
