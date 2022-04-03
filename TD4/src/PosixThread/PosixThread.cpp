/**
 * @file PosixThread.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in PosixThread.h.
 * @date 04-2022
 */

#include "PosixThread.h"


PosixThread::PosixThread()
{
    this -> isActive = false;
    this -> posixId = 0;
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&posixAttr, SCHED_OTHER);

    sched_param schedParam;
    schedParam.sched_priority = 0;
    pthread_attr_setschedparam(&posixAttr, &schedParam);
}

PosixThread::PosixThread(pthread_t posixId): posixId (posixId)
{
    pthread_attr_init(&posixAttr);
    pthread_attr_setinheritsched(&posixAttr, PTHREAD_EXPLICIT_SCHED);

    sched_param schedParam;
    int policy = 0;

    if(pthread_getschedparam(this -> posixId, &policy, &schedParam) == 0)
    {
        pthread_attr_setschedpolicy(&posixAttr, policy);
        pthread_attr_setschedparam(&posixAttr, &schedParam);
        this->isActive = true;
    }
    else
        throw PosixThread::Exception();
}

PosixThread::~PosixThread()
{
    pthread_attr_destroy(&posixAttr);
}
  
void PosixThread::start(Func threadFunc, void* threadArg)
{
    pthread_create(&posixId, &posixAttr, threadFunc, threadArg);
    isActive = true;
}

void PosixThread::join()
{
    pthread_join(posixId, NULL);
}

bool PosixThread::setScheduling(int schedPolicy, int priority)
{
    sched_param schedParam;
    schedParam.sched_priority = priority; 
    if(isActive)
        pthread_setschedparam(posixId, schedPolicy, &schedParam);
    else
    {
        pthread_attr_setschedpolicy(&posixAttr, schedPolicy);
        pthread_attr_setschedparam(&posixAttr, &schedParam);
    }
    return isActive;
}
    
bool PosixThread::getScheduling(int* p_schedPolicy, int* p_priority)
{
    sched_param schedParam;
    *p_priority = schedParam.sched_priority; 
    if(isActive)
        pthread_getschedparam(posixId, p_schedPolicy, &schedParam);
    else
    {
        pthread_attr_getschedpolicy(&posixAttr, p_schedPolicy);
        pthread_attr_getschedparam(&posixAttr, &schedParam);
    }
    return isActive;
}


const char *PosixThread::Exception::what() const noexcept
{
    return "\n-- ERROR: Thread does not exist! --\n";
}