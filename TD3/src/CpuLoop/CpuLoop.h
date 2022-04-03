#ifndef CpuLoop_h_INCLUDED
#define CpuLoop_h_INCLUDED

/**
 * @file CpuLoop.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Looper and make a calibration for a given time.
 * @date 04-2022
 */

#include "../Calibrator/Calibrator.h"

/**
 * @brief Class derivated from Looper
 * 
 */
class CpuLoop : public Looper
{
private:

    /**
     * @brief An calibrator object.
     * 
     */
    Calibrator calibrator;

protected:

public:

    /**
     * @brief Construct a new Cpu Loop object.
     * 
     * @param calibrator 
     */
    CpuLoop(Calibrator& calibrator);

    /**
     * @brief Run the loopers object in a determined time.
     * 
     * @param duration_ms 
     */
    void runTime(double duration_ms);
};

#endif