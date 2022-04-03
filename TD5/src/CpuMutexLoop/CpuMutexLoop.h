#ifndef CpuMutexLoop_h_INCLUDED
#define CpuMutexLoop_h_INCLUDED

/**
 * @file CpuMutexLoop.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class derivated from Thread
 * @date 04-2022
 */

#include "../Thread/Thread.h"
#include "../CpuLoop/CpuLoop.h"
#include "../Mutex/Mutex.h"

/**
 * @brief Class that permet to run threads CpuLoops
 * 
 */
class CpuMutexLoop : public Thread
{
    public:

    /**
     * @brief Construct a new Cpu Mutex Loop object
     * 
     * @param _loop                 Pointer to the CpuLoop object
     * @param policy                The poticy oh the thread
     * @param _priority             Priority of the thread
     * @param _mutex                Pointer to the Mutex object
     * @param _execTime             Execution time of the thread
     * @param _beginMutex           Time the thread is called
     * @param _durationMutex        Duration of the Lock
     */
    CpuMutexLoop(CpuLoop *_loop, int policy, int _priority, Mutex *_mutex, double _execTime, double _beginMutex, double _durationMutex);

    /**
     * @brief Destroy the Cpu Mutex Loop object
     * 
     */
    ~CpuMutexLoop();

    /**
     * @brief Handling function that varies when it has mutex or not 
     * 
     */
    void run();

private:
    CpuLoop *loop;            /*!< Pointer to the CpuLoop object*/
    Mutex *mutex;             /*!< Pointer to the Mutex object*/
    int priority;             /*!< Priority of the thread*/
    double execTime;          /*!< Execution time of the thread*/
    double beginMutex;        /*!< Time the thread is called*/
    double durationMutex;     /*!< Duration of the Lock*/
};

#endif