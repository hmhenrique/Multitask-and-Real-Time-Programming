#ifndef Timer_h_INCLUDED
#define Timer_h_INCLUDED

/**
 * @file Timer.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class Timer
 * @date 04-2022
 */

#include <signal.h>
#include <time.h>

/**
 * @brief Class implementing a Posix timer.
 * 
 */
class Timer
{

private:

    /**
     * @brief Call the handler function.
     * 
     * @param si 
     */
    static void call_callback(int, siginfo_t* si, void*);

public:

    /**
     * @brief Construct a new Timer object
     * 
     */
    Timer();

    /**
     * @brief Destroy the Timer object
     * 
     */
    virtual ~Timer();

    void start(double duration_ms);
    void stop();

protected: 

    timer_t tid;

    /**
     * @brief Pure virtual callback.
     * 
     */
    virtual void callback() = 0;

};

#endif