#ifndef SemConsumer_h_INCLUDED
#define SemConsumer_h_INCLUDED

/**
 * @file SemConsumer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Semaphore/Semaphore.h"
#include "../Thread/Thread.h"

/**
 * @brief Class that defines threads to consume tokens
 * 
 */
class SemConsumer : public Thread
{
private:

	Semaphore *semaphore;
	unsigned int mycounter = 0;
	unsigned int maxCount;	

	
public:
	/**
	 * @brief Construct a new Sem Consumer object
	 * 
	 * @param sem 
	 * @param maxCount 
	 */
	SemConsumer(Semaphore *sem, unsigned int maxCount);
	/**
	 * @brief Destroy the Sem Consumer object
	 * 
	 */
	~SemConsumer();

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