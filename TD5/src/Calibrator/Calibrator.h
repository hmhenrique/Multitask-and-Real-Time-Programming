#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED

/**
 * @file Calibrator.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from PeriodicTimer
 * @date 04-2022
 */

#include <vector>
#include "../PeriodicTimer/PeriodicTimer.h"
#include "../Looper/Looper.h"

/**
 * @brief Class derivated from PeriodicTimer
 * 
 */
class Calibrator : public PeriodicTimer
{
private:
    double a;
    double b;
    std::vector<double> samples;
    unsigned numSamples;


    Looper looper;

    /**
     * @brief The handle function.
     * 
     */
    void callback();

public:
    /**
     * @brief Construct a new Calibrator object.
     * 
     * @param samplingPeriod_ms 
     * @param nSamples 
     */
    Calibrator(double samplingPeriod_ms, unsigned nSamples);

    /**
     * @brief Estimates the number of loops.
     * 
     * @param duration_ms 
     * @return double 
     */
    double nLoops(double duration_ms);
};

#endif