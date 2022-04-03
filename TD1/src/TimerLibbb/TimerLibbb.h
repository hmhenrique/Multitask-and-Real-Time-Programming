#ifndef TimeLib_h_INCLUDED
#define TimeLib_h_INCLUDED

#include <time.h>
#include <iostream>

/**
 * @brief Converting to ms
 * 
 * @param time_ts 
 * @return double 
 */
double timespec_to_ms(const timespec& time_ts);

/**
 * @brief Converting to timespec
 * 
 * @param time_ms 
 * @return timespec 
 */
timespec timespec_from_ms(double time_ms);

/*Getting Real time*/
timespec timespec_now();

/*Not allowing negative nanoseconds (inverting then)*/
timespec timespec_negate(const timespec& time_ts);

/*Adding two timespec*/
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts);

/*Suctracting two timespec*/
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts);

/*Wait a time*/
timespec timespec_wait(const timespec& delay_ts);

/*DECLARING OPERATORS*/

/*Negative Only */
timespec  operator- (const timespec& time_ts);

/*Addition (+)*/
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts);

/*Subtrating (-)*/
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts);

/*Addition Assignment (+=)*/
timespec& operator+= (timespec& time_ts, const timespec& delay_ts);

/*Subtration Assignment (-=)*/
timespec& operator-= (timespec& time_ts, const timespec& delay_ts);

/*Equal (==)*/
bool operator== (const timespec& time1_ts, const timespec& time2_ts);

/*Different (!=)*/
bool operator!= (const timespec& time1_ts, const timespec& time2_ts);

/*Bigger than (>)*/
bool operator< (const timespec& time1_ts, const timespec& time2_ts);

bool operator> (const timespec& time1_ts, const timespec& time2_ts);

#endif