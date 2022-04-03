#include "TimerLib.h"

/*Converting to ms*/
double timespec_to_ms(const timespec& time_ts)
{
    return time_ts.tv_sec*1000.0 + (time_ts.tv_nsec/1e6);
}

/*Converting to timespec*/
timespec timespec_from_ms(double time_ms)
{
    timespec time_ts;
    time_ts.tv_sec = (int) time_ms/1000.0;
    time_ts.tv_nsec = time_ms*1e6 - time_ts.tv_sec*1e9;
    return time_ts;
}

/*Getting Real time*/
timespec timespec_now()
{
    timespec timeNow;
    clock_gettime(CLOCK_REALTIME, &timeNow);
    return timeNow;
}

/*Not allowing negative nanoseconds (inverting then)*/
timespec timespec_negate(const timespec& time_ts)
{
    timespec time_tsn = time_ts;
    if (time_ts.tv_nsec < 0){
        time_tsn.tv_sec -= 1;
        time_tsn.tv_nsec += 1e9;
    }
    return time_tsn;
}

/*Adding two timespec*/
timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
   timespec time_tsAdd;

   time_tsAdd.tv_sec = timespec_negate(time1_ts).tv_sec + timespec_negate(time2_ts).tv_sec;
   time_tsAdd.tv_nsec = timespec_negate(time1_ts).tv_nsec + timespec_negate(time2_ts).tv_nsec;

   if (time_tsAdd.tv_nsec >= 1e9){
     time_tsAdd.tv_sec += 1;
     time_tsAdd.tv_nsec -= 1e9;
   }
   return timespec_negate(time_tsAdd);
}


/*Suctracting two timespec*/
timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec time_tsSub;

    if (((time1_ts.tv_sec) > (time2_ts.tv_sec)) || (((time1_ts.tv_sec) == (time2_ts.tv_sec)) && (time1_ts.tv_nsec) > (time2_ts.tv_nsec)))
    {
        time_tsSub.tv_nsec = (time1_ts.tv_nsec) - (time2_ts.tv_nsec);
        time_tsSub.tv_sec = (time1_ts.tv_sec) - (time2_ts.tv_sec);
        return timespec_negate(time_tsSub);
    }
    else
    {
        time_tsSub.tv_nsec = (time2_ts.tv_nsec) - (time1_ts.tv_nsec);
        time_tsSub.tv_sec = (time2_ts.tv_sec) - (time1_ts.tv_sec);
        time_tsSub = timespec_negate(time_tsSub);

        time_tsSub.tv_sec = -time_tsSub.tv_sec;
        time_tsSub.tv_nsec = -time_tsSub.tv_nsec;

        return time_tsSub;
    }
}

/*Wait a time*/
timespec timespec_wait(const timespec& delay_ts)
{
    timespec debut, final;
    bool status;
    clock_gettime(CLOCK_REALTIME, &debut);
    status = nanosleep(&delay_ts, NULL);
    clock_gettime(CLOCK_REALTIME, &final);
    if (status == 1)
        std::cout << "nanosleep interrupted" << std::endl;
    return timespec_subtract(final, debut);
}

/*DECLARING OPERATORS*/

/*Negative Only */
timespec  operator- (const timespec& time_ts)
{
    return timespec_negate(time_ts);
}

/*Addition (+)*/
timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_add(time1_ts, time2_ts);
}

/*Subtrating (-)*/
timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)
{
    return timespec_subtract(time1_ts, time2_ts);
}

/*Addition Assignment (+=)*/
timespec& operator+= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = time_ts + delay_ts;
    return time_ts;
}

/*Subtration Assignment (-=)*/
timespec& operator-= (timespec& time_ts, const timespec& delay_ts)
{
    time_ts = timespec_negate(time_ts - delay_ts);
    return time_ts;
}

/*Equal (==)*/
bool operator== (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec == time2_ts.tv_nsec));
}

/*Different (!=)*/
bool operator!= (const timespec& time1_ts, const timespec& time2_ts)
{
    return ((time1_ts.tv_sec != time2_ts.tv_sec) && (time1_ts.tv_nsec != time2_ts.tv_nsec));
}

/*Bigger than (>)*/
bool operator< (const timespec& time1_ts, const timespec& time2_ts)
{
    if (time1_ts.tv_sec < time2_ts.tv_sec)
        return true;
    else
        return ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec < time2_ts.tv_nsec));
}

/*Smaller than (<)*/
bool operator> (const timespec& time1_ts, const timespec& time2_ts)
{
    if (time1_ts.tv_sec > time2_ts.tv_sec)
        return true;
    else
        return ((time1_ts.tv_sec == time2_ts.tv_sec) && (time1_ts.tv_nsec > time2_ts.tv_nsec));
}