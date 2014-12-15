#include "teller.h"

teller::teller()
{
    srand(time(NULL));
    lunch_ = rand() % 120 + 181;
    tea_1 = rand() % 165 + 1;
    tea_2 = rand() % 165 + 181;
    occupied_ = false;
}

teller::teller(int l, int t1, int t2)
{
    lunch_ = l;
    tea_1 = t1;
    tea_2 = t2;
}

teller::teller(const teller &other)
{
    lunch_ = other.lunch_;
    tea_1 = other.tea_1;
    tea_2 = other.tea_2;
}

teller::~teller()
{
    lunch_ = tea_1 = tea_2 = 0;
}

bool teller::onDuty(int t)
{
    if(t >= tea_1 && t <= tea_1 + 15)
        return false;
    else if(t >= lunch_ && t <= lunch_ + 30)
        return false;
    else if(t >= tea_2 && t <= tea_2 + 15)
        return false;
    else
        return true;
}

void teller::occupy()
{
    occupied_ = true;
}

void teller::vacate()
{
    occupied_ = false;
}

bool teller::occupied()
{
    return occupied_;
}
