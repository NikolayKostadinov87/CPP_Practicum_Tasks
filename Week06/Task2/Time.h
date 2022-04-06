#pragma once
#include<time.h>
class Time {
private:
	time_t currentTime = time(0);
	void copy(const Time&);
	void erase();
public:
	//Canonisation
	Time();
	Time(const Time& other);
	Time& operator=(const Time& other);
	~Time();

	//Setter for the current time
	void setCurrentTime(time_t currentTime);

	//Getter for the current time
	time_t getCurrentTime() const;

	//Adding minutes to current time
	void addMinutesToCurrentTime(size_t minutesToAdd);

	//Tracking the elapsed minutes since the start of the day
	void elapsedMinutes() const;
};
