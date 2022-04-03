/**
 * @file main_td4a.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Create a number nTasks of threads that realise nLoops increments in a counter. Not using mutex.
 * @date 04-2022
 */

#include <iostream>
#include <vector>

#include "Incrementer/Incrementer.h"
#include "Chrono/Chrono.h"

/**
 * @brief The main function.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        std::cout << "Value 'nLoops' 'nTasks' 'Sched Policy' required." << std::endl;
        return 1;
    }

    int nTasks = atoi(argv[2]);

    std::string scheduleArg(argv[3]);

    int schedPolicy;

    if(scheduleArg == "SCHED_RR")
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

    Data data = {(unsigned int)atoi(argv[1]), 0.0, schedPolicy};
    Data *ptrData = &data;

    Chrono chrono;

    std::vector<Incrementer> incrementer;

    double threadsTime = 0;

	for (int i = 0; i < nTasks; i++)
    {
        incrementer.push_back(Incrementer(ptrData));                                      /*!< Creating threads*/
		std::cout << "Thread " << i << " created" << std::endl;
    }
    
    for (int j = 0; j < nTasks; j++)
    {
        incrementer[j].start();                                                           /*!< Starting the Threads*/
    }

    std::cout << std::endl;
    for (int k = 0; k < nTasks; k++)
    {
        incrementer[k].join();                                                            /*!< Waiting the end of the Thread*/
        std::cout << "Thread " << k << " joined" << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i<nTasks; i++)
    {
		std::cout << "Thread " << i <<" execution time: " << incrementer[i].execTime_ms() << " ms" << std::endl;
        threadsTime += incrementer[i].execTime_ms();
    }
    
    chrono.stop();
    std::cout << std::endl;
    std::cout << "Final counter value: " << ptrData->pCounter << std::endl;
    std::cout << "Time for all the threads : " << threadsTime << " ms" << std::endl;
    std::cout << "Main execution : " << chrono.lap() << "ms" << std::endl;
    
    return 0;
}