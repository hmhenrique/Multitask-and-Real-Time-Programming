/**
 * @file Thread.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Thread.h.
 * @date 04-2022
 */

#include "Thread.h"
#include "../TimerLib/TimerLib.h"

Thread::Thread()
{}

Thread::~Thread()
{}

bool Thread::start()
{

    if(!started){
    startTime = timespec_now();
    PosixThread::start(call_run, (void*) this);
    started = true;
    }

    return started;
}

void* Thread::call_run(void* v_thread)
{
    Thread& thread = *((Thread*) v_thread);
    thread.run();
    thread.stopTime = timespec_now();
    return v_thread;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec_wait(timespec_from_ms(delay_ms));
}

double Thread::startTime_ms()
{
    return timespec_to_ms(startTime);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(stopTime);
}

double Thread::execTime_ms()
{
    return timespec_to_ms(stopTime - startTime);
}