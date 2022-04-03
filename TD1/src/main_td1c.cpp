/**
 * @file main_td1c.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief miplementing the function 'incr(unsigned int nLoops, double* pCounter)'
 * @date 04-2022
 */
#include <time.h>
#include <iostream>
#include "TimerLib/TimerLib.h"

/**
 * @brief Realise an incrementation by 1 in a counter pointed by pCounter nLoops times.
 * 
 * @param nLoops 
 * @param pCounter 
 */
void incr(unsigned int nLoops, double* pCounter)
{
    for(unsigned int i = 0; i < nLoops; ++i)
        *pCounter += 1.0;
}

/**
 * @brief Implementation of the main function.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    timespec time_begin, time_end;
    double counter = 0.0;

    if(argc == 1)                          /*!< Checking the arguments */
    {
        std::cout << "Value 'nLoops' required." << std::endl;
        return 1;
    }

    time_begin = timespec_now();
    incr(atoi(argv[1]), &counter);         /*!< Call of the incr() function */
    time_end = timespec_now();

    std::cout << "Counter value : " << counter << std::endl; 
    std::cout << "\nTime needed : " << (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000) << " seconds" << std::endl; 

    return 0;
}



