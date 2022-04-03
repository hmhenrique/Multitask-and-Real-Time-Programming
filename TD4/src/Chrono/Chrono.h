#ifndef Chrono_h_INCLUDED
#define Chrono_h_INCLUDED

/**
 * @file Chrono.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Define a class Chrono that uses the TimeLib
 * @date 04-2022
 */

#include "../TimerLib/TimerLib.h"

/**
 * @brief Class Chrono tha uses the TimeLib
 * 
 */
class Chrono
{
private:

	timespec startTime_;
	timespec stopTime_;

public:

	/**
	 * @brief Construct a new Chrono object
	 * 
	 */
	Chrono();
	
	void stop();	
	void restart();
	bool isActive();	
	double startTime();
	double stopTime();
	double lap();

};

#endif