#include "Time.h"
#include<iostream>
#include<ctime>
#include <chrono>
#pragma warning(disable : 4996)
void Time::copy(const Time& other)
{
	currentTime = other.currentTime;
}

void Time::erase()
{
}

Time::Time()
{
	currentTime = time(0);
}

Time::Time(const Time& other)
{
	copy(other);
}

Time& Time::operator=(const Time& other)
{
	
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Time::~Time()
{
}

void Time::setCurrentTime(time_t currentTime)
{
	this->currentTime = currentTime;
}

time_t Time::getCurrentTime() const
{
	return currentTime;
}

void Time::addMinutesToCurrentTime(size_t minutesToAdd)
{
	time_t _currentTime = time(0);
	time_t newTime = _currentTime + (60 * minutesToAdd);
	
	struct tm resultNewTime;
	memset(&resultNewTime, '\0', sizeof(struct tm));
	localtime_s(&resultNewTime, &newTime);

	std::cout << "The time after " << minutesToAdd << " minutes is : ";
	std::cout << asctime(&resultNewTime) << std::endl;
}

void Time::elapsedMinutes() const
{
	int result;
	auto now = std::chrono::system_clock::now();
	time_t startOfTheDay = std::chrono::system_clock::to_time_t(now);
	auto lt = std::localtime(&startOfTheDay);

	result = (lt->tm_hour * 60) + lt->tm_min;
	std::cout << "The elapsed minutes since the start of the day are : " << result << std::endl;
}
