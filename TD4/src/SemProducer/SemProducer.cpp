/**
 * @file SemProducer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in SemProducer.h.
 * @date 04-2022
 */

#include "SemProducer.h"

SemProducer::SemProducer(Semaphore *sem, unsigned int maxCount) : Thread(), semaphore(sem), counter(0), maxCount(maxCount)
{}

SemProducer::~SemProducer()
{}

void SemProducer::run(){
    for(unsigned int i = 0; i < maxCount; i++)
    {
    	semaphore -> give();
    	counter++;
    }
}

unsigned SemProducer::getCounter()
{
    return counter;
}