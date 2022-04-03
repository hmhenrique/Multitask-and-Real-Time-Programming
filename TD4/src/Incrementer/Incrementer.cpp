/**
 * @file Incrementer.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Incrementer.h.
 * @date 04-2022
 */

#include"Incrementer.h"

#include <iostream>

Incrementer::Incrementer(Data* data) : Thread(), data(data)
{
    int schedPriority = rand()%9 + 1;       //1 -> 10 
    if(data->schedPolicy == SCHED_OTHER)
        schedPriority = 0;
    
    setScheduling(data->schedPolicy, schedPriority);
}

Incrementer::~Incrementer()
{}

void Incrementer::run()
{
    for(unsigned int i = 0; i < data->nLoops; i++)
       data->pCounter += 1.0;
}