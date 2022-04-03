#ifndef FifoConsumer_h_INCLUDED
#define FifoConsumer_h_INCLUDED

/**
 * @file FifoConsumer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Fifo/Fifo.hpp"
#include "../Thread/Thread.h"

/**
 * @brief Class FifoConsumer that defines threads to consume tokens
 * 
 */
class FifoConsumer : public Thread
{
private:
	Fifo<int> *fifo;
	
	unsigned int myCounter = 0;
	unsigned int mySum = 0;
	unsigned int maxCount;	

	
public:

	/**
	 * @brief Construct a new Fifo Consumer object
	 * 
	 * @param fifo 
	 * @param MaxCount 
	 */
	FifoConsumer(Fifo<int> *fifo, unsigned int MaxCount) ;

	/**
	 * @brief Destroy the Fifo Consumer object
	 * 
	 */
	~FifoConsumer();

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

	/**
	 * @brief Get the Sum 
	 * 
	 * @return unsigned int 
	 */
	unsigned int getSum();

};

#endif