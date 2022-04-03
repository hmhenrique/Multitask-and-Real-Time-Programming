/**
 * @file main_td3c.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Testing the calibration with the classes implemented.
 * @date 04-2022
 */

#include <iostream>
#include "Calibrator/Calibrator.h"
#include "CpuLoop/CpuLoop.h"
#include "Chrono/Chrono.h"


/**
 * @brief The main function, calling the methods.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        std::cout << "Value 'samplingPeriod_ms' 'nSamples' 'duration_ms' required." << std::endl;
        return 1;
    }

    double samplingPeriod_ms = (double) atoi(argv[1]);
    unsigned int nSamples = (unsigned int) atoi(argv[2]);
    double duration_ms = (double) atoi(argv[3]);

    std::cout << "Parameters :" << "\n 'samplingPeriod_ms' = "<< samplingPeriod_ms<<"\n 'nSamples' = " << nSamples <<"\n 'duration_ms' = " << duration_ms << std::endl;
    
    Calibrator calibrator(samplingPeriod_ms, nSamples); 
    std::cout << "Testing estimation for " << duration_ms/1000 << " [s]" << std::endl;

    CpuLoop	loop(calibrator);            /*!<  Testing the estimation*/
    Chrono chrono;

    loop.runTime(duration_ms);           /*!< Running an Timer with the Loops determined by the equation*/
    chrono.stop();
    std::cout << "Result : " << chrono.lap()/1000 << " [s]" << std::endl;

    return 0;
}