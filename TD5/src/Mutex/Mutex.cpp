/**
 * @file Mutex.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Mutex.h.
 * @date 04-2022
 */

#include <iostream>
#include <string.h>
#include "Mutex.h"
#include "../TimerLib/TimerLib.h"


Mutex::Mutex(bool isInversionSafe)
{
	pthread_mutexattr_t mutexAttribute;									
	pthread_mutexattr_init(&mutexAttribute);							
    pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);
    if(isInversionSafe)
    {
        pthread_mutexattr_setprotocol(&mutexAttribute, PTHREAD_PRIO_INHERIT);
    }
	pthread_mutex_init(&posixId, &mutexAttribute);
	pthread_cond_init(&posixCondId, nullptr);
	pthread_mutexattr_destroy(&mutexAttribute);
}
	
Mutex::~Mutex()
{
    //pthread_mutex_unlock(&posixId);
    pthread_mutex_destroy(&posixId);
	pthread_cond_destroy(&posixCondId);
}

void Mutex::lock()
{	
    pthread_mutex_lock(&posixId); 	
}

bool Mutex::lock(double timeout_ms)
{
    timespec timeout_tspec = timespec_from_ms(timeout_ms)+timespec_now();
    return 0 == pthread_cond_timedwait(&posixCondId, &posixId, &timeout_tspec);
}

bool Mutex::trylock()
{
	return 0 == pthread_mutex_trylock(&posixId);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&posixId);
}

// class Monitor

Mutex::Monitor::Monitor(Mutex& m):m(m)
{}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&m.posixCondId, &m.posixId);	
}

bool Mutex::Monitor::wait(double timeout_ms)
{
	timespec timeout_tspec=(timespec_now())+timespec_from_ms(timeout_ms);																					
	return 0 == pthread_cond_timedwait(&m.posixCondId, &m.posixId, &timeout_tspec);								
}

void Mutex::Monitor::notify()
{
    pthread_cond_signal(&m.posixCondId);									
}

void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&m.posixCondId);
}

//class Lock::Monitor
Mutex::Lock::Lock(Mutex &m): Monitor(m)
{
    m.lock();
}

Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Monitor(m)
{
    if (m.lock(timeout_ms))
        throw Mutex::Monitor::TimeoutException();
}

Mutex::Lock::~Lock()
{
    m.unlock();
}

//class TryLock::Monitor
Mutex::TryLock::TryLock(Mutex& m): Monitor(m)
{
	if (m.trylock()) 
		throw Mutex::Monitor::TimeoutException();
}

Mutex::TryLock::~TryLock()
{}
