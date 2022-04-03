/**
 * @file main_td1a.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Tests functions created in the TimerLib.h
 * @date 04-2022
 */
#include "TimerLib/TimerLib.h"

/**
 * @brief Tests functions created in the TimerLib to deal with the timespecs
 * 
 * @return int 
 */
int main()
{
    /*!< Defining  a timespec*/
    const timespec myTimeTest = {10, 440000534};
    const timespec myTimeTest2 = {9, 340000534};

    /*!< Showing the timespec created */
    std::cout<< "My time : " << myTimeTest.tv_sec << " seconds and " << (double)myTimeTest.tv_nsec << " nanoseconds" << std::endl;
    
    /*!< Showing the timespec created */
    std::cout<< "My time 2: " << myTimeTest2.tv_sec << " seconds and " << (double)myTimeTest2.tv_nsec << " nanoseconds" << std::endl;

    /*!< Converting to ms */
    std::cout<< "My time in miliseconds :" << (double)timespec_to_ms(myTimeTest) << std::endl;

    /*!< Converting to timespec */
    std::cout<< "Returning My time from miliseconds to timespec : " << timespec_from_ms(timespec_to_ms(myTimeTest)).tv_sec << " seconds and " << (double)timespec_from_ms(timespec_to_ms(myTimeTest)).tv_nsec << " nanoseconds." << std::endl;

    /*!< Getting Real time */
    std::cout << "Real time : " << timespec_now().tv_sec << " seconds and " << timespec_now().tv_nsec << " nanoseconds." << std::endl;

    /*!< Negate the timer */
    std::cout << "My time 2 neagated : " << timespec_negate(myTimeTest2).tv_sec << " seconds and " << timespec_negate(myTimeTest2).tv_nsec << " nanoseconds."<< std::endl;

    /*!< Adding two timers */
    std::cout << "Two Times add : " << timespec_add(myTimeTest, myTimeTest2).tv_sec << " seconds and " << timespec_add(myTimeTest, myTimeTest2).tv_nsec << " nanoseconds." << std::endl;

    /*!< Subtracting two timers */
    std::cout << "Two Times Subtracted : " << timespec_subtract(myTimeTest, myTimeTest2).tv_sec << " seconds and " << timespec_subtract(myTimeTest, myTimeTest2).tv_nsec << " nanoseconds." << std::endl;

    /*!< Wait a time */
    std::cout<< "Waiting 5 seconds and 500.000.000 nanoseconds ..." <<std::endl;
    const timespec myTimeDelay = {5, 500000000};
    std::cout << "Waited time : " << timespec_wait(myTimeDelay).tv_sec << " seconds and " << timespec_wait(myTimeDelay).tv_nsec << " nanoseconds." << std::endl;

    /*!< TESTING OPERATORS */
    std::cout << "Negative Only : " << (-myTimeTest2).tv_sec << " seconds and " << (-myTimeTest2).tv_nsec << " nanoseconds."<< std::endl;
    std::cout << "Addition (+) : " << (myTimeTest + myTimeTest2).tv_sec << " seconds and " << (myTimeTest + myTimeTest2).tv_nsec << " nanoseconds." << std::endl;
    std::cout << "Subtrating (-) : " << (myTimeTest - myTimeTest2).tv_sec << " seconds and " << (myTimeTest - myTimeTest2).tv_nsec << " nanoseconds." << std::endl;
    
    timespec myTimeTest3 = myTimeTest;
    myTimeTest3 += myTimeDelay;
    std::cout << "Addition Assignment (+=) : " << myTimeTest3.tv_sec << " seconds and " << myTimeTest3.tv_nsec << " nanoseconds." << std::endl;
    
    myTimeTest3 -= myTimeDelay;
    std::cout << "Subtration Assignment (-=) : " << myTimeTest3.tv_sec << " seconds and " << myTimeTest3.tv_nsec << " nanoseconds." << std::endl;

    const timespec myTimeTest4 = myTimeTest3;
    std::cout << "Equal (==) : " << (myTimeTest == myTimeTest4) << std::endl;
    std::cout << "Different (!=) : " << (myTimeTest != myTimeTest4) << std::endl;
    std::cout << "Bigger than (>) : " << (myTimeTest > myTimeTest2) << std::endl;
    std::cout << "Smaller than (<) : " << (myTimeTest < myTimeTest2) << std::endl;


    return 0;
}