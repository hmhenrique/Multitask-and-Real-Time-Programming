/**
 * @file main_td2b.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief  Implementing an incremental function with the Real Time Scheduling definitions.
 * @date 04-2022
 */

#include <time.h>
#include <iostream>
#include "TimerLib/TimerLib.h"
#include <pthread.h>
#include <fstream>
#include <string>

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
 * @brief Function to export values in a .txt file.
 * 
 * @param nTasks 
 * @param nLoops 
 * @param timeExec 
 * @param policy 
 * @param pCounter 
 */
void expValues(int nTasks, int nLoops, double timeExec, int policy, volatile double pCounter)
{
    std::ofstream file;
	file.open ("expResults.txt", std::ofstream::app);
	file << "nTasks: " << nTasks << "   nLoops: " << nLoops << "   time: " << timeExec << "     Policy : " << policy  << "     Counter :" << pCounter <<  "\n";
	file.close();
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

    if(argc != 4)
    {
        std::cout << "Format : './main_td2b nLoops nTasks schedPolicy'" << std::endl;
        return 1;
    }

    int nLoops = atoi(argv[1]);
    unsigned int nTasks = atoi(argv[2]);
    std::string scheduleArg(argv[3]);

    threadArg threadData = {nLoops, 0.0};

    int schedPolicy;

    if(scheduleArg == "SCHED_RR")                      /*!< Ckecking the arguments for setting the sched policy */
    {
		schedPolicy=1;
        std::cout << "------ SCHED_RR" << std::endl;	
    }
    else if(scheduleArg == "SCHED_FIFO")
    {
		schedPolicy=2;
        std::cout << "------ SCHED_FIFO" << std::endl;	
    }
	else
    {
		schedPolicy=0;
        std::cout << "------ SCHED_OTHER" << std::endl;	
    }

    sched_param	schedParams;
    schedParams.sched_priority = (schedPolicy == 0) ? 0 : 10;

    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, schedPolicy);
    pthread_attr_setschedparam(&attr, &schedParams);


    sched_param schedParamMain;                                                       /*!< Giving to the main, the highest priority*/
	schedParamMain.sched_priority = sched_get_priority_max(schedPolicy);
	pthread_setschedparam(pthread_self(), schedPolicy, &schedParamMain);

    pthread_t incrementThread[nTasks];

    time_begin = timespec_now();
	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_create(&incrementThread[i], &attr, call_incr, (void*) &threadData);   /*!< Creating and starting the task */
		std::cout << "Thread " << i << " created" << std::endl;
	}

    std::cout << std::endl;

	for(unsigned int i = 0; i<nTasks; i++)
	{
		pthread_join(incrementThread[i], NULL);                                        /*!< Waiting the task finish*/
		std::cout << "Thread " << i << " joined" << std::endl;
	}

    time_end = timespec_now();

    double timeExec = (timespec_to_ms((const timespec) ((time_end - time_begin)))/1000);

    std::cout << std::endl;

    std::cout << "Counter value : " << threadData.pCounter << std::endl; 
    std::cout << "\nTime needed : " << timeExec << " seconds" << std::endl; 

    expValues(nTasks, nLoops, timeExec, schedPolicy, threadData.pCounter );

    return 0;
}



