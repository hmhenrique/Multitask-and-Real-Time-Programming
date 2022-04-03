/**
 * @file Looper.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Looper.h.
 * @date 04-2022
 */

#include <iostream>
#include "Looper.h"

double Looper::runLoop(double nLoops)
{
    std::cout << "-- runLoop --"  << std::endl;
    doStop = false;
    for(iLoop=0 ; iLoop < nLoops ; ++iLoop)
        if (doStop)
            break;
    return iLoop;
}

double Looper::getSample()
{
    return iLoop;
}

double Looper::stopLoop()
{
    doStop = true;
    return iLoop;
}

