/**
 * @file Calibrator.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Calibrator.h.
 * @date 04-2022
 */

#include <vector>
#include <iostream>
#include "Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned nSamples)
{
    numSamples = nSamples;

    std::cout << "-- Calibrator --"  << std::endl;

    PeriodicTimer::start(samplingPeriod_ms);
    looper.runLoop();

    // Making a Linear Regression

    double sumX=0, sumX2=0, sumY=0, sumXY=0;

    for (unsigned int i = 0; i<nSamples; i++)
    {
        sumX = sumX + samplingPeriod_ms*(i+1);
        sumX2 = sumX2 + (samplingPeriod_ms*(i+1))*(samplingPeriod_ms*(i+1));
        sumY = sumY + samples[i];
        sumXY = sumXY + (samplingPeriod_ms*(i+1))*samples[i];
    }

    a = (nSamples*sumXY-sumX*sumY)/(nSamples*sumX2-sumX*sumX);
    b = (sumX2*sumY - sumX*sumXY)/(nSamples*sumX2 - sumX*sumX);

}

void Calibrator::callback()
{
    --numSamples;
    if (numSamples == 0)
    {
        samples.push_back(looper.stopLoop());
        stop();
    }
    else
    samples.push_back(looper.getSample());
}



double Calibrator::nLoops(double duration_ms)
{
    return (a*duration_ms + b);
}