#ifndef Looper_h_INCLUDED
#define Looper_h_INCLUDED

/**
 * @file Looper.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class Looper.
 * @date 04-2022
 */

#include <cfloat>
#include <limits>

/**
 * @brief Class Looper that cycles until the stop.
 * 
 */
class Looper
{
private:
    volatile bool doStop;
    volatile double iLoop;

protected:


public:
    /**
     * @brief Runs a number of iterations of a loop.
     * 
     * @param nLoops 
     * @return double 
     */
	double runLoop(double nLoops = __DBL_MAX__); 

    /**
     * @brief Get the Sample object
     * 
     * @return double 
     */
    double getSample();

    /**
     * @brief Stop the looper and return the number of loops.
     * 
     * @return double 
     */
    double stopLoop();
};

#endif