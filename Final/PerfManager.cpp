#include "PerfManager.h"
using namespace std;

PerfManager::PerfManager()
{
	this->_StartTime = chrono::steady_clock::now();
	this->_EndTime = chrono::steady_clock::now();
}

void PerfManager::SetStartTime()
{
	this->_StartTime = chrono::steady_clock::now();
}

void PerfManager::SetEndTime()
{
	this->_EndTime = chrono::steady_clock::now();
}



std::string PerfManager::getMicroseconds()
{
	return to_string(chrono::duration_cast<chrono::microseconds>(this->_EndTime - this->_StartTime).count());
}
std::string PerfManager::getMilliseconds()

{
	return to_string(chrono::duration_cast<chrono::milliseconds>(this->_EndTime - this->_StartTime).count());
}

std::string PerfManager::getSeconds()
{
	return to_string(chrono::duration_cast<chrono::seconds>(this->_EndTime - this->_StartTime).count());
}
std::string PerfManager::getNanoSeconds()

{
	return to_string(chrono::duration_cast<chrono::nanoseconds>(this->_EndTime - this->_StartTime).count());
}
