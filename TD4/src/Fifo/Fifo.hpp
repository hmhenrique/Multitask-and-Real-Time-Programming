#ifndef Fifo_hpp_INCLUDED
#define Fifo_hpp_INCLUDED

/**
 * @file Fifo.hpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Defines the Fifo class Template
 * @date 04-2022
 */

#include <iostream>
#include <queue>

#include "../Mutex/Mutex.h"

/**
 * @brief Defines a template class to realise a Fifo.
 * 
 * @tparam T 
 */
template <typename T>
class Fifo
{

public:
    /**
     * @brief Exception if the Fifo is empty
     * 
     */
    class EmptyException: std::exception
    {
        public:
            const char *error() const noexcept;
    };

public:
    /**
     * @brief Construct a new Fifo object
     * 
     */
    Fifo();

    /**
     * @brief Destroy the Fifo object
     * 
     */
    ~Fifo();

    /**
     * @brief Add an element at the end of queue
     * 
     * @param element 
     */
    void push(T element);

    /**
     * @brief Remove the element at the top of the queue
     * 
     * @return T 
     */
    T pop();

    /**
     * @brief Remove the element at the top of the queue
     * 
     * @param timeout_ms 
     * @return T 
     */
    T pop(double timeout_ms);

private:
    Mutex mutex; 
    std::queue<T> elements;
};

template<typename T>
Fifo<T>::Fifo()
{
    mutex = Mutex();
}

template <class T>
Fifo<T>::~Fifo(){}


template<typename T>
void Fifo<T>::push(T element)
{
    Mutex::Lock lock(mutex);
    elements.push(element);
    lock.notify();
}

template<typename T>
T Fifo<T>::pop()
{
    Mutex::Lock lock(mutex);
    while(elements.empty())
        lock.wait();

    T element = elements.front();
    elements.pop();
    lock.notify();

    return element;
}

template<typename T>
T Fifo<T>::pop(double timeout_ms)
{
    Mutex::Lock lock(mutex);
    while(elements.empty())
        if(!lock.wait(timeout_ms))
            throw Fifo<T>::EmptyException();

    T element = elements.front();
    elements.pop();
    lock.notify();
    
    return element;
}

#endif