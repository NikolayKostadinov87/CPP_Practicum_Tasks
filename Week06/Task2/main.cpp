#include<iostream>
#include"Time.h"

int main() {
	Time clock;
	size_t minutesToAdd;
	std::cout << "Insert how many minutes you want to add to the current time : " << std::endl;
	std::cin >> minutesToAdd;
	//Adding minutes to the current time
	clock.addMinutesToCurrentTime(minutesToAdd);
	//Tracking the elapsed minutes since the start of the day
	clock.elapsedMinutes();
	return 0;
}
