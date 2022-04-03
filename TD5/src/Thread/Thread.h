#ifndef Thread_h_INCLUDED
#define Thread_h_INCLUDED

/**
 * @file Thread.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from PosixThread.
 * @date 04-2022
 */

#include "../PosixThread/PosixThread.h"

/**
 * @brief Class to define a thread as an object.
 * 
 */
class Thread : public PosixThread
{
public:

    /**
     * @brief Get the start time of the thread 
     * 
     * @return double 
     */
    double startTime_ms();

    /**
     * @brief Get the stop time of the thread 
     * 
     * @return double 
     */
    double stopTime_ms();

    /**
     * @brief Get the execution time of the thread
     * 
     * @return double 
     */
    double execTime_ms();

protected:

    /**
     * @brief pure virtual function that implemented in derivated classes
     * 
     */
    virtual void run() = 0;

private:

    /**
     * @brief Caller for the virtual function.
     * 
     * @param v_thread 
     * @return void* 
     */
    static void* call_run(void* v_thread);

    timespec startTime;
	timespec stopTime;
    bool started = false;

public:

    /**
     * @brief Construct a new Thread object
     * 
     */
    Thread();

    /**
     * @brief Destroy the Thread object
     * 
     */
    ~Thread();

    /**
     * @brief Start the Thread
     * 
     * @return true 
     * @return false 
     */
    bool start();

    /**
     * @brief Set the thread to sleep for a given duration
     * 
     * @param delay_ms 
     */
    static void sleep_ms(double delay_ms);
};

#endif