#include "bbQueue.h"

bbQueue::bbQueue(int s)
{
    size_ = s;
    meat.clear();
}

bbQueue::~bbQueue()
{
    size_ = 0;
    meat.clear();
}

void bbQueue::push(customer c)
{
    meat.push_back(c);
}

void bbQueue::resize(int s)
{
    size_ = s;
}

int bbQueue::size()
{
    return meat.size();
}

customer bbQueue::pop()
{
    customer temp = meat[0];
    meat.erase(meat.begin());
    return temp;
}

customer bbQueue::rPop()
{
    customer temp = meat[meat.size() - 1];
    meat.erase(meat.end());
    return temp;
}

bool bbQueue::full()
{
    return size_ == meat.size();
}

bool bbQueue::empty()
{
    return meat.size() == 0;
}

bool bbQueue::wellDone()
{
    return meat[0].difficulty() == 0;
}

void bbQueue::moreTime()
{
    if(!meat.empty())
    {
        meat[0].beingServed();
        for(int i = 1; i < meat.size(); i++)
            meat[i].timePassed();
    }
}

void bbQueue::sbMoreTime()
{
    for(int i = 0; i < meat.size(); i++)
        meat[i].timePassed();
}

void bbQueue::returnToTheLine(customer c)
{
    meat.insert(meat.begin(), c);
    while(meat.size() > size_)
        meat.erase(meat.end());
}
