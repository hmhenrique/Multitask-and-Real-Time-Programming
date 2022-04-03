/**
 * @file FifoConsumer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in FifoConsumer.h.
 * @date 04-2022
 */

#include "FifoConsumer.h"

FifoConsumer::FifoConsumer(Fifo<int> *fifo, unsigned int maxCount) : Thread(), fifo(fifo), maxCount(maxCount)
{}

FifoConsumer::~FifoConsumer()
{}

void FifoConsumer::run()
{
    try
    {   
        while(myCounter<maxCount){
            mySum = mySum + fifo->pop();
            myCounter++;
        }
    }
    catch(const Fifo<int>::EmptyException& e)
    {
        isActive = false;
    }
}

unsigned int FifoConsumer::getCounter()
{
    return myCounter;
}

unsigned int FifoConsumer::getSum()
{
    return mySum;
}
