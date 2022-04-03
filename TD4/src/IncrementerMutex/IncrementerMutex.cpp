/**
 * @file IncrementerMutex.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in IncrementerMutex.h.
 * @date 04-2022
 */

#include"IncrementerMutex.h"

#include <iostream>

IncrementerMutex::IncrementerMutex(Data* data, Mutex &mutex) : Thread(), data_(data), mutex_(mutex)
{
    int schedPriority = rand()%9 + 1;       //1 -> 10 
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
}

IncrementerMutex::~IncrementerMutex()
{}

void IncrementerMutex::run()
{
    for(unsigned int i = 0; i < data_->nLoops; ++i)
    {
        Mutex::Lock lock(mutex_);
        data_->pCounter += 1.0;
    }
}