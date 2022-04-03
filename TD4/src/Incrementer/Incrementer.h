#ifndef Incrementer_h_INCLUDED
#define Incrementer_h_INCLUDED

/**
 * @file Incrementer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread.
 * @date 04-2022
 */

#include "../Thread/Thread.h"

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
 * @brief Class that increments a counter value.
 * 
 */
class Incrementer : public Thread
{

public:

    /**
     * @brief Construct a new Incrementer object
     * 
     * @param data 
     */
    Incrementer(Data* data);

    /**
     * @brief Destroy the Incrementer object
     * 
     */
    ~Incrementer();

    /**
     * @brief Handling function
     * 
     */
    void run();

    Data* data;


};

#endif