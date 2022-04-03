/**
 * @file CpuLoop.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in CpuLoop.h.
 * @date 04-2022
 */

#include "CpuLoop.h"

CpuLoop::CpuLoop(Calibrator& calibrator_) : calibrator(calibrator_)
{}

void CpuLoop::runTime(double duration_ms)
{
    double nLoops = calibrator.nLoops(duration_ms);
    runLoop(nLoops); 
}