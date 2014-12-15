#include "customer.h"

customer::customer(bool e)
{
    existence_ = e;
    srand(time(NULL));
    difficulty_= rand()%10+5;
    loyalty_ = rand()%2;
    waitTime_ = 0;
}

customer &customer::operator=(const customer &other)
{
    difficulty_ = other.difficulty_;
    loyalty_ = other.loyalty_;
    waitTime_ = other.waitTime_;
    existence_ = other.existence_;
}

customer::customer(const customer &other)
{
    difficulty_ = other.difficulty_;
    loyalty_ = other.loyalty_;
    waitTime_ = other.waitTime_;
    existence_ = other.existence_;
}

customer::~customer()
{
    existence_ = false;
    difficulty_ = 0;
    loyalty_ = false;
    waitTime_ = 0;
}

int customer::difficulty()
{
    return difficulty_;
}

bool customer::loyalty()
{
    return loyalty_;
}

void customer::timePassed()
{
    waitTime_++;
}

void customer::beingServed()
{
    if(difficulty_ > 0)
        difficulty_--;
}

int customer::waitTime()
{
    return waitTime_;
}

bool operator==(const customer &c1, const customer &c2)
{
    if(c1.difficulty_ != c2.difficulty_)
        return false;
    else if(c1.loyalty_ != c2.loyalty_)
        return false;
    else if(c1.waitTime_ != c2.waitTime_)
        return false;
    else if(c1.existence_ != c2.existence_)
        return false;
    else
        return true;
}

bool customer::existence()
{
    return existence_;
}
