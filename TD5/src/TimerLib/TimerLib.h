#ifndef TimerLib_h_INCLUDED
#define TimerLib_h_INCLUDED

/**
 * @file TimerLib.h
 * @author Henrique RODRIGUES (https://github.com/hmhenrique)
 * @brief Implements methods for dealing with timespec
 * @date 04-2022
 */
#include <time.h>
#include <unistd.h>
#include <iostream>

/**
 * @brief Converting timespec to ms
 * 
 * @param time_ts 
 * @return double 
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * @brief Converting ms to timespec
 * 
 * @param time_ms 
 * @return timespec 
 */
timespec timespec_from_ms(double time_ms);

/**
 * @brief Getting Real time
 * 
 * @return timespec 
 */
timespec timespec_now();

/**
 * @brief Not allowing negative nanoseconds (inverting then)
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec timespec_negate(const timespec& time_ts);

/**
 * @brief Adding two timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Suctracting two timespec
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Wait a time
 * 
 * @param delay_ts 
 * @return timespec 
 */
timespec timespec_wait(const timespec& delay_ts);

/*!< DECLARING OPERATORS */

/**
 * @brief Negative Only
 * 
 * @param time_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time_ts);

/**
 * @brief Addition (+)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Subtrating (-)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return timespec 
 */
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Addition Assignment (+=)
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Subtration Assignment (-=)
 * 
 * @param time_ts 
 * @param delay_ts 
 * @return timespec& 
 */
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

/**
 * @brief Equal (==)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Different (!=)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Bigger than (>)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

/**
 * @brief Smaller than (<)
 * 
 * @param time1_ts 
 * @param time2_ts 
 * @return true 
 * @return false 
 */
bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif