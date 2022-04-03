/**
 * @file PeriodicTimer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in PeriodicTimer.h.
 * @date 04-2022
 */

#include "PeriodicTimer.h"
#include "../TimerLib/TimerLib.h"

#include <iostream>

void PeriodicTimer::start(double duration_ms)
{
    itimerspec its;

    its.it_value = timespec_from_ms(duration_ms);
    its.it_interval = its.it_value;

    timer_settime(tid, 0, &its, nullptr);
}