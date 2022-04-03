/**
 * @file main_td3a.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Tests the class Chrono created.
 * @date 04-2022
 */

#include <iostream>
#include "Chrono/Chrono.h"

/**
 * @brief The function main.
 * 
 * @return int 
 */
int main()
{
    Chrono chrono;

    chrono.restart();
    std::cout << "Waiting 5 seconds" << std::endl;
	timespec_wait(timespec_from_ms(5000));

	std::cout << "Time after 5 seconds: " << chrono.lap()/1000 << std::endl;
	chrono.stop();
	std::cout << "Time stopped" << std::endl;
    std::cout << "Stop Time minus Start Time after 5 seconds: " << (chrono.stopTime() - chrono.startTime())/1000 << std::endl;

    std::cout << "Waiting 1 seconds" << std::endl;
	timespec_wait(timespec_from_ms(1000));

	std::cout << "Time after 1 second stopped: " << chrono.lap()/1000 << std::endl;
	chrono.restart();

	std::cout << "Time restarted" << std::endl;
    std::cout << "Stop Time minus Start Time after restart: " <<  (chrono.stopTime() - chrono.startTime())/1000 << std::endl;

    std::cout << "Waiting 3 seconds" << std::endl;
	timespec_wait(timespec_from_ms(3000));
  
	std::cout << "Time after 3 seconds: " << chrono.lap()/1000 << std::endl; 
return 0;
}