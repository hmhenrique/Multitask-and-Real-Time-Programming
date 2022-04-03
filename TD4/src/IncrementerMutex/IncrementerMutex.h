#ifndef IncrementerMutex_h_INCLUDED
#define IncrementerMutex_h_INCLUDED

/**
 * @file IncrementerMutex.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Thread/Thread.h"
#include "../Mutex/Mutex.h"

/**
 * @brief Struct with the thrads arguments
 * 
 */
struct Data
{
    unsigned int nLoops;
    volatile double pCounter;
    int schedPolicy;
};

/**
 * @brief Class that increments a counter value. Now using Mutex.
 * 
 */
class IncrementerMutex : public Thread
{

public:

    /**
     * @brief Construct a new Incrementer Mutex object
     * 
     * @param data 
     * @param mutex 
     */
    IncrementerMutex(Data* data, Mutex &mutex);

    /**
     * @brief Destroy the Incrementer Mutex object
     * 
     */
    ~IncrementerMutex();

protected:

    /**
     * @brief Handling function
     * 
     */
    void run();

private:
    Data* data_;
    Mutex &mutex_; 

};

#endif