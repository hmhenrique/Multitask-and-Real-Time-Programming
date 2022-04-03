/**
 * @file main_td2c.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Multi-task execution of an incremental function with Mutex.
 * @date 04-2022
 */

#include <time.h>
#include <iostream>
#include "TimerLib/TimerLib.h"
#include <mutex>

/**
 * @brief Struct with the varibles used in each thread. Now with the Mutex.
 * 
 */
struct threadArg
{
    int nLoops;
    volatile double pCounter;
    bool isProtected;
    pthread_mutex_t mutex;
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

    if (pThread_arg->isProtected)
    {
        pthread_mutex_lock(&pThread_arg->mutex);
        incr(pThread_arg->nLoops, (double*) &pThread_arg->pCounter);
        pthread_mutex_unlock(&pThread_arg->mutex);
    }
    else
    {
        incr(pThread_arg->nLoops, (double*) &pThread_arg->pCounter);
    }

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

    bool isMutexP;

    if(argc < 3)                                                                /*!< Ckecking the arguments, determining if is or not protected */
    {
        std::cout << "Value 'nLoops', 'nTasks' required, if mutex, 'protected' also." << std::endl;
        return 1;
    }
    else if(argc == 3)
    {
        isMutexP = false;
        std::cout << "\n**NOT Protected**\n" << std::endl;
    }
    else if(argc == 4){
        std::string protedArg(argv[3]);
        if (protedArg == "protected")
        {
            std::cout << "\n**Protected**\n" << std::endl;
            isMutexP = true;
        }
        else
        {
            std::cout << "\n**NOT Protected**\n" << std::endl;
            std::cout << "**For protection : 'protected'**\n" << std::endl;
        }
    }

    int nLoops = atoi(argv[1]);
    unsigned int nTasks = atoi(argv[2]);

    pthread_mutex_t mutex;                                                                   /*!< Initializing the mutex*/
    threadArg threadData = {nLoops, 0.0, isMutexP, mutex};

    if (isMutexP) 
        pthread_mutex_init(&threadData.mutex, nullptr);

    pthread_t incrementThread[nTasks];

    time_begin = timespec_now();
	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_create(&incrementThread[i], nullptr, call_incr, (void*) &threadData);        /*!< Creating and starting the task */
		std::cout << "Thread " << i << " created" << std::endl;
	}

    std::cout << std::endl;

	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_join(incrementThread[i], nullptr);                                           /*!< Waiting the task finish*/
		std::cout << "Thread " << i << " joined" << std::endl;
	}

    time_end = timespec_now();

    std::cout << std::endl;

    std::cout << "Counter value : " << threadData.pCounter << std::endl; 
    std::cout << "\nTime needed : " << (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000) << " seconds" << std::endl; 

    return 0;
}