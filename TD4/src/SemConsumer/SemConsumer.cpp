/**
 * @file SemConsumer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in SemConsumer.h.
 * @date 04-2022
 */

#include "SemConsumer.h"

SemConsumer::SemConsumer(Semaphore *sem, unsigned int maxCount) : Thread(), semaphore(sem),  maxCount(maxCount)
{}

SemConsumer::~SemConsumer()
{}

void SemConsumer::run()
{
    while(mycounter < maxCount){
        semaphore->take();
        mycounter++;
    }
    
}

unsigned SemConsumer::getCounter()
{
    return mycounter;
}