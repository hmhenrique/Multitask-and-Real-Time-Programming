/**
 * @file main_td1b.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Using signal.h and the timer POSIX to implement a timer of 2Hz that 
 * increments a counter
 * @date 04-2022
 */
#include <time.h>
#include <iostream>
#include <signal.h>

/**
 * @brief Callback function that increments the associated counter.
 * 
 * @param si 
 */
void myHandler(int, siginfo_t* si, void*)
{
    volatile int& count_ref = *((int*) si->si_value.sival_ptr);
    std::cout<<"My compteur : " << count_ref << std::endl;
    count_ref += 1;
}

/**
 * @brief main function, definin the timer posix.
 * 
 * @return int 
 */
int main()
{
    volatile int count = 0;

    struct sigaction sa;                             /*!< Action to be taken in the end of the timer*/
    sa.sa_flags = SA_SIGINFO;                        /*!< Defining the action*/
    sa.sa_sigaction = myHandler;                     /*!< Pointer to the function 'myHandler'*/
    sigemptyset(&sa.sa_mask);                        /*!< No signal blocked during callback execution*/
    sigaction(SIGRTMIN, &sa, nullptr);               /*!< Action associated with a real-time signal*/

    struct sigevent sev;                             /*!< Timer expiry event*/
    sev.sigev_notify = SIGEV_SIGNAL;                 /*!< 'Signal' type event*/
    sev.sigev_signo = SIGRTMIN;                      /*!< Number of the transmitted signal*/
    sev.sigev_value.sival_ptr = (void*) &count;      /*!< Data transmitted to 'myHandler'*/

    timer_t tid;                                     /*!< Identifier of the timer*/
    timer_create(CLOCK_REALTIME, &sev, &tid);        /*!< Creation of the timer*/
    itimerspec its;                                  /*!< Timespec structure*/

    std::cout<<"Waiting 2 seconds" << std::endl;
    its.it_value.tv_sec = 2;                         /*!< Duration of the timer to expiry in sec*/
    its.it_value.tv_nsec = 0;                        /*!< Duration of the timer to expiry in nsec*/
    its.it_interval.tv_sec = 0;                      /*!< Periodic time in sec*/
    its.it_interval.tv_nsec = 5e8;                   /*!< Periodic time in nsec (2Hz)*/
    timer_settime(tid, 0, &its, nullptr);

    while(count < 15)
        continue;

    timer_delete(tid);                               /*!< Destruction of the timer*/

    return 0;
}
