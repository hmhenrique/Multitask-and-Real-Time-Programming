/**
 * @file Semaphore.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Semaphore.h.
 * @date 04-2022
 */

#include"Semaphore.h"
#include "../TimerLib/TimerLib.h"

Semaphore::Semaphore(unsigned initCount, unsigned maxCount) : counter(initCount), maxCount(maxCount)
{}

void Semaphore::give()
{
    Mutex::Lock lock(mutex);
    if(counter < maxCount)
        counter++;
    lock.notify();
}

void Semaphore::take()
{
    Mutex::Lock lock(mutex);
    while(counter == 0)
        lock.wait();
    counter--;
    lock.notify();
}

bool Semaphore::take(double timeout_ms)
{
    Mutex::Lock lock(mutex);
    if (counter == 0)
    {
        lock.wait(timeout_ms);
        lock.notify();
        return false;
    }
    else
    {
        counter--;
        lock.notify();
        return true;
    }
}