#ifndef PosixThread_h_INCLUDED
#define PosixThread_h_INCLUDED

/**
 * @file PosixThread.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define Thread Posix class
 * @date 04-2022
 */

#include <pthread.h>
#include <exception>

/**
 * @brief Class PosixThread implementign the basics functions of a Thread Posix
 * 
 */
class PosixThread
{

public:

    using Func = void* (*) (void*);      /*!< Defining enumerator */

    /**
     * @brief Class for exception treatment.
     * 
     */
    class Exception : std::exception
	{
	public:		
        const char* what() const noexcept;
	};

private:
    pthread_t posixId;
    pthread_attr_t posixAttr;

protected:
    bool isActive;

public:
    /**
     * @brief Construct a new Posix Thread object
     * 
     */
    PosixThread();

    /**
     * @brief Construct a new Posix Thread object already identified
     * 
     * @param posixId 
     */
    PosixThread(pthread_t posixId);

    /**
     * @brief Destroy the Posix Thread object
     * 
     */
    ~PosixThread();
    
    /**
     * @brief Start the thread
     * 
     * @param Func 
     * @param threadArg 
     */
    void start(Func, void* threadArg);

    /**
     * @brief Terminate the thread
     * 
     */
    void join();

    /**
     * @brief Set the scheduling of the thread
     * 
     * @param schedPolicy 
     * @param priority 
     * @return true 
     * @return false 
     */
    bool setScheduling(int schedPolicy, int priority);

    /**
     * @brief Get the scheduling of the thread
     * 
     * @param p_schedPolicy 
     * @param p_priority 
     * @return true 
     * @return false 
     */
    bool getScheduling(int* p_schedPolicy = nullptr, int* p_priority = nullptr);
};

#endif