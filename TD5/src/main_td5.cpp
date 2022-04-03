/**
 * @file main_td5.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the main function for the Priority Inversion test.
 * @date 04-2022
 */

#include "CpuMutexLoop/CpuMutexLoop.h"
#include "Chrono/Chrono.h"
#include <iostream>

/**
 * @brief The function main
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) 
{
	/*!< Run the code in a single CPU by setting affinity for the thread 0*/
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);
	sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);

	bool isInversionSafe;

    if(argc < 2)                                                                                  /*!< Checking the arguments received*/
    {
        std::cout << "Value 'InversionSafe' or 'notInversionSafe' required." << std::endl;
        return 1;
    }
    std::string safeArg(argv[1]);
    if (safeArg == "InversionSafe")
    {
        std::cout << "\n**InversionSafe**\n" << std::endl;
        isInversionSafe = true;
    }
    else if (safeArg == "notInversionSafe")
    {
        std::cout << "\n**NOT InversionSafe**\n" << std::endl;
		isInversionSafe = false;
    }
	else
	{
		std::cout << "Respect the format: ./main_td5 'InversionSafe' or 'notInversionSafe'." << std::endl;
		return 1;
	}

	Chrono chrono;

	Mutex mutex(isInversionSafe);                                                                /*!< Mutex set with or without protection for the inversion*/

	int policy = SCHED_RR;                                                                       /*!< Setting policy*/
	int priority_A = 3;                                                                          /*!< Setting priority for the Thread A*/
	int priority_B = 2;                                                                          /*!< Setting priority for the Thread B*/
	int priority_C = 1;                                                                          /*!< Setting priority for the Thread C*/
	
	Calibrator calibrator(1000,5);
	CpuLoop cpuLoop_A(calibrator);                                                               /*!< Defining the task for A*/
	CpuLoop cpuLoop_B(calibrator);                                                               /*!< Defining the task for B*/
	CpuLoop cpuLoop_C(calibrator);                                                               /*!< Defining the task for C*/
	
	if (isInversionSafe)
		std::cout << "\n\nStarting simulation with inversion priority control" << std::endl;
	else
		std::cout << "\n\nStarting simulation without inversion priority control" << std::endl;

	CpuMutexLoop thread_A(&cpuLoop_A, policy, priority_A, &mutex, 40, 10, 10);                   /*!< Creating the Thread A*/
	CpuMutexLoop thread_B(&cpuLoop_B, policy, priority_B, &mutex, 10, 0, 0);                     /*!< Creating the Thread B*/
	CpuMutexLoop thread_C(&cpuLoop_C, policy, priority_C, &mutex, 50, 20, 20);                   /*!< Creating the Thread C*/

	std::cout << "Starting Thread C with priority" << priority_C << std::endl;
	thread_C.start();                                                                            /*!< Starting thread C*/

	std::cout << "Waiting until t = 30 "  << std::endl;
	timespec_wait(timespec_from_ms((double) 30 / CLOCKS_PER_SEC * 1e3));                         /*!< Waiting 30 clocks to start other threads*/

	std::cout << "Starting Thread A with priority" << priority_A  << std::endl;
	std::cout << "Starting Thread B with priority" << priority_B  << std::endl;

	thread_A.start();                                                                            /*!< Starting thread A*/
	thread_B.start();                                                                            /*!< Starting thread B*/
		
	thread_A.join();                                                                             /*!< Joining thread B*/
	thread_C.join();                                                                             /*!< Joining thread B*/
	thread_B.join();                                                                             /*!< Joining thread B*/
		
	chrono.stop();

	std::cout << "The thread A took " << thread_A.execTime_ms()*CLOCKS_PER_SEC*1e-3 << " clocks of the system" << std::endl;
	std::cout << "The thread B took " << thread_B.execTime_ms()*CLOCKS_PER_SEC*1e-3 << " clocks of the system" << std::endl;
	std::cout << "The thread C took " << thread_C.execTime_ms()*CLOCKS_PER_SEC*1e-3 << " clocks of the system" << std::endl;

	std::cout << "Execution Time of all the main : " << chrono.lap() << " ms"<< std::endl;

	return 0;
}
