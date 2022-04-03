#ifndef Mutex_h_INCLUDED
#define Mutex_h_INCLUDED

/**
 * @file Mutex.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define the Mutex class
 * @date 04-2022
 */

#include <exception>
#include <pthread.h>

/**
 * @brief Mutex class that encapsulates the functionalities of a Mutex Posix
 * 
 */
class Mutex
{

public:

    /**
     * @brief Class that locks a Mutex.
     * 
     */
    class Lock;

    /**
     * @brief Class that tries to lock a Mutex
     * 
     */
    class TryLock;

    /**
     * @brief Class for the Mutex monitoring.
     * 
     */
    class Monitor;

private:
    pthread_mutex_t posixId;
    pthread_cond_t posixCondId;


public:

    /**
     * @brief Construct a new Mutex object
     * 
     * @param isInversionSafe 
     */
    Mutex(bool isInversionSafe);

    /**
     * @brief Destroy the Mutex object
     * 
     */
    ~Mutex();

private:

    /**
     * @brief Lock the mutex
     * 
     */
    void lock();

    /**
     * @brief Lock with a timeout
     * 
     * @param timeout_ms 
     * @return true 
     * @return false 
     */
    bool lock(double timeout_ms);

    /**
     * @brief Try to lock the mutex
     * 
     * @return true 
     * @return false 
     */
    bool trylock();

    /**
     * @brief Unlock the mutex
     * 
     */
    void unlock();    
};

/**
 * @brief Class for the Mutex monitoring.
 * 
 */
class Mutex::Monitor
{

public:

    /**
     * @brief Class for exception treatment.
     * 
     */
    class TimeoutException: std::exception
    {
        public:
            const char *error();
    };

protected:
    Mutex& m;
    
    /**
     * @brief Construct a new Monitor object
     * 
     * @param m 
     */
    Monitor(Mutex& m);

public:
    /**
     * @brief Wait for the posix condition of the mutex.
     * 
     */
    void wait();

    /**
     * @brief Wait for the posix condition of the mutex with a timeout.
     * 
     * @param timeout_ms 
     * @return true 
     * @return false 
     */
    bool wait(double timeout_ms);

    /**
     * @brief Unlock a thread in a waiting condition.
     * 
     */
    void notify();

    /**
     * @brief Unlock all the threads  in a waiting condition.
     * 
     */
    void notifyAll();

};


/**
 * @brief Class that locks a Mutex.
 * 
 */
class Mutex::Lock : public Mutex::Monitor
{

public:
    /**
     * @brief Construct a new Lock object
     * 
     * @param m 
     */
    Lock(Mutex& m);

    /**
     * @brief Construct a new Lock object
     * 
     * @param m 
     * @param timeout_ms 
     */
    Lock(Mutex& m, double timeout_ms);

    /**
     * @brief Destroy the Lock object
     * 
     */
    ~Lock();
};

/**
 * @brief Class that tries to lock a Mutex
 * 
 */
class Mutex::TryLock : public Mutex::Monitor
{

public:
    /**
     * @brief Construct a new Try Lock object
     * 
     * @param m 
     */
    TryLock(Mutex& m);

    /**
     * @brief Destroy the Try Lock object
     * 
     */
    ~TryLock();
};


#endif