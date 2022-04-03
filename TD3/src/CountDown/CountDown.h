#ifndef CountDown_h_INCLUDED
#define CountDown_h_INCLUDED

/**
 * @file CountDown.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from PeriodicTimer
 * @date 04-2022
 */

#include "../PeriodicTimer/PeriodicTimer.h"

/**
 * @brief Class derivated from PeriodicTime
 * 
 */
class CountDown : public PeriodicTimer
{

private:
    int count;

public:

    /**
     * @brief Construct a new Count Down object
     * 
     * @param n 
     */
    CountDown(int n);

    /**
     * @brief Get the count object
     * 
     * @return int 
     */
    int get_count();

protected:

    /**
     * @brief Implements the virtual function Callback()
     * 
     */
    void callback();

};

#endif