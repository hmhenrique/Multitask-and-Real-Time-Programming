/**
 * @file FifoProducer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in FifoProducer.h.
 * @date 04-2022
 */

#include "FifoProducer.h"

FifoProducer::FifoProducer(Fifo<int> *fifo, unsigned maxNum) : Thread(), fifo(fifo), maxCount(maxNum)
{}

FifoProducer::~FifoProducer()
{}

void FifoProducer::run()
{
	for(unsigned i = 0; i < maxCount; i++)
    {
    	fifo -> push(i);
		sum = sum + i;
    	count++;
    }
}
	
unsigned int FifoProducer::getCount()
{
	return count;
}

unsigned int FifoProducer::getSum()
{
	return sum;
}