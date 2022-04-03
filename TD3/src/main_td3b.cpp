/**
 * @file main_td3b.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the tests for the CountDown class.
 * @date 04-2022
 */

#include "CountDown/CountDown.h"
#include <iostream>

/**
 * @brief The main function that realises the countdown of a counter.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[])
{

    if(argc != 2)
    {
        std::cout << "Value 'nLoops' required." << std::endl;
        return 1;
    }

    int nLoops = atoi(argv[1]);

    CountDown countDown(nLoops);
    countDown.start(1000);

    while(countDown.get_count() != 0){}

    return 0;
}
