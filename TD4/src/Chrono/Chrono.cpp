/**
 * @file Chrono.cpp
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements the methods declared in Chrono.h.
 * @date 04-2022
 */

#include "Chrono.h"

/*Constructor with the actual time*/
Chrono::Chrono()
{
	startTime_ = timespec_now();
    stopTime_ = startTime_ - startTime_;
}

/*Restart the startTime_*/
void Chrono::restart()
{
    startTime_ = timespec_now();
    stopTime_ = startTime_;
}

/*Set the stopTime_ as the actual time*/
void Chrono::stop()
{
    stopTime_ = timespec_now();
}

/*Check if the chronometre is active or not*/
bool Chrono::isActive()
{
    return (stopTime_ == startTime_);
}

/*Return the value of startTime_*/
double Chrono::startTime()
{
    return timespec_to_ms(startTime_);
}

/*Return the value of stopTime_*/
double Chrono::stopTime()
{
    return timespec_to_ms(stopTime_);
}

/*Current time after a start if called betwwen a start and a stop*/
/*Time in miliseconds betwwen the start and the stop stop*/
double Chrono::lap()
{
    if (!isActive()) 
		return timespec_to_ms(stopTime_ - startTime_);
    else 
		return timespec_to_ms(timespec_now() - startTime_);
}