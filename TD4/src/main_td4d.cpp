/**
 * @file main_td4d.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Declare the main function to test the Fifo class created.
 * @date 04-2022
 */

#include <iostream>
#include <vector>

#include "Chrono/Chrono.h"
#include "FifoProducer/FifoProducer.h"
#include "FifoConsumer/FifoConsumer.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{
    if (argc != 4)
    {
    std::cout << " 'nProd' 'nCons' 'n' required" << std::endl;
    return 1;
    }

    unsigned int nProd = (unsigned int)atoi(argv[1]);
    unsigned int nCons = (unsigned int)atoi(argv[2]);
    unsigned int nItems = (unsigned int)atoi(argv[3]);

    Fifo<int> fifo;                                                                                      /*!< Declaring Fifo type int*/
    double timeProdThreads = 0;
    double timeConsThreads = 0;
    unsigned int prod = 0;
    unsigned int cons = 0;
    unsigned int sumProd = 0;
    unsigned int sumCons = 0;

    Chrono chrono;
       
    std::vector<FifoConsumer> consumer;
    std::vector<FifoProducer> producer;


    for (unsigned int i=0; i<nProd; i++)
        producer.push_back(FifoProducer(&fifo, nItems));                                               /*!< Creating the Producers*/

    for (unsigned int i=0; i<nCons-1; i++)
        consumer.push_back(FifoConsumer(&fifo, (int) nProd*nItems/nCons));                             /*!< Creating the Consumers*/
    consumer.push_back(FifoConsumer(&fifo, (nProd*nItems - (nCons-1)* ((int) nProd*nItems/nCons))));   /*!< The last one gets the rest of token to be consumed*/


    for (unsigned int i=0; i<nProd; i++)
    {
        producer[i].start();                                                                           /*!< Starting the Producers Threads*/
        std::cout << "Producer Thread " << i << " created" << std::endl;
    }

    std::cout << std::endl;
    for (unsigned int i=0; i<nCons; i++)
    {
        consumer[i].start();                                                                           /*!< Starting the Consumers Threads*/
        std::cout << "Consumer Thread " << i << " created" << std::endl;
    }

    std::cout << std::endl;
    for (unsigned int i=0; i<nProd; i++)
    {
        producer[i].join();                                                                            /*!< Joining the Producers Threads*/
        std::cout << "Producer Thread " << i << " joined with "<<  producer[i].getCount() << " items produced and a sum = "<< producer[i].getSum() << std::endl;
        prod += producer[i].getCount();
        sumProd += producer[i].getSum();
    }

    std::cout << std::endl;
    for (unsigned int i=0; i<nCons; i++)
    {
        consumer[i].join();                                                                            /*!< Joining the Consumers Threads*/
        std::cout << "Consumer Thread " << i << " joined with "<<  consumer[i].getCounter() << " items consumed and a sum = "<< consumer[i].getSum() << std::endl;
        cons += consumer[i].getCounter();
        sumCons += consumer[i].getSum();
    }

    std::cout << std::endl;
    for (unsigned int i=0; i<nProd; i++)
    {
        std::cout << "Producer thread " << i <<" execution time: " << producer[i].execTime_ms() << " ms" << std::endl;
        timeProdThreads += producer[i].execTime_ms();  
    }

    std::cout << std::endl;
    for (unsigned int i=0; i<nCons; i++)
    {
        std::cout << "Consumer thread " << i <<" execution time: " << consumer[i].execTime_ms() << " ms" << std::endl;
        timeConsThreads += consumer[i].execTime_ms();  
    }
    
    chrono.stop();

    std::cout << std::endl;
    std::cout << "Tokens produced : " << prod << std::endl;
    std::cout << "Tokens consumed : " << cons << std::endl;
    std::cout << std::endl;
    std::cout << "Sum produced : " << sumProd << std::endl;
    std::cout << "Sum consumed : " << sumCons << std::endl;  
    std::cout << std::endl;
    std::cout << "Time by producers : " << timeProdThreads << " ms" << std::endl;
    std::cout << "Time by consumers : " << timeConsThreads << " ms" << std::endl;
    std::cout << "Execution time of main : " << chrono.lap() << " ms" << std::endl;
    
    return 0;
}