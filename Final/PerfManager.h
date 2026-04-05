#pragma once

#include <string>
#include <iostream>
#include <chrono>

class PerfManager {
private:
	std::chrono::steady_clock::time_point _StartTime;
	std::chrono::steady_clock::time_point _EndTime;
public:
	PerfManager();
	void SetStartTime();
	void SetEndTime();
	std::string getMicroseconds();
	std::string getMilliseconds();
	std::string getSeconds();
	std::string getNanoSeconds();
};
