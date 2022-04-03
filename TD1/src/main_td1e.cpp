/**
 * @file main_td1e.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the calib() function that aims to estimate the coefficients 
 * of an affine function relating the number of loops to the time spent. Using also
 * a method of mean to try to improve the estimation.
 * @date 04-2022
 */
#include <time.h>
#include <iostream>
#include <climits>
#include <signal.h>

#include "TimerLib/TimerLib.h"

/**
 * @brief Realise an incrementation by 1 in a counter pointed by pCounter nLoops times.
 * Now, being possible to interrupt with a boolean pStop.
 * 
 * @param nLoops 
 * @param pCounter 
 * @param pStop 
 * @return unsigned int 
 */
unsigned int incr(unsigned int nLoops, volatile double* pCounter, bool* pStop)
{
    unsigned int iLoop=0;
    for(iLoop=0 ; iLoop < nLoops ; ++iLoop)
    {
        if (*pStop)
            break;
        *pCounter += 1.0;
    }
    return iLoop;
}

/**
 * @brief Callback function that sets the pStop boolean to true in the time expiration.
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    *((bool*)si->si_value.sival_ptr) = true;
    std::cout << "'stop' is set to true" <<  std::endl;
}

/**
 * @brief Implementing a Posix timer, measuring the number of loops before the stop.
 * 
 * @param sec 
 * @return double 
 */
double setIncrement(time_t sec)
{
    bool stop = false;
    unsigned int nLoops = UINT_MAX;
    volatile double counter = 0.0;


    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);

    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &stop;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);
    itimerspec its;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0; 
    timer_settime(tid, 0, &its, nullptr);

    unsigned int iLoop = incr(nLoops, &counter, &stop);

    std::cout << "Counter value for " << sec << " seconds : " << counter << std::endl; 

    timer_delete(tid);

    return (double) iLoop;
}

/**
 * @brief Struct with the value of the coefficients of the affine function.
 * 
 */
struct coef
{
    double a;
    double b;
};

/**
 * @brief Function that sets the values of a and b by measuring 
 * the iLoop value for 4 seconds and for 6 seconds.
 * 
 * @return coef 
 */
coef calib()
{
    coef params;

    double iLoop_4sec = setIncrement((time_t) 4);
    double iLoop_6sec = setIncrement((time_t) 6);

    //calculatingthe function:
    params.a = (iLoop_6sec - iLoop_4sec)/(6 - 4);
    params.b = (iLoop_6sec - params.a*6);

    return params;
}

/**
 * @brief Implementation of the main function, calling the created methods and 
 * using a method of recursive averages.
 * 
 * @return int 
 */
int main()
{
    /*!< Making a mean of the parameters */
    int nTest = 3;
    coef params = calib();
    double a_mean = params.a, b_mean = params.b;
    for (int j = 0; j < nTest; j++)
    {
        params = calib();
        a_mean = (params.a + a_mean)/2;
        b_mean = (params.b + b_mean)/2;
    }

    std::cout << "\nCalculated parameters: a = " << a_mean << " b = " << b_mean << std::endl;

    std::cout << "\nChecking the parameters" << std::endl;

    std::cout << "\nFor a 9 seconds timer:" << std::endl;
    timespec time_begin, time_end;
    time_begin = timespec_now();
    double coefCal = setIncrement((time_t) 9);
    time_end = timespec_now();
    std::cout << "\nTime needed : " << (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000) << " seconds" << std::endl; 
    std::cout << "\niLoop directed obtained = " << coefCal << std::endl; 

    double coefCalFunction = a_mean*9 + b_mean;
    std::cout << "\niLoop directed by the function= " << coefCalFunction << std::endl; 
    std::cout << "\nAccuracy: " << (1-(abs(coefCal - coefCalFunction) /coefCal))*100 << "%" << std::endl;

    return 0;
}



