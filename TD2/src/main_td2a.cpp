/**
 * @file main_td2a.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief  Multi-task execution of an incremental function without Mutex.
 * @date 04-2022
 */

#include <time.h>
#include <iostream>
#include "TimerLib/TimerLib.h"

/**
 * @brief Struct with the varibles used in each thread.
 * 
 */
struct threadArg
{
    int nLoops;
    volatile double pCounter;
};

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
 * @brief Function that calls the incr() function.
 * 
 * @param thread_arg 
 * @return void* 
 */
void* call_incr(void* thread_arg)
{
	threadArg* pThread_arg = (threadArg*) thread_arg;
	incr(pThread_arg -> nLoops, (double*) &pThread_arg->pCounter);
	return thread_arg;
}

/**
 * @brief Implement the main function, using the methods created.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{

    timespec time_begin, time_end;

    if(argc != 3)
    {
        std::cout << "Value 'nLoops' and 'nTasks' required." << std::endl;
        return 1;
    }

    int nLoops = atoi(argv[1]);
    unsigned int nTasks = atoi(argv[2]);

    threadArg threadData = {nLoops, 0.0};

    pthread_t incrementThread[nTasks];

    time_begin = timespec_now();
	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_create(&incrementThread[i], NULL, call_incr, (void*) &threadData); /*!< Creating and starting the task */
		std::cout << "Thread " << i << " created" << std::endl;
	}

    std::cout << std::endl;

	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_join(incrementThread[i], NULL);                                      /*!< Waiting the task finish*/
		std::cout << "Thread " << i << " joined" << std::endl;
	}

    time_end = timespec_now();

    std::cout << std::endl;

    std::cout << "Counter value : " << threadData.pCounter << std::endl; 
    std::cout << "\nTime needed : " << (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000) << " seconds" << std::endl; 

    return 0;
}