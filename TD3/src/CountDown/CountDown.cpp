/**
 * @file CountDown.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in CountDown.h.
 * @date 04-2022
 */

#include "CountDown.h"
#include "../TimerLib/TimerLib.h"

#include <iostream>


CountDown::CountDown(int n)
{
    count = n;
}
	
void CountDown::callback()
{
	--count;
    std::cout << "Count = "<< count << std::endl;
	if (count == 0)
		stop();
}


int CountDown::get_count()
{
    return count;
}