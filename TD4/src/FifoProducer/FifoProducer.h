#ifndef FifoProducer_h_INCLUDED
#define FifoProducer_h_INCLUDED

/**
 * @file FifoProducer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Fifo/Fifo.hpp"
#include "../Thread/Thread.h"

/**
 * @brief Class FifoProduce that defines threads to produce tokens of type T
 * 
 */
class FifoProducer : public Thread
{
private:
	Fifo<int> *fifo;

	unsigned int count = 0;
	unsigned int sum = 0;
	unsigned int maxCount;

		
public:

	/**
	 * @brief Construct a new Fifo Producer object
	 * 
	 * @param fif 
	 * @param maxNum 
	 */
	FifoProducer(Fifo<int> *fif, unsigned maxNum);

	/**
	 * @brief Destroy the Fifo Producer object
	 * 
	 */
	~FifoProducer();

	/**
	 * @brief Handling function
	 * 
	 */
	void run();

	/**
	 * @brief Get the Count 
	 * 
	 * @return int unsigned 
	 */
	int unsigned getCount();

	/**
	 * @brief Get the Sum 
	 * 
	 * @return int unsigned 
	 */
	int unsigned getSum();
};

#endif

