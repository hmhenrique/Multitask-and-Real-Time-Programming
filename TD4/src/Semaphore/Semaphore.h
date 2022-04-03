#ifndef Semaphore_h_INCLUDED
#define Semaphore_h_INCLUDED

/**
 * @file Semaphore.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class Semaphore
 * @date 04-2022
 */

#include <climits>
#include "../Mutex/Mutex.h"

/**
 * @brief class that defines the methods to a Semaphore
 * 
 */
class Semaphore
{
private:
	volatile unsigned int counter; 
	unsigned int maxCount; 
	Mutex mutex; 

public:

	/**
	 * @brief Construct a new Semaphore object
	 * 
	 * @param initCount 
	 * @param maxCount 
	 */
	Semaphore(unsigned int initCount = 0, unsigned int maxCount = UINT_MAX);
	//~Semaphore();

	/**
	 * @brief Add a token
	 * 
	 */
	void give();

	/**
	 * @brief Remove an token
	 * 
	 */
	void take();

	/**
	 * @brief Remove a token with a timeout
	 * 
	 * @param timeout_ms 
	 * @return true 
	 * @return false 
	 */
	bool take(double timeout_ms);

};

#endif