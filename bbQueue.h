#ifndef BBQUEUE_H
#define BBQUEUE_H

#include<iostream>
#include<vector>

#include "customer.h"

using namespace std;

struct bbQueue{
    bbQueue(int s = 4);
    ~bbQueue();
    bbQueue(const bbQueue &other);
    void push(customer c);
    void resize(int s);
    int size();
    customer pop();
    customer rPop();
    bool full();
    bool empty();
    bool wellDone();
    void moreTime();
    void sbMoreTime();
    void returnToTheLine(customer c);

private:
    int size_;
    vector<customer> meat;
};

#endif // BBQUEUE_H
