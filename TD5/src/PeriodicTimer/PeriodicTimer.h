#ifndef PeriodicTimer_h_INCLUDED
#define PeriodicTimer_h_INCLUDED

/**
 * @file PeriodicTimer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Timer
 * @date 04-2022
 */

#include "../Timer/Timer.h"

/**
 * @brief Class PeriodicTimer that implements a periodic timer Posix.
 * 
 */
class PeriodicTimer : public Timer
{

public:

    /**
     * @brief Start the periodic tiemr.
     * 
     * @param duration_ms 
     */
    void start(double duration_ms);

};

#endif