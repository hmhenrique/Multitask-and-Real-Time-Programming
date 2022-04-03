#ifndef SemProducer_h_INCLUDED
#define SemProducer_h_INCLUDED

/**
 * @file SemProducer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Mutex/Mutex.h"
#include "../Semaphore/Semaphore.h"
#include "../Thread/Thread.h"

/**
 * @brief Class that defines threads to produce tokens
 * 
 */
class SemProducer : public Thread
{
private:

	Semaphore *semaphore;
	unsigned int counter;	
	unsigned int maxCount;
		
public:

	/**
	 * @brief Construct a new Sem Producer object
	 * 
	 * @param sem 
	 * @param maxCount 
	 */
	SemProducer(Semaphore *sem, unsigned int maxCount);

	/**
	 * @brief Destroy the Sem Producer object
	 * 
	 */
	~SemProducer();

	/**
	 * @brief Handling function
	 * 
	 */
	void run();

	/**
	 * @brief Get the Counter
	 * 
	 * @return unsigned int 
	 */
	unsigned int getCounter();
};

#endif