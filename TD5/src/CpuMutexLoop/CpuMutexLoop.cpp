/**
 * @file CpuMutexLoop.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in CpuMutexLoop.h.
 * @date 04-2022
 */

#include "CpuMutexLoop.h"

#include "../Calibrator/Calibrator.h"

#include <iostream>

CpuMutexLoop::CpuMutexLoop(CpuLoop *_loop, int policy, int _priority, Mutex *_mutex, double _execTime, double _beginMutex, double _durationMutex) : Thread(), loop(_loop), mutex(_mutex), execTime(_execTime), beginMutex(_beginMutex), durationMutex(_durationMutex)
{
	priority = _priority;
	setScheduling(policy, priority);
}

CpuMutexLoop::~CpuMutexLoop()
{}

void CpuMutexLoop::run()
{
	std::cout << ">> Thread with priority : " << priority << std::endl;
	if(beginMutex > 0)
	{
		loop->runTime((double) beginMutex / CLOCKS_PER_SEC * 1e3);                                  /*!< Before getting the mutex*/
		Mutex::Lock lock(*mutex);
		std::cout << ">>> Thread with priority " << priority << " WITH Mutex" << std::endl;
		loop->runTime((double) durationMutex / CLOCKS_PER_SEC * 1e3);                               /*!< With the mutex*/
		lock.~Lock();
		loop->runTime((double) (execTime - (durationMutex + beginMutex)) / CLOCKS_PER_SEC * 1e3);   /*!< After unlock of the mutex*/
	}
	else
	{
		loop->runTime((double) execTime / CLOCKS_PER_SEC * 1e3);
		std::cout << ">>> Thread with priority " << priority << " WITHOUT Mutex" << std::endl;
	}
}
